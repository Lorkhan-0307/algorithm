#include <iostream>
#include <algorithm>
using namespace std;

int N, S, M;
int dp[101][1001];
int v[101];

int main() {

	cin >> N >> S >> M;

	for (int i = 1; i <= N; i++) {
		cin >> v[i];
	}

	dp[0][S] = 1;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= M; j++) {
			if (dp[i - 1][j] == 1) {
				if (j + v[i] <= M) dp[i][j + v[i]] = 1;
				if (j - v[i] >= 0) dp[i][j - v[i]] = 1;
			}
		}
	}

	for (int i = M; i >= 0; i--) {
		if (dp[N][i] == 1) {
			cout << i << '\n';
			return 0;
		}
	}

	cout << -1 << '\n';
	return 0;
}