
#include <iostream>
using namespace std;
int WeekToDay(int y, int m, int c, int w, bool B){//�����������µڼ������ڼ����Լ��������ǵ������������
	int d, week, i;
	if (m == 1){ m = 13; y--; }//��ʽҪ��1�¡�2��ҪתΪ��һ��13��14��
	if (m == 2){ m = 14; y--; }
	i = 0;
	for (d = B ? 1 : 31; d <= B ? 31 : 1; B ? (d++) : (d--)){//B������/����
		week = (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400) % 7;//���չ�ʽ
		if (week + 1 == w) ++i;
		if (i == c) break;
	}
	return d;
}

int main(void){
	int y;
	while (cin >> y){
		cout << y << "-01-01" << endl;
		printf("%d-01-%02d\n", y, WeekToDay(y, 1, 3, 1, 1));
		printf("%d-02-%02d\n", y, WeekToDay(y, 2, 3, 1, 1));
		printf("%d-05-%02d\n", y, WeekToDay(y, 5, 1, 1, 0));//����
		cout << y << "-07-04" << endl;
		printf("%d-09-%02d\n", y, WeekToDay(y, 9, 1, 1, 1));
		printf("%d-11-%02d\n", y, WeekToDay(y, 11, 4, 4, 1));
		cout << y << "-12-25" << endl << endl;
	}
	system("pause");
	return 0;
}