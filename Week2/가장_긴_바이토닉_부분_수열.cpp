#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<int> increasingDP(N, 1); 
    vector<int> decreasingDP(N, 1); 


    for (int i = 1; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (A[i] > A[j]) {
                increasingDP[i] = max(increasingDP[i], increasingDP[j] + 1);
            }
        }
    }


    for (int i = N - 2; i >= 0; i--) {
        for (int j = N - 1; j > i; j--) {
            if (A[i] > A[j]) {
                decreasingDP[i] = max(decreasingDP[i], decreasingDP[j] + 1);
            }
        }
    }

    int longestBitonic = 0;
    for (int i = 0; i < N; i++) {
        longestBitonic = max(longestBitonic, increasingDP[i] + decreasingDP[i] - 1);
    }

    cout << longestBitonic << endl;

    return 0;
}
