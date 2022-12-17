#include <bits/stdc++.h>
using namespace std;

int main(){
    priority_queue<int, vector<int>, greater <int> > q;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        int a;
        cin >> a;
        q.push(a);
    }

    int cnt = 0;
    while(q.size() > 1){
        int d_min = q.top();
        if (d_min >= m){
            break; 
        }
        q.pop();
        int d_min1 = q.top();
        q.pop();
        q.push(d_min + 2 * d_min1);
        cnt++;
    }
    if (q.top() >= m){
        cout << cnt;
    }
    else{
        cout << "-1";
    }
    return 0;
}