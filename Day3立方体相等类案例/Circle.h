#pragma once
#include <iostream>
#include "point.h"

class Circle : point
{
public:
	Circle() = default;
	~Circle() = default;
	void setCenter(point p)
	{
		m_center = p;
	}

	void setR(int r)
	{
		m_R = r;
	}

	int getR() const
	{
		return m_R;
	}

	point getCenter() const
	{
		return m_center;
	}


private:
	int m_R = 0;
	point m_center;

};