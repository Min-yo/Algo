#include <iostream>
#include<vector>
#include<cmath>
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
		if (this->heap.size() == 0) return 0;
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
/*
    int res(){
        while(heap.size() != 1){
            int a = extractMax(), b = extractMax();
            if(a == b) continue;
            else if (a != b) insert(abs(a-b));
            
        }
        return extractMax();
    }*/
    void change(int i, int val){
        heap[i] += val;
        this->heapify(0);
        for(int j = 0; j < heap.size(); j++){
            cout << heap[j] << " ";
        } 
    }/*
    void _inorder(Node* node) {
		if (!node) return;
		_inorder(node->left);
		cout << node->val << " ";
		_inorder(node->right);
	}*/
/*
    int size(){
        return v.size();
    }
    int val(int i){
        return heap[i];
    }*/
};

    


int main(){
    int n, a, m, x1, x2;
    cin >> n;
    MaxHeap heap;
    while(n--){
        cin >> a;
        heap.insert(a);
    }
    cin >> m;
    while(m--){
        cin >> x1 >> x2;
        heap.change(x1, x2);
    }
    return 0;
}