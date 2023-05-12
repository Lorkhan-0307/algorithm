#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int n;
int path[10][10];
bool isVisited[10];

int dfs(int startPos, int currentPos, int cnt, int cost){
    if(cnt == n){
        if(path[currentPos][startPos] == 0){
            return 99999999;
        }
        return cost + path[currentPos][startPos];
    }

    int ret = 99999999;

    for(int i=0; i<n; i++){
        if(!isVisited[i] && path[currentPos][i] != 0){
            isVisited[i] = true;
            ret = min(ret, dfs(startPos, i, cnt +1, cost + path[currentPos][i]));
            isVisited[i] = false;
        }
    }

    return ret;
}



int main(){
    cin >> n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> path[i][j];
        }
    }

    int answer = 99999999;

    for(int i=0; i<n; i++){
        isVisited[i] = true;
        answer = min(answer, dfs(i, i, 1, 0));
        isVisited[i] = false;
    }

    cout << answer << endl;

    return 0;
}