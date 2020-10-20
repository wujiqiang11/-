#include<iostream>
using namespace std;
void OBST(double* a, double* b, int n, double** m, int** s, double** w)
{
	for (int i = 0; i <= n; i++)
	{
		w[i + 1][i] = a[i];
		m[i + 1][i] = 0;
	}
	
	for(int  r=0;r<n;r++)
		for (int i = 1; i <= n - r; i++)
		{
			int j = i + r;
			w[i][j] = w[i][j - 1] + a[j-1] + b[j-1];
			m[i][j] = m[i + 1][j];
			
			s[i][j] = i;
			for (int k = i + 1; k <= j; k++)
			{
				double t = m[i][k - 1] + m[k + 1][j];
				if (t < m[i][j])
				{
					m[i][j] = t;
					s[i][j] = k;
				}
			}
			//printf("i: %d, j: %d, w[i][j]: %f, m[9][9]:%f\n", i, j, w[i][j], m[9][9]);
			
			m[i][j] += w[i][j];
		}
	return;
}
int main()
{
	double a[10] = {0.1, 0.04, 0.04, 0.04, 0.04, 0.04, 0.04, 0.04, 0.04, 0.04};
	double  b[9] = {0.06, 0.06, 0.06, 0.06, 0.06, 0.06, 0.06, 0.06, 0.06};
	int nn = 11;
	double** m = new double* [nn];
	int** s = new int* [nn];
	double** w = new double* [nn];
	for (int i = 0; i <= nn-1; i++)
	{
		m[i] = new double[nn];
		s[i] = new int[nn];
		w[i] = new double[nn];
	}
	for (int i = 0; i < nn; i++)
	{
		for (int j = 0; j < nn; j++)
		{
			m[i][j]=0;
			w[i][j] = 0;
			s[i][j] = 00;
		}
	}
	
	OBST(a, b, 9, m, s, w);
	printf("s:\n");
	for (int i = 0; i < nn-1; i++)
	{
		for (int j = 0; j <nn; j++)
		{
			cout <<s[i][j] << " ";
		}
		cout << endl;
	}
	printf("w:\n");
	for (int i = 0; i < nn-1; i++)
	{
		for (int j = 0; j < nn; j++)
		{
			cout << s[i][j] << " ";
		}
		cout << endl;
	}
	printf("m:\n");
	for (int i = 0; i < nn-1; i++)
	{
		for (int j = 0; j < nn; j++)
		{
			cout << s[i][j] << " ";
		}
		cout << endl;
	}
	printf("该数组的最优二叉搜索树的平均查找步长为: %f\n", m[1][9]);
	for (int i = 0; i <= 10; i++)
	{
		delete [] m[i];
		delete [] s[i];
		delete [] w[i];
	}
	return 0;
}
