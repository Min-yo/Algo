#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int main(){
    int n, m, a, b, cnt;
    cin >> n >> m;
    cnt = n;
    vector<int> arr[n];
    vector<int> v;
    queue<int> q;
    bool ifv[n];
    int num[n];
    for (int i = 0; i < n; i++){
        ifv[i]=true;
        num[i]=0;
    }
    for (int i = 0; i < m; i++){
        cin >> a >> b;
        arr[a-1].push_back(b-1);
        ifv[b-1] = false;
        num[b-1]++;
    }
    for (int i = 0; i < n; i++){
        if (ifv[i]){
            v.push_back(i + 1);
            cnt--;
            if (cnt == 0){
                cout << "Possible\n";
                for (int i = 0; i < v.size(); i++){
                    cout << v[i] << " ";
                }
                cout << endl;
                return 0;
            }
            q.push(i);
            while(!q.empty()){
                a = q.front();
                for (int j = 0; j < arr[a].size(); j++){
                    if (num[arr[a][j]] > 0){
                        num[arr[a][j]]--;
                        if (num[arr[a][j]]==0){
                            cnt--;
                            v.push_back(arr[a][j]+1);
                            if (cnt == 0){
                                cout << "Possible\n";
                                for (int i = 0; i < v.size(); i++){
                                    cout << v[i] << " ";
                                }
                                cout << endl;
                                return 0;
                            }
                            q.push(arr[a][j]);
                        }
                    }
                }
                q.pop();
            }
        }
    }
    cout << "Impossible\n";
    return 0;
}