#pragma once
#include <iostream>


class Cube
{
public:
	Cube();
	~Cube();

	//��Ա����
public:
	//���ó���ߣ���ȡ�����
	void setL(int L)
	{
		m_L = L;
	}
	int getL() const
	{
		return m_L;
	}

	void setW(int W)
	{
		m_W = W;
	}
	int getW() const
	{
		return m_W;
	}

	void setH(int H)
	{
		m_H = H;
	}
	int getH() const
	{
		return m_H;
	}

	int calcuateV()
	{
		return m_H*m_L*m_W;
	}

	bool is_equalClass(Cube &c);

	//��Ա����
private:
	int m_L;
	int m_W;
	int m_H;

};