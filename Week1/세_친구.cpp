#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
int answer = -1;
bool isFriends[4001][4001];
vector<int> friends[4001];


int main(){
    cin >> n >> m;

    
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        friends[a].push_back(b);
        friends[b].push_back(a);
        isFriends[a][b] = isFriends[b][a] = true;
    }


    int answer = -1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < friends[i].size(); j++) {
            int B = friends[i][j];
            for (int k = j + 1; k < friends[i].size(); k++) {
                int C = friends[i][k];
                if (isFriends[B][C]) {
                    int sum = friends[i].size() + friends[B].size() + friends[C].size() - 6;
                    if (answer == -1 || answer > sum) {
                        answer = sum;
                    }
                }
            }
        }
    }

    cout << answer << endl;
}