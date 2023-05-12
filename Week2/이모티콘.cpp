#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int S;
    cin >> S;

    vector<vector<int>> dp(S + 1, vector<int>(S + 1, -1)); // dp[i][j]: 화면에 i개 이모티콘을 만들고, 클립보드에 j개 이모티콘이 있는 상태에서 필요한 최소 시간

    queue<pair<int, int>> q;
    q.push(make_pair(1, 0)); // 초기 상태: 화면에 1개 이모티콘, 클립보드에 0개 이모티콘
    dp[1][0] = 0; // 초기 상태에서는 이미 화면에 1개 이모티콘이 있는 상태이므로 시간은 0

    while (!q.empty()) {
        int screen = q.front().first;
        int clipboard = q.front().second;
        q.pop();

        // 1. 복사하기
        if (dp[screen][screen] == -1) {
            dp[screen][screen] = dp[screen][clipboard] + 1;
            q.push(make_pair(screen, screen));
        }

        // 2. 붙여넣기
        if (screen + clipboard <= S && dp[screen + clipboard][clipboard] == -1) {
            dp[screen + clipboard][clipboard] = dp[screen][clipboard] + 1;
            q.push(make_pair(screen + clipboard, clipboard));
        }

        // 3. 삭제하기
        if (screen - 1 >= 0 && dp[screen - 1][clipboard] == -1) {
            dp[screen - 1][clipboard] = dp[screen][clipboard] + 1;
            q.push(make_pair(screen - 1, clipboard));
        }
    }

    int minTime = -1;
    for (int i = 0; i <= S; i++) {
        if (dp[S][i] != -1) {
            if (minTime == -1 || minTime > dp[S][i]) {
                minTime = dp[S][i];
            }
        }
    }

    cout << minTime << endl;

    return 0;
}
