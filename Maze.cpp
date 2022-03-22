//洛谷P1605 迷宫
#include<stdio.h>
#include<iostream>
using namespace std;
typedef long long ll;
int n, m, t, sx, sy, fx, fy, res = 0;
int mp[7][7] = { 0 };
bool vis[7][7] = { false };//记忆化
//可以往上下左右四个方向移动一格
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void dfs(int a, int b) {
	if (a == fx && b == fy) {//找到终点
		res++;
		return;
	}
	for (int i = 0; i < 4; ++i) {
		int nx = a + dx[i], ny = b + dy[i];
		if (nx >= 1 && nx <= n
			&& ny >= 1 && ny <= m) {//坐标不越界
			if (mp[nx][ny] != -1 && !vis[nx][ny]) {//不是障碍
				vis[nx][ny] = 1;
				dfs(nx, ny);//深度优先
				vis[nx][ny] = 0;//回溯
			}
		}
	}
}

int main()
{
	cin >> n >> m >> t;
	cin >> sx >> sy >> fx >> fy;//起点(sx,sy)和终点(fx,fy)
	vis[sx][sy] = 1;
	int i, j;
	while (t--) {
		cin >> i >> j;
		mp[i][j] = -1;
	}
	dfs(sx, sy);
	cout << res;
	return 0;
}
