#include<bits/stdc++.h>
using namespace std;

void print(deque<int> q, bool flag){
    while(!q.empty()){
        flag ? cout << q.front() << " " : cout << q.back() << " ";
        flag ? q.pop_front() : q.pop_back();
    }
    return;
}

int main(){
    int q, a, b;
    bool flag = true;
    cin >> q;
    deque<int> que;
    while(q--){
        cin >> a;
        if(a == 1){
            cin >> b;
            if(flag) que.push_back(b);
            if(!flag) que.push_front(b);
        }
        else{
            flag = !flag;
        }
    }
    print(que, flag);
    return 0;
}