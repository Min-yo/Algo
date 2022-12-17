#include<bits/stdc++.h>
using namespace std;

int main(){
    int a, b;
    cin >> a >> b;
    vector <int> vec;
    vec.resize(2 * max(a, b) + 1, -1);
    deque <int> dec, ans;
    vec[a] = 0;
    dec.push_back(a);
    while(!dec.empty()){
        int frnt = dec.front();
        dec.pop_front();
        if(frnt == b) break;
        if(frnt < b){
            int temp = 2*frnt;
            if(vec[temp] == -1 || vec[temp] > vec[frnt] + 1){
                vec[temp] = vec[frnt] + 1;
                dec.push_back(temp);
            }
        }int temp = frnt-1;
        if(frnt !=0 && (vec[temp] == -1 || vec[temp] > vec[frnt] + 1)){
            vec[temp] = vec[frnt] + 1;
            dec.push_back(temp);
        }
    }
    ans.push_front(b);
    while(ans.front() != a){
        if(vec[ans.front() + 1] + 1 == vec[ans.front()]){
            ans.push_front(ans.front() + 1);
        }
        else if(ans.front() % 2 == 0){
            ans.push_front(ans.front() / 2);
        }
    }
    if(ans.size() == 0){
        cout << 0;
        return 0;
    }
    ans.pop_front();
    cout << ans.size() << endl;
    while(!ans.empty()){
        cout << ans.front() << ' ';
        ans.pop_front();
    }
    return 0;
}