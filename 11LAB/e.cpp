#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int main(){
    int n, m, a, b, ans = 1, minyo, cnt_1;
    cin >> n >> m;
    int v[n];
    int temp = n-1;
    v[temp] = 0;
    v[--temp] = 1;
    vector<int> ar[n];
    int pr[n];
    for (int i = 0; i < m; i++){
        cin >> a >> b;
        ar[min(a,b)-1].push_back(max(a,b)-1);
    }
    for (int i = 0; i < n; i++){
        pr[i] = -1;
    }
    for (int i = temp; i > 0; i--){
        cnt_1 = -1;
        for (int j = 0; j < ar[i].size(); j++){
            minyo = ar[i][j];
            while(pr[minyo] > -1){
                minyo = pr[minyo];
            }
            pr[ar[i][j]] = minyo;
            if (minyo != i){
                pr[minyo] = i;
                cnt_1++;
            }
        }
        ans -= cnt_1;
        v[i-1] = ans;
    }
    for (int i = 0; i < n; i++){
        cout << v[i] << endl;
    }
    return 0;
}