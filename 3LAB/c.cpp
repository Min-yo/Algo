#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n, q, cnt = 0;
    cin >> n >> q;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a+n);
    int l1, l2, r1, r2;
    for(int i = 0; i<q; i++){
        cin >> l1 >> r1 >> l2 >> r2;
        for(int j = 0; j < n; j++){
            if((a[j] >= l1 && a[j] <= r1) || (a[j]>=l2 && a[j]<=r2)){
                cnt++;
            }
        }
        cout << cnt << endl;
        cnt = 0;
    }
    
    return 0;
}