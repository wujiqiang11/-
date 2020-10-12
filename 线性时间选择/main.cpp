#include<iostream>
#include<time.h>
#include<algorithm>
using namespace std;

template<class T>
void Swap(T& a, T& b)
{
	T temp;
	temp = a;
	a = b;
	b = temp;
}

template<class T>
int partition(T a[], int low, int high, int mid) //划分
{
	Swap(a[low], a[mid]);
	T temp = a[low];
	int i = low;
	int j = high + 1;
	while (true)
	{
		while (a[++i] < temp && i < high);
		while (a[--j] > temp);
		if (i >= j)
			break;
		Swap(a[i], a[j]);
	}
	a[low] = a[j];
	a[j] = temp;
	return j;
}

template<class T>
T select(T a[], int low, int high, int k)  //在数组a[]的 low~high 中找出第k小的元素, 中位数法
{
	if (high - low + 1 <= 75)
	{
		sort(a+low, a+high);
		return a[low + k - 1];
	}
	int j = (high - low + 1) / 9;
	for (int i = 0; i < j; i++)
	{
		sort(a+low + 9 * i, a+low + 9 * i + 8);
		Swap(a[low + i], a[low + 9 * i + 4]);
	}
	sort(a + low, a + low + j - 1);
	int mid = (j - 1) / 2;
	int x_i = partition(a, low, high, mid);
	int x_j = x_i - low + 1;
	if (k <= x_j)
		select(a, low, x_i, k);
	else
		select(a, x_i + 1, high, k - x_j);
}

int main()
{
	/*
	int n, k;
	cin >> n;
	cout << " 请输入" << n << "个数" << endl;
	int* a = new int[n];
	*/
	int a[1000];
	int j = 0,k;
	for (int i = 1000; i > 0; i--)
	{
		a[j++]=i;
	}
	cout << "输入k" << endl;
	cin >> k;
	int a_k = select(a, 0, 999, k);
	cout << a_k << endl;
	return 0;
}
