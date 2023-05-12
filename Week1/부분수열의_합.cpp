#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[20];



int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    sort(arr, arr+n);

    int ans = 1;

    for (int i = 0; i < n; i++) {
        if (ans < arr[i]) {
            break;
        }
        ans += arr[i];
    }

    cout << ans << endl;

}