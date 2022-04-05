#include<iostream>
#include<stack>
using namespace std;
int t, n;
int a[100010];
int b[100010];
stack<int> stk;
void f() {
	while (!stk.empty()) //先清空栈
		stk.pop();
	int i = 1, j = 1;
	for (i = 1; i <= n; ++i) {
		stk.push(a[i]);
		while (stk.top() == b[j]) {
			stk.pop();
			++j;
			if (stk.empty()) break;
		}
	}
	
	if (stk.empty()) cout << "YES\n";
	else cout << "NO\n";
}

int main()
{
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; ++i) cin >> a[i];
		for (int i = 1; i <= n; ++i) cin >> b[i];
		f();
	}
	return 0;
}
