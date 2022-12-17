#include <bits/stdc++.h>
using namespace std;

int main(){
    int arr[100][100];
    int n, start, end;
    vector <int> visited;
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }
    visited.assign(n, -1);
    cin >> start >> end;
    start--; end--;
    visited[start] = 0;
    deque <int> deq;
    deq.push_back(start);
    while(!deq.empty()){
        int sts = deq.front();
        deq.pop_front();
        for(int i = 0; i < n; i++){
            if(arr[i][sts] == 1 && visited[i] == -1){
                visited[i] = visited[sts] + 1;
                deq.push_back(i);
                if(i == end){
                    cout << visited[i];
                    return 0;
                }
            }
        }
        
    }
    cout << -1;
    return 0;
}