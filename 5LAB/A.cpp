#include <bits/stdc++.h>

using namespace std;

void heapify(long long ar[], long long n, long long i) {
    long long larg = i; 

    long long right = 2 * i + 2; 
    long long left = 2 * i + 1;
    

    if (left < n && ar[left] > ar[larg]) 
        larg = left;
 
    if (right < n && ar[right] > ar[larg])
        larg = right;
 
    if (larg != i) { 
        swap(ar[i], ar[larg]);
        heapify(ar, n, larg);
    }
}


void heapify2(long long ar[], long long n, long long i) {
    long long minimum2 = i; 
    long long left2 = 2 * i + 1;  
    long long right2 = 2 * i + 2;

    if (left2 < n && ar[left2] < ar[minimum2]) 
        minimum2 = left2;
 
    if (right2 < n && ar[right2] < ar[minimum2]) 
        minimum2 = right2;
 
    if (minimum2 != i) { 
        swap(ar[i], ar[minimum2]);
        heapify2(ar, n, minimum2);
    }
}



void heapSort(long long ar[], long long n){
    for (long long i = n / 2 - 1; i >= 0; i--)
        heapify(ar, n, i);
 
    for (long long i = n - 1; i >= 0; i--) {
        swap(ar[0], ar[i]);
        heapify(ar, i, 0);
    }
}
 

int main(){
    long long n;
    cin>>n;
    long long ar[n]; 
    for(long long i = 0; i < n; i++){
        cin >> ar[i]; 
    }
    heapSort(ar,n);
    
    long long answer = 0; 
    long long size = n;
    long long temp = 0;

    for(long long i = 0;i < n-1; i++){
        long long temp = 0;

        temp = ar[0];
        ar[0] = 0;
        size--;

        swap(ar[0], ar[size]);
        heapify2(ar, size, 0);
        
        ar[0] += temp;
        answer += ar[0];
        heapify2(ar, size, 0);
    }

    cout << answer;
}