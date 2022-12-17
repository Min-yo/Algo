#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    stack<int> s;
    vector<int> v;

    for (int i = 0; i < n; i++){
        int a;
        cin >> a;
        v.push_back(a);
    }

    for (int i = 0; i < v.size(); i++){
        if(!s.empty()){
            while(!s.empty() && s.top() > v[i]){
                s.pop();
            }
        }
        if(s.empty()){
            cout<< "-1";
        }
        else{
            cout<< s.top();
        }
        cout<<" ";
        s.push(v[i]);
    }
}
