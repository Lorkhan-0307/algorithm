#include <iostream>

using namespace std;

int Result[100001];
int X[100001];
int L[100001];
int R[100001];

void Recursive(int n){

    if(Result[n-1] == -1){
        Recursive(n-1);
    }
    if(Result[n-1] != -1 && n != 0){
        Result[n] = (Result[n-1] + 2 * X[n-1] + R[n-1] + L[n-1])%9901;
        X[n] = Result[n-1];
        R[n] = X[n-1] + L[n-1];
        L[n] = X[n-1] + R[n-1];
    }
}


int main(){
    int n;
    cin >> n;

    std::fill(Result, Result + 100001, -1);
    std::fill(X, X + 100001, -1);
    std::fill(L, L + 100001, -1);
    std::fill(R, R + 100001, -1);


    Result[0] = 1;
    X[0] = 1;
    L[0] = 0;
    R[0] = 0;

    Recursive(n);

    cout << Result[n] % 9901 <<endl;

}