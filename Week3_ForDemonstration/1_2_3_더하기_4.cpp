#include <iostream>
#define Max 10001
using namespace std;

int DP[Max][4] = { 0, };
int curN = 0;
int T;

void solution() {
	DP[0][1] = 1;
	DP[1][1] = 1;
	for (int i = 2; i <= 10000; i++) {
		DP[i][1] = DP[i - 1][1];
		DP[i][2] = DP[i - 2][1] + DP[i - 2][2];
		if (i >= 3)
			DP[i][3] = DP[i - 3][1] + DP[i - 3][2] + DP[i - 3][3];
	}
}

int main() {
	int n;
	cin >> T;
	solution();
	curN = 3;
	while (T--) {
		cin >> n;
		cout << DP[n][1] + DP[n][2] + DP[n][3] << '\n';
	}
	return 0;
}