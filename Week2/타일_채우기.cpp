#include <iostream>
 
#define endl "\n"
#define MAX 35
using namespace std;
 
int N;
int DP[MAX];
 
void Calc()
{
    if (N % 2 == 1)
    {
        cout << 0 << endl;
        return;
    }
    DP[0] = 1;
    DP[1] = 0;
    DP[2] = 3;
    for (int i = 4; i <= N; i = i + 2)
    {
        DP[i] = DP[i - 2] * DP[2];
        for (int j = i - 4; j >= 0; j = j - 2)
        {
            DP[i] = DP[i] + (DP[j] * 2);
        }
    }
    cout << DP[N] << endl;
}

 
int main(void)
{
    
    cin >> N;


    // F[8] = ( F[6] * F[2] ) + ( F[4] * 2 ) + ( F[2] * 2 ) + ( F[0] * 2 )
    // F[N] = ( F[N - 2] * F[2] ) + ( F[N - 4] * 2 ) + ( F[N - 6] * 2) + ( F[N - 8] * 2 ) + ... + ( F[0] * 2 )

    Calc();
    return 0;
}
