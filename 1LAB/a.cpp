#include <bits/stdc++.h>
using namespace std;

int main(){   
    int n; cin >> n;
    for(int i=0; i<n; i++){
        deque <int> d;
        int h; 
        cin >> h;
        for(int j=h; j!=0; j--){
            d.push_front(j);
            for(int c=0; c<j; c++){
                d.push_front(d.back());
                d.pop_back();
            }
        }

        deque <int>:: iterator it;
        for(it = d.begin(); it!=d.end(); it++){
            cout << *it << " ";
        }
        cout << endl;
    }
    return 0;
}