#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){
    stack<char> s,c;
    char a;
    string r, e;
    cin >> r >> e;
    
    for(int i = 0; i < r.size(); i++){
        if(r[i] != '#'){
            s.push(r[i]);
        }
        else 
            s.pop();
    }
    for(int i = 0; i < e.size(); i++){
        if(e[i] != '#'){
            c.push(e[i]);
        }
        else 
            c.pop();
    }
    if (c == s)
        cout << "Yes";
    else
        cout << "No";
    return 0;
}