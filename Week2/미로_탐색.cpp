#include <iostream>
#include <queue>
#include <utility>
#include <cstring>

using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int N, M;
int maze[100][100];
bool isVisited[100][100];

int BFS(){
    queue<pair<int, int>> q;

    q.push(make_pair(0,0));

    isVisited[0][0] = true;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if(x == N-1 && y == M-1){
            return maze[x][y]; // 최단 경로 값 반환
        }

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx >= 0 && nx < N && ny >= 0 && ny <M && maze[nx][ny] == 1 && !isVisited[nx][ny]){
                q.push(make_pair(nx, ny));
                isVisited[nx][ny] = true;
                maze[nx][ny] = maze[x][y] + 1; // 최단 경로 길이 저장
            }

        }
    }

    return -1;
}

int main(){
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            char c;
            cin >> c;
            maze[i][j] = c - '0';
        }
    }

    memset(isVisited, false, sizeof(isVisited));

    int shortestPath = BFS(); // 최단 경로 값을 저장

    cout << shortestPath << endl;

    return 0;
}
