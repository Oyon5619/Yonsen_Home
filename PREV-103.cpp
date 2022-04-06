#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
int n, k, p, res = 1;
vector<int> vec;
const int md = 1e9 + 9;
int main()
{
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> p;
		vec.push_back(p);
	}
	
	sort(vec.begin(), vec.end());
	int sign = 1;
	int l = 0, r = n - 1;
	if (k & 1) { //k为奇数
		res = vec[r--];//取最大的数
		--k;
		if (res < 0) sign = -1;//如果最大为负数,那就改变符号
	}
	while (k) {//这里的k是偶数时的情况
		//取最小的两个与最大的两个进行乘积(这里需要强制转换)
		ll x = (ll)vec[l] * vec[l + 1];
		ll y = (ll)vec[r] * vec[r - 1];
		if (x * sign > y * sign) {
			res = x % md * res % md;//看两个数与当前符号相乘哪个大取哪个
			l += 2;
		}
		else {
			res = y % md * res % md;
			r -= 2;
		}
		k -= 2;
	}
	cout << res;
	return 0;
}
/*
解题思路：
1、如果k==n的话，那么全部数字都要选
2、如果k%2==0(即k为偶数)，那么选出来的一个是非负数
3、如果k%2==1(即k为奇数)分两种：
（1）如果全部都为负数，那么全部都为负数，把最大最大负数取出来，然后变成了k为偶数的情况，要把符号改变过来
（2）否则的话,则一定至少有 1个非负数, 那么我们将最大的数取出来,然后变成了k为偶数的情况。
*/
