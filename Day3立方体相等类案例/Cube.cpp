#include "Cube.h"

using namespace std;

Cube::Cube()
{
}

Cube::~Cube()
{
}
//��ĳ�Ա����
bool Cube::is_equalClass(Cube &c2)
{
	return (m_L == c2.getL() && m_W == c2.getW() && m_H == c2.getH());
}

//ȫ�ֺ����ж��Ƿ����
bool is_equal(const Cube &c1, const Cube &c2)
{
	if (c1.getL() == c2.getL() && c1.getW() == c2.getW() && c1.getH() == c2.getH())
	{
		return true;
	}
	else
	{
		return false;
	}
}

