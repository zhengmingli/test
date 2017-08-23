#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

string a, b;///原单词和目标单词;

stack <char> build;///构造目标字符串
vector <char> operate;///记录出入栈操作
int len;///字符串a长度


		///iPush表示入栈操作的次数，iPop表示出栈操作的次数；
void dfs(int iPush, int iPop)
{
	///当出入栈操作的次数刚好等于字符串长度时，目标单词构造完成。
	if (iPush == len&&iPop == len)
	{
		for (int i = 0;i<operate.size();i++)
			cout << operate[i] << " ";
		cout << endl;
	}
	///入栈操作；
	if (iPush + 1 <= len)
	{
		build.push(a[iPush]);
		operate.push_back('i');
		dfs(iPush + 1, iPop);
		build.pop();
		operate.pop_back();
	}
	///出栈操作；
	if (iPop + 1 <= iPush&&iPop + 1 <= len&&build.top() == b[iPop])
	{
		char tc = build.top();
		build.pop();
		operate.push_back('o');
		dfs(iPush, iPop + 1);
		build.push(tc);
		operate.pop_back();
	}
}


int main()
{
	a = "madam";
	b = "adamm";
	
		len = a.length();
		cout << "[" << endl;
		dfs(0, 0);
		cout << "]" << endl;
	
	return 0;
}