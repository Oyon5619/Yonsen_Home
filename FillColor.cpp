//洛谷 P1162 填涂颜色
#include<iostream>
#include<queue>
using namespace std;
typedef long long ll;
const int MAX = 35;
int mp[MAX][MAX];
int n;
//上下左右四个方向
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
struct node {
	int x, y;
};

void bfs() {
	queue<node> que;//创建一个连通块队列
	node e,e1,e2;
	e.x = 0, e.y = 0;
	que.push(e);
	mp[e.x][e.y] = -1;
	//求外部连通的0区块
	while (!que.empty()) {
		e1 = que.front();
		que.pop();
		for (int i = 0; i < 4; ++i) {
			int nx = e1.x + dx[i], ny = e1.y + dy[i];
			if (nx>=0&&ny>=0&&nx<=n+2&&ny<=n+2) {
				if (!mp[nx][ny]) { //查找在边界外的0
					mp[nx][ny] = -1;
					e2.x = nx, e2.y = ny;
					que.push(e2);
				}
			}
		}
	}
}

void print() {
	//按要求输出
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (mp[i][j] == -1) cout << "0 ";
			else if (mp[i][j] == 1) cout << "1 ";
			else cout << "2 ";
		}
		putchar('\n');
	}
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			cin >> mp[i][j];
	bfs();
	print();
	return 0;
}
