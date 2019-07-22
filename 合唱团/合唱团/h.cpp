#include <iostream>
#include <string>
#include <vector>
#include <limits.h>         // �� LONG_MIN LONG_MAX

using namespace std;

// NK���ŵ��ǣ���ǰn��ѧ���У�ȡk������ȡ��n���������ȵõ���������˻�����С���˻���
long long NK_zheng[51][11];
long long NK_fu[51][11];

int main() {

	int N;
	cin >> N;

	vector<int> V(N + 1);
	for (int i = 1; i <= N; i++) {
		cin >> V[i];
	}

	int K, D;
	cin >> K >> D;

	for (int n = 1; n <= 50; n++) {
		for (int k = 1; k <= 10; k++) {
			NK_zheng[n][k] = LLONG_MIN;     // ������Чֵ
			NK_fu[n][k] = LLONG_MAX;
		}
	}

	for (int n = 1; n <= N; n++) {
		if (V[n] >= 0)
			NK_zheng[n][1] = V[n];
		else
			NK_fu[n][1] = V[n];
	}

	for (int n = 2; n <= N; n++) {
		for (int k = 2; k <= K && k <= n; k++) {
			// �ҵ�NK[...][k-1]��������������С�ĸ�����
			long long max = LLONG_MIN, min = LLONG_MAX;
			for (int temp = (k - 1 > n - D) ? (k - 1) : (n - D); temp <= n - 1; temp++) {     // ��ʼλ�ú���Ҫ
				if (max < NK_zheng[temp][k - 1])
					max = NK_zheng[temp][k - 1];
				if (min > NK_fu[temp][k - 1])
					min = NK_fu[temp][k - 1];
			}
			if (max != LLONG_MIN) {
				if (V[n] >= 0)
					NK_zheng[n][k] = max * V[n];
				else
					NK_fu[n][k] = max * V[n];
			}
			if (min != LLONG_MAX) {
				if (V[n] < 0 && NK_zheng[n][k] < min * V[n])
					NK_zheng[n][k] = min * V[n];
				else if (NK_fu[n][k] > min * V[n])
					NK_fu[n][k] = min * V[n];
			}
		}
	}

	// ������������һ���У��ҳ����ĳ˻���
	long long max1 = LLONG_MIN, max2 = LLONG_MIN;
	for (int n = K; n <= N; n++) {
		if (max1 < NK_zheng[n][K])
			max1 = NK_zheng[n][K];
		if (max2 < NK_fu[n][K] && NK_fu[n][K] != LLONG_MAX)
			max2 = NK_fu[n][K];
	}

	max1 = max1 > max2 ? max1 : max2;

	cout << max1 << endl;
}