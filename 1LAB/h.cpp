#include <iostream>
#include <stack>
using namespace std;

bool isPri(int n){
    if (n == 1)
        return false;
    for(int i = 2; i*i < n; i++){
        if(n % i == 0)
            return false;
    }
    return true;
}

int main(){
    stack<int> s;
    int n;
    cin >> n;
    s.push(n);
    if(isPri(s.top()))
        cout << "YES";
    else
        cout << "NO";
    return 0;

}