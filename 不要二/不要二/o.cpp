//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int main(){
//	int W, H, i, j, counts = 0;
//	cin >> W >> H;
//	if (W % 4 == 0 || H % 4 == 0){
//		counts = W * H / 2;
//	}
//	else if (W % 2 == 0 && H % 2 == 0){
//		counts = (W * H / 4 + 1) * 2;
//	}
//	else{
//		counts = W * H / 2 + 1;
//	}
//	cout << counts << endl;
//	return 0;
//}



#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int w, h, res = 0;
	cin >> w >> h;
	vector<vector<int>> a;
	a.resize(w);
	for (auto& e : a)
		e.resize(h, 1);
	for (int i = 0; i<w; i++)
	{
		for (int j = 0; j<h; j++)
		{
			if (a[i][j] == 1)
			{
				res++;
				// 标记不能放蛋糕的位置
				if ((i + 2)<w)
					a[i + 2][j] = 0;
				if ((j + 2)<h)
					a[i][j + 2] = 0;
			}
		}
	}
	cout << res;
	return 0;
}
