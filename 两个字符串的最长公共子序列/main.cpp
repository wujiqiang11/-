//��������ַ����Ĺ���������
//Ҫ��1����ʹ�ø�������
//Ҫ��2:��ʹ��m*n���飬ʹ��2*n����
#include<iostream>
using namespace std;

void LCSLength(int m, int n, char* x, char* y, int** c, int** b)  //��̬�滮����������Ӵ�����
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
			if (x[i-1] == y[j-1])
			{
				c[i][j] = c[i - 1][j - 1] + 1;
				b[i][j] = 1;
			}
			else if (c[i - 1][j] >= c[i][j - 1])
			{
				c[i][j] = c[i - 1][j];
				b[i][j] = 2;
			}
			else
			{
				c[i][j] = c[i][j - 1];
				b[i][j] = 3;
			}
		}
	}
	cout << "����������г���(ʹ��m*n����)��" << c[m][n] << endl;
}

void LCS(int i, int j, char* x, int** b)   //�ݹ������Ӵ�
{
	if (i == 0 || j == 0)
	{
		//cout << endl;
		return;
	}
	if (b[i][j] == 1)
	{
		LCS(i - 1, j - 1, x, b);
		cout << x[i-1] << " ";
	}
	else if (b[i][j] == 2)
	{
		LCS(i - 1, j, x, b);
	}
	else
	{
		LCS(i, j - 1, x, b);
	}
}

void LCS1(int i, int j, char* x, int** c)  //��ʹ�ø������������Ӵ�
{
	if (i == 0 || j == 0)
	{
		//cout << endl;
		return;
	}
	if (c[i][j] == c[i - 1][j - 1] + 1)
	{
		LCS1(i - 1, j - 1, x, c);
		cout << x[i - 1] << " ";
	}
	else if (c[i][j] == c[i - 1][j])
	{
		LCS1(i - 1, j, x, c);
	}
	else
	{
		LCS1(i, j - 1, x, c);
	}
}

void LCSLength2(int m, int n, char* x, char* y, int** d)  //��ʹ��m*n���飬ʹ��2*n����
{
	int i, j;
	for (int i = 0; i <= 1; i++)
		d[i][0] = 0;
	for (int i = 1; i <= n; i++)
		d[0][i] = 0;
	int ii;
	for (i = 1; i <= m; i++)
	{
		ii = i % 2;
		//printf("i:%d , ii:%d \n", i, ii);
		for (j = 1; j <= n; j++)
		{
			if (x[i - 1] == y[j - 1])
			{
				d[ii][j] = d[(ii + 1)%2][j - 1] + 1;
			}
			else if (d[(ii + 1)%2][j] >= d[ii][j - 1])
			{
				d[ii][j] = d[(ii + 1)%2][j];
			}
			else
			{
				d[ii][j] = d[ii][j - 1];
			}
		}
	}
	printf("����������г���Ϊ(��ʹ��m*n����): %d\n ", d[m % 2][n]);
}

int main()
{
	char x[] = "abbbccasddpou";
	char y[] = "ubbtbgousc";
	int m = strlen(x);
	int n = strlen(y);

	printf("x �ַ���: %s\n", x);
	printf("y �ַ���: %s\n", y);
	//����ռ�

	int **c = new int* [m+1];
	int **b = new int* [m+1];
	for (int i = 0; i <= m; i++)
	{
		c[i] = new int[n+1];
		b[i] = new int[n+1];
	}

	int** d = new int* [2];
	d[0] = new int[n + 1];
	d[1] = new int[n + 1];

	LCSLength(m, n, x, y, c, b);
	LCSLength2(m, n, x, y, d);
	cout << "���������������(ʹ�ø�������)��" << endl;
	LCS(m, n, x, b);
	cout << endl;
	cout << "���������������(��ʹ�ø�������)��" << endl;
	LCS1(m, n, x, c);

	//�ͷſռ�
	for (int i = 0; i <= m; i++)
	{
		delete[] c[i];
		delete[] b[i];
	}
	delete[] d[0];
	delete[] d[1];

	return 0;
}

