#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){
    stack<char> s;
    string r;
    cin >> r;
    for(int i = 0; i < r.size(); i++){
        if (s.empty()){
            s.push(r[i]);
        }
        else{ 
            if(r[i] == s.top())
                s.pop();
            else 
                s.push(r[i]);
        }
    }
    if(s.empty())
        cout << "YES";
    else
        cout << "NO";
    return 0;
}