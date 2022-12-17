#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, a;
    cin >> n;
    deque<int> deq;
    for(int i = 0; i < n; i++){
        cin >> a;
        deq.push_back(a);
        if(a >= 3000){
            while(deq.front() < a-3000) deq.pop_front();
        }
        cout << deq.size() << " ";
    }
}