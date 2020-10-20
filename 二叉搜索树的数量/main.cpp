#include<iostream>
using namespace std;
int treeNum(int* a, int i, int j)
{
	if (i == j)
		return 1;
	int num = 0;
	int temp = 0;
	for (int k = i; k <= j; k++)
	{
		if (k == i)
		{
			temp = treeNum(a, k + 1, j);
		}
		else if(k == j)
		{
			temp = treeNum(a, i, k - 1);
		}
		else
		{
			temp = treeNum(a, i, k - 1)*treeNum(a, k+1, j);
		}
		num = num + temp;
		//printf("%d\n", num);
	}
	return num;
}
int main()
{
	int n;
	printf("输入数组长度:\n");
	scanf_s("%d", &n);
	int a[3] = { 1,2 ,3};
	int tree = treeNum(a, 0, n-1);
	printf("数组a的二叉搜索树数量：%d\n",tree);
	return 0;
}