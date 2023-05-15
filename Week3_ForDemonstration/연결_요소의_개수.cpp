#include <iostream>
#include <vector>

using namespace std;

vector<int> adj[1001]; // 인접 리스트
bool visited[1001]; // 방문 여부

// DFS 함수
void DFS(int node) {
    visited[node] = true;
    for (int i = 0; i < adj[node].size(); i++) {
        int next = adj[node][i];
        if (!visited[next]) {
            DFS(next);
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int components = 0;
    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            DFS(i);
            components++;
        }
    }

    cout << components << endl;

    return 0;
}