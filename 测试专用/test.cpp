#include <iostream>

using namespace std;

int main()
{
	char a;
	unsigned int a_num = 0, e_num = 0, i_num = 0,
		o_num = 0, u_num = 0, other_num = 0, space_num = 0,
		tab_num = 0, enter_num = 0;
	while (cin>> noskipws >> a)
	{
		switch (a)
		{
			case 'a': ++a_num; break;
			case 'e': ++e_num; break;
			case 'i': ++i_num; break;
			case 'o': ++o_num; break;
			case 'u': ++u_num; break;
			case '\ ': ++space_num; break;
			case '\t': ++tab_num; break;
			case '\n': ++enter_num; break;
			default : ++other_num; break;
		}
	}


	return 0;
}