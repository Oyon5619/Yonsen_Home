//洛谷P1010 幂次方
#include<iostream>
using namespace std;
typedef long long ll;
ll n;

//归根结底都要用2(0),2来表示(本人思路: 递归输出)
void f(ll k) {
	if (k == 1) cout << "2(0)";
	else if (k == 2) cout << "2";
	else { //用原来n的数减去2的幂，如果这个数大于2，继续对新的n进行搜索；
		ll i = 1, s = 0;
		while (i <= k) {
			i <<= 1; ++s;
		}
		i >>= 1; --s;
		if (k - i) { //说明k > i
			if (s == 1) cout << "2+";
			else {
				cout << "2("; f(s); cout << ")+";
			}
			f(k - i);//继续探索余数(k - i)的表达式
		}
		else { //说明 k == i
			cout << "2("; f(s); cout << ")";//后面就不用再加括号了,因为已经分解完了
		}
	}
}

int main()
{
	cin >> n;
	f(n);
	return 0;
}
