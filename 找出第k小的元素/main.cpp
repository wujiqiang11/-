#include<iostream>
#include<time.h>
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
int partition(T a[], int low, int high) //划分
{
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
int RandomPatition(T a[], int low, int high)
{
	int i = (rand() % (high - low + 1)) + low;
	Swap(a[i], a[low]);
	return partition(a, low, high);
}

template<class T>
T select(T a[], int low, int high, int k)  //在数组a[]的 low~high 中找出第k小的元素
{
	if (low==high)
	{
		return a[low];
	}
	int i = RandomPatition(a, low, high);
	int j = i - low + 1;
	if (j >= k)
		return select(a, low, i, k);
	else
		return select(a, i + 1, high, k - j);
}

int main()
{
	int n, k;
	cin >> n;
	cout << " 请输入" << n << "个数" << endl;
	int* a = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	cout << "输入k" << endl;
	cin >> k;
	int a_k = select(a, 0, n - 1, k);
	cout << a_k << endl;
	return 0;
}