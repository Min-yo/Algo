#include <bits/stdc++.h>
using namespace std;

bool isPri(int n){
    if(n == 0 || n == 1) return false;
    if(n== 2) return true;
    for(int i = 2; i < sqrt(n) + 1; i++){
        if(n % i == 0) return false;
    }
    return true;
}

int main(){
    int n, p, q;
    cin >> n;
    p = 2, q = n-2;
    while(true){
        if(isPri(p) && isPri(q)) break;
        p++, q--;
    }
    cout << p << " " << q;
    return 0;
}