#include<iostream>
#include<queue>
#include<string.h>
using namespace std;
typedef long long ll;
const int MAX = 310;
int mp[MAX][MAX] = { 0 };
bool vis[MAX][MAX] = { 0 };
int m;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
struct node {
	int x, y, t;
};

void bfs() {
	queue<node> que;//用于存放可行走方块的队列
	node e, e1, e2;
	e.x = e.y = e.t = 0;
	que.push(e);
	vis[e.x][e.y] = 1;

	while (!que.empty()) {
		e1 = que.front();
		que.pop();
		for (int i = 0; i < 4; ++i) { //四个方向都可以逃
			int ex = e1.x + dx[i], ey = e1.y + dy[i];
			if (ex >= 0 && ey >= 0 && (!vis[ex][ey])) {//不越界
				if (mp[ex][ey] == -1) { //成功到达安全地
					cout << e1.t + 1;//输出答案
					return;
				}
				if (e1.t + 1 < mp[ex][ey] || mp[ex][ey] == -1) {//这块能走
					e2.x = ex, e2.y = ey, e2.t = e1.t + 1;
					vis[ex][ey] = 1;
					que.push(e2);//入队
				}
			}
		}
	}
	cout << -1;//到达不了安全的格子
}

int main()
{
	cin >> m;
	int a, b, t, nx, ny;
	memset(mp, -1, sizeof(mp));
	while (m--) {
		cin >> a >> b >> t;
		if (mp[a][b] == -1 || mp[a][b] > t) mp[a][b] = t;//(a,b)处在t时刻会有陨石(也不排除不同时刻的陨石伤害范伟会重叠)

		for (int i = 0; i < 4; ++i) {
			nx = a + dx[i], ny = b + dy[i];
			if (nx >= 0 && ny >= 0) {//不越界
				//表示当前时刻和位置的陨石伤害范围
				if (mp[nx][ny] == -1 || t < mp[nx][ny])
					mp[nx][ny] = t;
			}
		}
	}
	bfs();
	return 0;
}
