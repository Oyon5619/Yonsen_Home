//洛谷P2404 自然数的拆分问题
#include<iostream>
#include<stdio.h>
using namespace std;
typedef long long ll;
int p[10];
int n;

//输出
void print(int m) {
	for (int i = 1; i <= m - 1; ++i)
		printf("%d+",p[i]);
	printf("%d\n",p[m]);
}

void dfs(int k, int m, int z) {
	//k表示所选的数,m表示所选数之和，z表示第z个数
	if (k == n) return;//不给单独输出
	if (m == n) {
		print(z - 1);//当前所选数之和等于n,则输出结果(z-1个数之和)
		return;
	}
	for (int i = k; i <= n - m; ++i) {
		p[z] = i;//记录当前选的数
		dfs(i, m + i, z + 1);
	}
}

int main()
{
	cin >> n;
	dfs(1, 0, 1);//当前从1开始,初始所选数之和为0,而且是第1个数
	return 0;
}
