#include <iostream>
#include <stack>
using namespace std;
/*
bool isPri(int n){
    if (n == 1)
        return false;
    for(int i = 2; i*i < n; i++){
        if(n % i == 0)
            return false;
    }
    return true;
}*/

int main(){
    stack<int> s;
    int n, cnt = 0, flag = 1, p = 1;
    cin >> n;
    while(cnt != n){
        p++;
        if(p == 2){
            s.push(p);
            cnt++;
        }
        else{
            for(int i = 2; i < p; i++){
                if(p % i == 0){
                    flag = 0;
                    break;
                }
            }
            if(flag == 1){
                s.push(p);
                cnt++;
            }
            else{
                flag = 1;
            }
        }
    }
    cout << s.top();
    return 0;
}