#include<iostream>
#include<set>
#include<algorithm>
using namespace std;
typedef long long ll;
int n, ans = 0;
struct ln {
	int a, b;
} lns[100010];
bool cmp(ln l1,ln l2){
	if (l1.b == l2.b) return l1.a < l2.a;
	return l1.b < l2.b;
}
/*显然放右端点最靠左的线段最好，从左向右放，右端点越小妨碍越少
其他线段放置按右端点排序，贪心放置线段，即能放就放*/
int main()
{
	cin >> n;
	int a, b;
	for (int i = 1; i <= n; ++i) {
		cin >> a >> b;
		lns[i].a = a, lns[i].b = b;
	}
	sort(lns + 1, lns + n + 1, cmp);
	
	/*printf("\n\n");
	for (int i = 1; i <= n; ++i) {
		cout << lns[i].a << " " << lns[i].b << endl;
	}
	printf("\n\n");*/
	int j = -1;
	for (int i = 1; i <= n; ++i) {
		if (lns[i].a >= j) {
			ans++; j = lns[i].b;
		}
	}

	cout << ans;


	return 0;
}
