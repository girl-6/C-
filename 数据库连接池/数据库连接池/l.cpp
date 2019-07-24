//#include <iostream>
//#include <string>
//#include <queue>
//
//using namespace std;
//
//int main()
//{
//	int n;
//	while (cin >> n)
//	{
//		int con = 0;
//		queue<char> q;
//		for (int i = 0; i<n; i++)
//		{
//			char ID;
//			cin >> ID;
//			string OP;
//			cin >> OP;
//			if (OP == "connect")
//				q.push(ID);
//			else
//			{
//				con = q.size()>con ? q.size() : con;
//				q.pop();
//			}
//		}
//		cout << con << endl;
//	}
//	return 0;
//}

#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int Connect(vector<string> v)
{
	int c = 0;
	queue<string> q;
	for (int i = 1; i<v.size(); i += 2)
	{
		if (v[i] == "connect")
			q.push(v[i - 1]);
		else{
			c = q.size()>c ? q.size() : c;
			q.pop();
		}
	}
	return c;
}
int main()
{
	int n;
	while (cin >> n)
	{
		vector<string> v;
		for (int i = 0; i<n; i++)
		{
			string id, op;
			cin >> id >> op;
			v.push_back(id);
			v.push_back(op);
		}
		cout << Connect(v) << endl;
	}
	return 0;
}
