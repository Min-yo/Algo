#include <bits/stdc++.h>
using namespace std; 

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

void printArray(vector<int> array, int size) {
  for (int i = 0; i < size; i++) {
    cout << array[i] << " ";}
  cout << endl;
}

int partition(vector<int> array, int low, int high) {
  int pivot = array[high];
  int i = (low - 1);
  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {
      i++;
      swap(&array[i], &array[j]);
    }
  }
  swap(&array[i + 1], &array[high]);
  return (i + 1);
}

void quickSort(vector<int> array, int low, int high) {
  if (low < high) {
    int pi = partition(array, low, high);
    quickSort(array, low, pi - 1);
    quickSort(array, pi + 1, high);
  }
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> v1(n), v2(m);
    for(int i = 0; i < n; i++){
        cin >> v1[i];
    }
    for(int i = 0; i < m; i++){
        cin >> v2[i];
    }
    quickSort(v1, 0, n-1), quickSort(v2, 0 , m-1);
    int k = 0;
    vector<int>v;
    for(int i = 0; i < v1.size(); i++){
        for(int j = 0; j < v2.size(); j++){
            if(v1[i]==v2[j]){
                v.push_back(v1[i]);
                v1.erase(v1.begin()+ i);
                v2.erase(v2.begin()+ j);
                i--, j--, k++;
            }
        }
    }
    //quickSort(v, 0, k);
    sort(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    return 0;
}