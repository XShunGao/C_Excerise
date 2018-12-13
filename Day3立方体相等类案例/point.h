#pragma once
class point
{
public:
	point();
	~point();

public:
	void setPoint(int x, int y)
	{
		m_X = x;
		m_Y = y;
	}

	point getPoint(point p)
	{
		m_X = p.m_X;
		m_Y = p.m_Y;
		return *this;
	}

	int getX() const
	{
		return m_X;
	}

	int getY() const
	{
		return m_Y;
	}

private:
	int m_X = 0;
	int m_Y = 0;
};

