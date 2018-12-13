#pragma once

#include<iostream>

//const int N = 16;
#define N 16
int t = 1;

class Chess
{
public:
	int size;
	Chess::Chess(int (*a)[N], int dr, int dc, int tr,
		         int tc, int size);
	Chess::~Chess();

private:
	int board[20][20];
	int s_size = 0;
	
protected:


};
