#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

string a, b;///ԭ���ʺ�Ŀ�굥��;

stack <char> build;///����Ŀ���ַ���
vector <char> operate;///��¼����ջ����
int len;///�ַ���a����


		///iPush��ʾ��ջ�����Ĵ�����iPop��ʾ��ջ�����Ĵ�����
void dfs(int iPush, int iPop)
{
	///������ջ�����Ĵ����պõ����ַ�������ʱ��Ŀ�굥�ʹ�����ɡ�
	if (iPush == len&&iPop == len)
	{
		for (int i = 0;i<operate.size();i++)
			cout << operate[i] << " ";
		cout << endl;
	}
	///��ջ������
	if (iPush + 1 <= len)
	{
		build.push(a[iPush]);
		operate.push_back('i');
		dfs(iPush + 1, iPop);
		build.pop();
		operate.pop_back();
	}
	///��ջ������
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