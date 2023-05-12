#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000000000;

int main() {
    int N, K;
    cin >> N >> K;

    vector<vector<int>> dp(K + 1, vector<int>(N + 1, 0));

    // 합이 N이 되는데 사용하는 정수의 개수가 1개인 경우
    for (int i = 0; i <= N; i++) {
        dp[1][i] = 1;
    }

    // 합이 N이 되는데 사용하는 정수의 개수가 k개인 경우
    for (int k = 2; k <= K; k++) {
        for (int n = 0; n <= N; n++) {
            for (int i = 0; i <= n; i++) {
                dp[k][n] += dp[k - 1][i];
                dp[k][n] %= MOD;
            }
        }
    }

    cout << dp[K][N] << endl;

    return 0;
}
