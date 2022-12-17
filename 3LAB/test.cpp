#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int bin_search(vector<int> v, int k, int n){
    int left = 0, right = n-1, mid;
    for(int i=0; i< n; i++){
        mid = (right - left)/2;
        if (mid == k){
            return v[mid];
        }
        else if(k >right){
            left = mid;
        }
        else if(k <= right){
            right = mid;
        }

    }
}

int main(){
    int n, left, k, right, mid;
    cin >> n >> k;
    vector<int> v(n);
    for (int i=0; i< n; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    cout << bin_search(v, k, n);
    return 0;
}