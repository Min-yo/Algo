#include <bits/stdc++.h> 
using namespace std; 
long long arr[555][555],arr1[555],arr2[555]; 
int main(){ 
   
    int n; 
    cin>>n; 
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            cin>>arr[i][j]; 
        }
    }
    for(int z=1;z<=n;z++){ 
        cin>>arr2[z]; 
    }
    for(int z=1;z<=n;z++){ 
        for(int i=1;i<=n;i++){ 
            for (int j=1;j<=n;j++) {
                arr[i][j]=min(arr[i][j],arr[i][arr2[z]]+arr[arr2[z]][j]);
            }
        }
        for (int i=1;i<=z;i++) {
            for (int j=1;j<=z;j++) {
                arr1[z]=max(arr[arr2[i]][arr2[j]], arr1[z]); 
            }
        }
    } 
    for (int i=1;i<=n;i++) {
        cout<<arr1[i]<<endl; 
    }
}