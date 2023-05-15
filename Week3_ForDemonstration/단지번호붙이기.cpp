#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<string> grid;
vector<int> complexes;

int dfs(int x, int y) {
    int dx[] = {-1, 1, 0, 0};  // 상하좌우 이동을 위한 방향 배열
    int dy[] = {0, 0, -1, 1};
    
    int count = 1;  // 현재 집을 카운트
    
    grid[x][y] = '0';  // 현재 집을 방문 처리
    
    // 상하좌우로 연결된 집 확인
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if (nx >= 0 && nx < N && ny >= 0 && ny < N) {  // 지도 범위를 벗어나지 않는지 확인
            if (grid[nx][ny] == '1') {  // 연결된 집이 있다면
                count += dfs(nx, ny);  // 연결된 집을 방문하며 단지의 집 개수 증가
            }
        }
    }
    
    return count;
}

int main() {
    cin >> N;  // 지도의 크기 입력
    
    grid.resize(N);
    
    for (int i = 0; i < N; i++) {
        cin >> grid[i];  // 지도 정보 입력
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] == '1') {  // 집이 있다면
                int complex = dfs(i, j);  // 단지 형성 시작
                complexes.push_back(complex);  // 단지에 속하는 집의 수 추가
            }
        }
    }
    
    sort(complexes.begin(), complexes.end());  // 집의 수를 오름차순으로 정렬
    
    cout << complexes.size() << "\n";  // 총 단지수 출력
    for (int i = 0; i < complexes.size(); i++) {
        cout << complexes[i] << "\n";  // 각 단지에 속하는 집의 수 출력
    }
    
    return 0;
}
