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
	//��һ��ɨ��
	for (int i = 1; i < cols - 1; ++i)
	{
		for (int j = 1; j < rows - 1; ++j)
		{
			int value = srcImg.at<unsigned char>(i, j);
			if (value == 0)
			{
				int leftlabel = mapImg.at<unsigned char>(i, j - 1);
				int uplabel = mapImg.at<unsigned char>(i - 1, j);
				//�����ǰ����ֵ Ϊ1 ��������û��label > 1
				// 1.��������1���½�label  2.ȫ������1��ȡ��С�ĸ�����ǰֵ 3.һ��һС �Ѵ�ĸ�ֵ����ǰ
				if ((leftlabel < 2) && (uplabel < 2))
				{
					mapImg.at<unsigned char>(i, j) = ++label;  //��2��ʼ����label
					labelset[label] = label;  //�洢label������
				}
				else if ((leftlabel > 1) && (uplabel > 1))
				{
					if (leftlabel > uplabel)
					{
						mapImg.at<unsigned char>(i, j) = uplabel;
						labelset[leftlabel] = uplabel;  //��¼lebel�ȼ۹�ϵ
					}
					else
					{
						mapImg.at<unsigned char>(i, j) = leftlabel;
						labelset[uplabel] = leftlabel;  //��¼lebel�ȼ۹�ϵ
					}
				}
				else
				{ //3.һ��һС �Ѵ�ĸ�ֵ����ǰ
					if (leftlabel > uplabel)
					{
						mapImg.at<unsigned char>(i, j) = leftlabel;
						//labelset[leftlabel] = uplabel;  //��¼lebel�ȼ۹�ϵ
					}
					else
					{
						mapImg.at<unsigned char>(i, j) = uplabel;
					}
				}
			}
		}
	}
		//ͬ��labelset�е�label�ȼ۹�ϵ
		for (int i = 2; i < 100; ++i)
		{
			int templabel = labelset[i];
			if (templabel < 2)
			{   //label��2��ʼ �������labelset���ֵС��2 �����˴�ѭ����
				continue;
			}
			else 
			{	//label >= 2ʱ�����label��labelset���Ӧ��ֵ��ֱ��label == labelset[label]
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
	
	//��չͼ��
	TwoPass(srcImg, mapImg);

	imshow("mapImg", mapImg);

	system("pause");
	return 0;
}