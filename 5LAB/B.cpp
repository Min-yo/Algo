#include <iostream>

using namespace std;

void heapify(int ar[], int n, int i) {
    int larg = i; 

    int right = 2 * i + 2; 
    int left = 2 * i + 1;
    

    if (left < n && ar[left] > ar[larg]) 
        larg = left;
 
    if (right < n && ar[right] > ar[larg]) 
        larg = right;
 
    if (larg != i) { 
        swap(ar[i], ar[larg]);
        heapify(ar, n, larg);
    }
}


void heapSort(int ar[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(ar, n, i);
 
    for (int i = n - 1; i >= 0; i--) {
        swap(ar[0], ar[i]);
        heapify(ar, i, 0);
    }
}
 
  

int main() {
    int n;
    cin >> n;
    int ar[n]; 
    for(int i = 0; i < n; i++){
        cin >> ar[i]; 
    }

    heapSort(ar, n);  

    for(int i = n-1; i >= 1; i--){
        ar[i-1] = abs (ar[i-1] - ar[i]); 
        heapSort(ar, i); 
    }
    cout << ar[0]; 
}
