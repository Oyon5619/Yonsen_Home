//洛谷P2437 蜜蜂路线(高精度 + 递推)
#include<iostream>
using namespace std;
typedef long long ll;
ll n, m, k, len = 1;
ll t[1003][1003];

void hPlus(int k) {
	for (int j = 1; j <= len; ++j)
		t[k][j] = t[k - 1][j] + t[k - 2][j];//递推
	for (int j = 1; j <= len; ++j) {
		//进位相加
		if (t[k][j] > 9) {
			t[k][j + 1] += t[k][j] / 10;
			t[k][j] %= 10;
			if (t[k][len + 1])++len;//数组长度加一
		}
	}
}

int main()
{
	cin >> m >> n;
	k = n - m + 1;
	t[1][1] = 1, t[2][1] = 1;
	for (int i = 3; i <= k; ++i) {
		hPlus(i);//高精度加法
	}

	for (int i = len; i >= 1; --i)
		printf("%lld", t[k][i]);
	
	return 0;
}
