#include <bits/stdc++.h>
using namespace std;

void heapify(int array[], int size, int i){
    int big = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if(l < size && array[l] > array[big]) 
        big = l;
    if(r < size && array[r] > array[big]) 
        big = r;
    if(big != i){
        swap(array[big], array[i]);
        heapify(array, size, big);
    }
}

void heapSort(int array[], int size){
    for (int i = (size - 1) / 2; i >= 0; i--) {
        heapify(array, size, i);
    }
    for (int i = size - 1; i >= 0; i--) {
        swap(array[0], array[i]);
        heapify(array, i, 0);
    }
}

int main(){
    int n;
    cin >> n;
    int array[n];
    for (int i = 0; i < n; i++) {
        cin >> array[i]; 
    }
    heapSort(array, n);
    int minn = abs(array[1] - array[0]);
    for (int i = 1; i < n; i++) {
        if(minn > abs(array[i] - array[i - 1])){
            minn = abs(array[i] - array[i - 1]);
        }
    }
    for (int i = 1; i < n; i++) {
        if(abs(array[i] - array[i - 1]) == minn){
            cout << array[i - 1] << ' ' <<array[i] << ' ';
        }
    }
    return 0;
}