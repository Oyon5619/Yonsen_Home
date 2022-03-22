//洛谷P1443 马的遍历
#include<stdio.h>
#include<iostream>
#include<queue>
using namespace std;
typedef long long ll;
ll t[410][410] = { 0 };
bool vis[410][410] = { false };
ll n, m;
//自定义结构体node,用于存放坐标
struct node {
	ll x, y;
};
//马走日
ll dx[8] = { 1,2,2,1,-1,-2,-2,-1 };
ll dy[8] = { 2,1,-1,-2,-2,-1,1,2 };
node k;

//利用bfs算法(广度优先搜索)来解决
void f() {
	queue<node> que;
	que.push(k);
	node e1 ,e2;
	while (!que.empty()) {
		e1 = que.front();//队头
		que.pop();//出队一个元素
		for (int i = 0; i < 8; ++i) {
			ll nx = e1.x + dx[i], ny = e1.y + dy[i];
			if (!vis[nx][ny] && nx >= 1 && nx <= n 
				&& ny >= 1 && ny <= m) {//没走过这格而且这个格所在位置不越界
				vis[nx][ny] = 1;
				t[nx][ny] = t[e1.x][e1.y] + 1;//前面走过的最小步数+1
				e2.x = nx, e2.y = ny;
				que.push(e2);//入队
			}	
		}
	}
}

//输出结果
void print() {
	for (ll i = 1; i <= n; ++i) {
		for (ll j = 1; j <= m; ++j)
			if (vis[i][j]) printf("%-5lld", t[i][j]);
			else printf("%-5lld", -1ll);
		printf("\n");
	}
}

int main()
{
	cin >> n >> m >> k.x >> k.y;
	vis[k.x][k.y] = 1;//将马的起始位置标记起来
	f();
	print();
	return 0;
}
