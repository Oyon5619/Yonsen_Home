//洛谷 临时抱佛脚
#include<stdio.h>
#include<iostream>
using namespace std;
typedef long long ll;
int p[6];//习题集
int t[22];//每题耗时量
int dp[5005];//dp数组(01)
int res = 0;
int main()
{
	int i, j, total;
	for (i = 0; i < 4; ++i) cin >> p[i];

	for (i = 0; i < 4; ++i) {
		total = 0;
		for (j = 0; j < p[i]; ++j) {
			cin >> t[j];
			total += t[j];
		}
		//最优解: 总和是总时间的一半
		for (j = 0; j < p[i]; ++j)
			for (int k = total/2; k >= t[j]; --k)
				dp[k] = max(dp[k], dp[k - t[j]] + t[j]);//01背包问题
		//累加到最接近total/2的值(累加为另一个脑子)
		res += total - dp[total / 2];
		memset(dp,0,sizeof(dp));
	}
	cout << res;
	return 0;
}
