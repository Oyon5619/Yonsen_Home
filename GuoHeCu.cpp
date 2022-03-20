//过河卒 
#include<iostream>
#include<string.h>
using namespace std;
typedef long long ll;
ll dp[30][30];
bool p[30][30];
ll x, y, mx, my;
//马的所有控制点 
ll dx[9] = { 0, -1,-2,-2,-1,1,2,2,1 }; 
ll dy[9] = { 0, -2,-1,1,2,2,1,-1,-2 };

void solve() {

	for (ll i = 2; i <= x; ++i)
		for (ll j = 2; j <= y; ++j) {
			if (p[i][j]) continue;
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}

	printf("%lld",dp[x][y]);
}

int main()
{
	cin >> x >> y >> mx >> my;
	x += 2, y += 2, mx += 2, my += 2;//防止越界
	dp[1][2] = 1;
	//马的坐标和马的控制点
	for (ll i = 0; i < 9; ++i) {
		ll nx = mx + dx[i], ny = my + dy[i];
		p[nx][ny] = 1;
	}
	solve();
	return 0;
}
