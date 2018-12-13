#include <iostream>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;

void TwoPass(const Mat &srcImg, Mat &mapImg)
{
	int cols = srcImg.cols;
	int rows = srcImg.rows;
	int label = 1;
	int labelset[100] = { 0 };
	//第一次扫描
	for (int i = 1; i < cols - 1; ++i)
	{
		for (int j = 1; j < rows - 1; ++j)
		{
			int value = srcImg.at<unsigned char>(i, j);
			if (value == 0)
			{
				int leftlabel = mapImg.at<unsigned char>(i, j - 1);
				int uplabel = mapImg.at<unsigned char>(i - 1, j);
				//如果当前像素值 为1 看左，上有没有label > 1
				// 1.都不大于1，新建label  2.全部大于1，取最小的赋给当前值 3.一大一小 把大的赋值给当前
				if ((leftlabel < 2) && (uplabel < 2))
				{
					mapImg.at<unsigned char>(i, j) = ++label;  //从2开始计数label
					labelset[label] = label;  //存储label的数量
				}
				else if ((leftlabel > 1) && (uplabel > 1))
				{
					if (leftlabel > uplabel)
					{
						mapImg.at<unsigned char>(i, j) = uplabel;
						labelset[leftlabel] = uplabel;  //记录lebel等价关系
					}
					else
					{
						mapImg.at<unsigned char>(i, j) = leftlabel;
						labelset[uplabel] = leftlabel;  //记录lebel等价关系
					}
				}
				else
				{ //3.一大一小 把大的赋值给当前
					if (leftlabel > uplabel)
					{
						mapImg.at<unsigned char>(i, j) = leftlabel;
						//labelset[leftlabel] = uplabel;  //记录lebel等价关系
					}
					else
					{
						mapImg.at<unsigned char>(i, j) = uplabel;
					}
				}
			}
		}
	}
		//同步labelset中的label等价关系
		for (int i = 2; i < 100; ++i)
		{
			int templabel = labelset[i];
			if (templabel < 2)
			{   //label从2开始 所以如果labelset里的值小于2 跳过此次循环；
				continue;
			}
			else 
			{	//label >= 2时，检查label在labelset里对应的值，直到label == labelset[label]
				while (templabel != labelset[templabel])
				{
					labelset[i] = labelset[templabel];
					templabel = labelset[i];
				}
			}
		}
	
	//two-pass
	for (int i = 1; i < rows - 1; ++i)
	{
		for (int j = 1; j < cols - 1; ++j)
		{
			int templabel = mapImg.at<unsigned char>(i, j);
			if (templabel > 1)
			{
				mapImg.at<unsigned char>(i, j) = labelset[templabel];
			}
		}
	}
}

int main()
{
	Mat srcImg = imread("1.jpg");
	if (srcImg.type() != CV_8UC1)
	{
		cvtColor(srcImg, srcImg, CV_RGB2GRAY);
	}
	Mat mapImg(srcImg.size(), CV_8UC1, Scalar(0));
	
	//扩展图像
	TwoPass(srcImg, mapImg);

	imshow("mapImg", mapImg);

	system("pause");
	return 0;
}