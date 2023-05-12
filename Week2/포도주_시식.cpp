#include <iostream>
#include<cstring>
#include <algorithm>

using namespace std;
int N;
int Arr[10001];
int DP[10001];


void CalcDP(){
    for (int i = 3; i <= N; i++)
    {
        DP[i] = max(DP[i - 3] + Arr[i - 1] + Arr[i], max(DP[i - 2] + Arr[i], DP[i - 1]));
    }
     
}

int main()
{
    
    memset(Arr, 0, sizeof(Arr));
    memset(DP, 0, sizeof(DP));
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> Arr[i];
    }

    DP[0] = Arr[0] = 0;
    DP[1] = Arr[1];
    DP[2] = Arr[1] + Arr[2];


    CalcDP();
    cout << DP[N] << endl;

}