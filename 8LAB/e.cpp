#include <bits/stdc++.h>
using namespace std;

void hash_i(long long arr[], long long n) {
    for(long long i = 0; i < n; i++){long long a = arr[i];
        a /= pow(2, i);
        a += 97;
        cout << char(a);
    }
	return;
}
int main(){
    long long a, n; cin >> n;
    long long arr[n], a1[n];
    for(long long i = 0; i < n ; i++){
        cin >> arr[i];
    }
    for(long long i = n-1; i != 0; i--){
        arr[i] -= arr[i-1];
    }
    /*for(int i = 0; i < n; i++){
        cout << hash_i(arr[i], i);
    }*/
    hash_i(arr, n);
}