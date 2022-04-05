#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//卡片拆分问题
const int maxn = 2021;
int num[10];//0 - 9数字
bool flag(vector<int> vec) { //flag函数用于判断剩余的卡片是否能组成接下来的数
	for (int i = 0; i < vec.size(); ++i) {
		num[vec[i]]--;
		if (num[vec[i]] < 0) return false;//没有足够的卡片可以组成,就返回false
	}
	return true;//默认可以组成
}
vector<int> numSplit(int n) {//将数字分割
	vector<int> res;
	int p;
	while (n) {
		p = n % 10;
		res.push_back(p);
		n /= 10;
	}
	return res;
}
int main()
{
	//先初始化
	int ans = 1; //因为是从1开始拼数
	for (int i = 0; i < 10; ++i)
		num[i] = maxn;
	while (true) {
		vector<int> tmp = numSplit(ans);
		if (flag(tmp)) {
			//for (int i = 0; i < tmp.size(); ++i)
			//	cout << tmp[i] << " ";
			//cout << '\n';
			++ans;
		}
		else break;
	}
	cout << ans - 1;//打印最终结果
	return 0;
}
