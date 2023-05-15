#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N;
vector<int> inDegree;
vector<int> jobMatrix[10002];
vector<int> jobTime;
vector<int> totalJobTime;
bool isVisited[10002];
int answer = 0;

void Topology_Sort() {
    queue<int> jobQueue;

    for (int cur = 1; cur <= N; cur++) {
        if (inDegree[cur] == 0)
            jobQueue.push(cur);
    }

    while (!jobQueue.empty()) {
        int cur = jobQueue.front();
        isVisited[cur] = true;
        jobQueue.pop();
        totalJobTime[cur] = max(totalJobTime[cur], jobTime[cur]);

        for (int j = 0; j < jobMatrix[cur].size(); j++) {
            int next = jobMatrix[cur][j];
            inDegree[next] -= 1;
            totalJobTime[next] = max(totalJobTime[next], totalJobTime[cur] + jobTime[next]);

            if (inDegree[next] == 0)
                jobQueue.push(next);
        }
    }

    for(int i=1; i<=N; i++){
        if(!isVisited[i]){
            jobQueue.push(i);
            cout << "pushing" << i << endl;
            Topology_Sort();
        }
    }
}

int main() {
    cin >> N;

    inDegree.resize(N + 1, 0);
    jobTime.resize(N + 1);
    totalJobTime.resize(N + 1, 0);

    for (int i = 1; i <= N; i++) {
        cin >> jobTime[i];

        int linkNum;
        cin >> linkNum;

        for (int j = 0; j < linkNum; j++) {
            int preBuild;
            cin >> preBuild;
            jobMatrix[preBuild].push_back(i);
            inDegree[i]++;
        }
    }

    Topology_Sort();

    for(int i=1; i<=N; i++){
        answer = max(answer, totalJobTime[i]);
    }

    cout << answer << endl;

    return 0;
}
