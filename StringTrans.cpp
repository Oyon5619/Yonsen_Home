#include<iostream>
#include<queue>
#include<map>
#include<algorithm>
using namespace std;
string sa[8], sb[8];
string a, b;
int n;
map<string, int> tag;//用map存放已经宽搜过的字符串,用于去重(否则可能会超时)
struct node {
	string s;
	int step;
};

void bfs() {
	queue<node> que;
	node n1, n2, n3;
	string t;
	n1.s = a, n1.step = 0;
	que.push(n1);

	while (!que.empty()) {
		n2 = que.front();

		//cout << n2.s << " " << n2.step << endl;

		if (!n2.s.compare(b) && n2.step <= 10) {
			cout << n2.step;
			return;
		}

		if (n2.step > 10) {
			cout << "NO ANSWER!";
			return;
		}
		if (tag[n2.s]) { que.pop(); continue; }//去重
		tag[n2.s] = 1;//标记
		que.pop();
		for (int i = 0; i < n; ++i) {
			t = n2.s;
			while (1) { //找出子串sa[i]的所有位置
				size_t pos = t.find(sa[i]);
				if (pos != string::npos) { //能找到子串
					n3.s = n2.s;
					n3.s = n3.s.replace(pos, sa[i].size(), sb[i]);//替换
					n3.step = n2.step + 1;
					que.push(n3);
					t[pos] = '-';//这里子串第一次被找到的位置用其他字符替代,目的是用于寻找该子串下一次出现的位置
				}
				else break;//全找到了
			}
		}
	}
	if (n2.s.compare(b)) cout << "NO ANSWER!";//这种情况是10步以内发现a不可能转换为b
}

int main()
{
	string s1, s2;
	n = 0;
	cin >> a >> b;
	while (cin >> s1 >> s2) {
		sa[n] = s1, sb[n] = s2;
		++n;
	}
	bfs();
	return 0;
}
