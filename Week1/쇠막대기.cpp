#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){
    string s;
    cin >> s;

    stack<int> st;
    int answer = 0;

    for(int i=0; i<s.length(); i++){
        if(s[i] == '('){
            st.push(i);
        }
        else{
            if(s[i-1] == '('){
                st.pop();
                answer += st.size();
            }
            else{
                st.pop();
                answer +=1;
            }
        }
    }

    cout << answer << endl;
    return 0;
}