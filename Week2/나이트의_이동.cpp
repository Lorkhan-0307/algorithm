#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 300;

int caseNum;
int length;

int board[MAX][MAX];
bool isVisited[MAX][MAX];
int startX, startY;
int targetX, targetY;

int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[] = {2, 1, -1, -2, -2, -1, 1, 2};

int BFS(){
    queue<pair<int, int>> q;

    q.push(make_pair(startX, startY));

    isVisited[startX][startY] = true;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if(x == targetX && y == targetY){
            return board[x][y]; // 최단 경로 값 반환
        }

        for(int i=0; i<8; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx >= 0 && nx < length && ny >= 0 && ny < length && !isVisited[nx][ny]){
                q.push(make_pair(nx, ny));
                isVisited[nx][ny] = true;
                board[nx][ny] = board[x][y] + 1; // 최단 경로 길이 저장
            }

        }
    }
    return -1;
}


void Calc(){
    cin >> length;
    cin >> startX >> startY;
    cin >> targetX >> targetY;
    

    for(int i=0; i<length; i++){
        for(int j=0; j<length; j++){
            board[i][j] = 0;
            isVisited[i][j] = false;
        }
    }

    cout << BFS() << endl;
}
 

 int main(){
    cin >> caseNum;

    for(int i=0; i<caseNum; i++){
        Calc();
    }
}