#include<bits/stdc++.h>
using namespace std;


int main(){
    int k, n, a;
    cin >> k >> n;
    vector<int> ar;
    for(int i = 0; i < n; i++){
        cin >> a;
        ar.push_back(a);
    }
    sort(ar.begin(), ar.end());/*
    for(int i = 0; i < n-1; i++){
        for(int j = n-1; j > 0; j--){
            if(i < j && ar[i]+ar[j] == k){
                cout << ar[i] << " " << ar[j];
                return 0;
            }
        }
    }*/
    for(int i = 0; i < n; i++){
        int l = i, r = n;
        while(l <= r){
            int mid = l+(r-l)/2;
            if(ar[i]+ar[mid] == k){
                cout << ar[i] << " " << ar[mid];
                return 0;
            }
            else if(ar[i]+ar[mid] < k) l = mid+1;
            else r = mid-1;
        }
    }
}