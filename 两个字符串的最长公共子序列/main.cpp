//��������ַ����Ĺ���������
//Ҫ��1����ʹ�ø�������
//Ҫ��2:��ʹ��m*n���飬ʹ��2*n����
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