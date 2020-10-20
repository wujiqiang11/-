#include<iostream>
#include<vector>
using namespace std;


const int n = 5;
vector<double> a = { 0.05,0.1,0.05,0.05,0.05,0.1 };
//b(n+1)  b(0) is not useful
vector<double> b = { -1,0.15,0.1,0.05,0.1,0.2 };
vector<vector<double> > m(n + 2, vector<double>(n + 1));
vector<vector<double> > w(n + 2, vector<double>(n + 1));
vector<vector<int> > s(n + 2, vector<int>(n + 1, 0));


void OptimalBinarySearchTree(vector<double>& a, vector<double>& b, int n, vector<vector<double> >& m,
	vector<vector<int> >& s, vector<vector<double> >& w)
{
	for (int i = 0; i <= n; i++) {
		w[i + 1][i] = a[i];
		m[i + 1][i] = 0;
	}
	for (int r = 0; r < n; r++) {
		for (int i = 1; i <= n - r; i++) {
			int j = i + r;
			w[i][j] = w[i][j - 1] + a[j] + b[j];
			m[i][j] = m[i + 1][j];
			s[i][j] = i;
			for (int k = i; k <= j; k++) {
				double t = m[i][k - 1] + m[k + 1][j];
				if (t < m[i][j]) {
					m[i][j] = t;
					s[i][j] = k;
				}
			}
			m[i][j] += w[i][j];
		}
	}
}
void printVector(vector<vector<double> > nums) {
	for (int i = 0; i < nums.size(); i++) {
		for (int j = 0; j < nums[0].size(); j++) {
			cout << nums[i][j] << " ";
		}
		cout << endl;
	}
}

//��ӡ����
void printVector(vector<vector<int> > nums) {
	for (int i = 0; i < nums.size(); i++) {
		for (int j = 0; j < nums[0].size(); j++) {
			cout << nums[i][j] << " ";
		}
		cout << endl;
	}
}
//��ӡ������
void printOptimalBST(int i, int j, int r)
{
	int rootChild = s[i][j];//�������ڵ�
	if (rootChild == s[1][n])
	{
		//����������ĸ�
		cout << "k" << rootChild << "�Ǹ�" << endl;
		printOptimalBST(i, rootChild - 1, rootChild);
		printOptimalBST(rootChild + 1, j, rootChild);
		return;
	}

	if (j < i - 1)
	{
		return;
	}
	else if (j == i - 1)//���������
	{
		if (j < r)
		{
			cout << "d" << j << "��" << "k" << r << "������" << endl;
		}
		else
			cout << "d" << j << "��" << "k" << r << "���Һ���" << endl;
		return;
	}
	else//�����ڲ����
	{
		if (rootChild < r)
		{
			cout << "k" << rootChild << "��" << "k" << r << "������" << endl;
		}
		else
			cout << "k" << rootChild << "��" << "k" << r << "���Һ���" << endl;
	}

	printOptimalBST(i, rootChild - 1, rootChild);
	printOptimalBST(rootChild + 1, j, rootChild);
}
int main() {
	OptimalBinarySearchTree(a, b, n, m, s, w);
	cout << "m: " << endl;
	printVector(m);
	cout << "w: " << endl;
	printVector(w);
	cout << "s: " << endl;
	printVector(s);
	cout << "printOptimalBST: " << endl;
	printOptimalBST(1, n, -1);
	return 0;
}