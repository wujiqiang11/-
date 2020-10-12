//输出两个字符串的公共子序列
//要求1：不使用辅助数组
//要求2:不使用m*n数组，使用2*n数组
#include<iostream>
using namespace std;

void LCSLength(int m, int n, char* x, char* y, int** c, int** b)
{
	int i, j;
	for (int i = 0; i <= m; i++)
		c[i][0] = 0;
	for (int i = 1; i <= n; i++)
		c[0][i] = 0;
	for (i = 1; i <= m; i++)
	{
		for (j = 1; j <= n; j++)
		{
			if (x[i] == y[j])
			{
				c[i][j] = c[i - 1][j - 1] + 1;
				b[i][j] = 1;
			}
			else if (c[i - 1][j] >= c[i][j - 1])
			{
				c[i][j] = c[i - 1][j - 1];
				b[i][j] = 2;
			}
			els
		}
	}
}