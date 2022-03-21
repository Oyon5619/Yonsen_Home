//洛谷P1464
#include<iostream>
using namespace std;
typedef long long ll;
ll a, b, c, res;
//记忆化+递归(减少重复递归的次数)
ll dp[25][25][25];//计算
ll w(ll a,ll b,ll c) {
	if (a <= 0 || b <= 0 || c <= 0) return 1;
	if (a > 20 || b > 20 || c > 20) return w(20, 20, 20);
	if (dp[a][b][c] != 0) return dp[a][b][c];//已经算过了,那就直接返回
	if (a < b && b < c) dp[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
	else dp[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
	return dp[a][b][c];
}

int main()
{
	while (cin >> a >> b >> c) {	
		if (a == -1 && b == -1 &&c == -1) return 0;
		printf("w(%lld, %lld, %lld) = %lld\n", a, b, c, w(a, b, c));
	}
	return 0;
}
