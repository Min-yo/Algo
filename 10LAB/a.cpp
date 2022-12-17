#include<bits/stdc++.h>
using namespace std;
int n, m, mushrooms = 0;
int arr[1000][1000];
queue<pair<int, int> > mario_pos;
void checkAdj(int x, int y){
    if(x - 1 >= 0 && arr[x - 1][y] == 1){
        arr[x - 1][y] = 2;
        mario_pos.push(make_pair(x - 1, y));
        mushrooms--;
    }
    if(x + 1 < n && arr[x + 1][y] == 1){
        arr[x + 1][y] = 2;
        mario_pos.push(make_pair(x + 1, y));
        mushrooms--;
    }
    if(y - 1 >= 0 && arr[x][y - 1] == 1){
        arr[x][y - 1] = 2;
        mario_pos.push(make_pair(x, y - 1));
        mushrooms--;
    }
    if(y + 1 < m && arr[x][y + 1] == 1){
        arr[x][y + 1] = 2;
        mario_pos.push(make_pair(x, y + 1));
        mushrooms--;
    }
}

int main() {int time = 0;
	cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 2) mario_pos.push(make_pair(i, j));
            if(arr[i][j] == 1) mushrooms++;
        }
    }
    while(!mario_pos.empty()){
        if(!mushrooms) break;
        int size = mario_pos.size();
        while(size--){
            int x = mario_pos.front().first;
            int y = mario_pos.front().second;
            mario_pos.pop();
            checkAdj(x, y);
        }
        if(!mario_pos.empty()){
            time++;
        }
    }
    cout << (!mushrooms ? time : -1);
	return 0;
}