#include<bits/stdc++.h> 
using namespace std; 
 
struct MaxHeap { 
 vector<int> heap; 
 int parent(int i) { 
  return (i - 1) / 2; 
 } 
 int left(int i) { 
  return 2 * i + 1; 
 } 
 int right(int i) { 
  return 2 * i + 2; 
 } 
 void insert(int value) { 
  this->heap.push_back(value); 
  int i = this->heap.size() - 1; 
  while (i != 0 && this->heap[parent(i)] < this->heap[i]) { 
   swap(this->heap[parent(i)], this->heap[i]); 
   i = parent(i); 
  } 
 } 
 int extractMax() { 
  if (this->heap.size() == 0) return INT_MAX; 
  if (this->heap.size() == 1) { 
   int root = this->heap[0]; 
   this->heap.pop_back(); 
   return root; 
  } 
  int root = this->heap[0]; 
  this->heap[0] = this->heap[this->heap.size() - 1]; 
  this->heap.pop_back(); 
  this->heapify(0); 
  return root; 
 } 
 void heapify(int i) { 
  int l = this->left(i); 
  int r = this->right(i); 
  int smallest = i; 
  if (l < this->heap.size() && this->heap[l] > this->heap[smallest]) 
   smallest = l; 
  if (r < this->heap.size() && this->heap[r] > this->heap[smallest]) 
   smallest = r; 
  if (smallest != i) { 
   swap(this->heap[i], this->heap[smallest]); 
   this->heapify(smallest); 
  } 
 } 
    
    void clear(){
        heap.clear();
    }
 
}; 
 
     
 
 
 
int main(){ 
    int n, m; cin >> n >> m; 
    MaxHeap heap; 
    int ar[n][m];
    for(int k = 0; k < n; k++){
        for(int l = 0; l< m; l++){
            cin >> ar[k][l];
        }
    }
    int ar1[n][m];
    for(int j = 0; j < m; j++){ 
        heap.clear();
        for (int i = 0; i < n; i++){ 
            heap.insert(ar[i][j]);
        } 
        for(int i = 0; i < n; i++){
            ar1[i][j] = heap.extractMax();
        }
    } 
    for(int k = 0; k < n; k++){
        for(int l = 0; l< m; l++){
            cout <<  ar1[k][l] << " ";
        }
        cout << endl;
    }
}