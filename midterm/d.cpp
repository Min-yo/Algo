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

void printDivisors(int n){
    for (int i=1; i<=sqrt(n); i++){
        if (n%i == 0){
            if (n/i == i) cout <<" "<< i;
            else cout << " "<< i << " " << n/i;
        }
    }
}
 

int main(){
    int n, cnt = 0;
    cin >> n;
    /*
    for(int i = 2; i < n; i++){
        if(n % i == 0 && isPri(i)){
            cnt++;
        }
    }*/
    for (int i=1; i<=sqrt(n); i++){
        if (n%i == 0){
            if (n/i == i && isPri(i)) cnt++;
            else if (isPri(i) && isPri(n/i)) cnt += 2;
            else if(!isPri(i) && isPri(n/i)) cnt++;
            else if(isPri(i) && !isPri(n/i)) cnt++;
        }   
    }
    cout << cnt;
    return 0;
}