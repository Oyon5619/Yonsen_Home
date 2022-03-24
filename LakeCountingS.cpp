//洛谷 P1596 [USACO10OCT]Lake Counting S
#include<iostream>
#include<stdio.h>
using namespace std;
typedef long long ll;
const int MAX = 105;
char mp[MAX][MAX];
int n, m;
int dx[8] = { -1,-1,-1,0,1,1,1,0 };
int dy[8] = { -1,0,1,1,1,0,-1,-1 };
//dfs算法
void dfs(int a, int b) {
	//八个方向都可以找找有无水坑
	for (int j = 0; j < 8; ++j) {
		int nx = a + dx[j], ny = b + dy[j];
		if (nx >= 1 && nx <= n && 
			ny >= 1 && ny <= m && 
			mp[nx][ny] == 'W') {//不越界,而且是水坑
			mp[nx][ny] = '.';
			dfs(nx, ny);//继续搜寻周围看看还有无水坑
		}
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) 
			cin >> mp[i][j];
		
	int res = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) 
			if (mp[i][j] == 'W') {
				dfs(i, j);//找出整个水坑
				++res;
			}
	printf("%d", res);
	return 0;
}
