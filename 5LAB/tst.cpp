#include <iostream>
#include <vector>
using namespace std;

struct MinHeap{
    vector<int> heap;

    int parent(int i){
        return (i - 1) / 2;
    }
    int left(int i){
        return 2 * i + 1;
    }
    int right(int i){
        return 2 * i + 2;
    }

    void insert(int val){
        heap.push_back(val);
        int i = heap.size()-1;
        while( i!= 0 && heap[parent(i)] > heap[i]){
            swap(heap[parent(i)], heap[i]);
            i = parent(i);
        }
    }

    void heapify(int i){
        int l = left(i), r = right(i);
        int smallest = i;
        if(l < heap.size() && heap[l] < heap[smallest]){
            smallest = l;
        }
        if(r < heap.size() && heap[r] < heap[smallest]){
            smallest = r;
        }
        if(smallest != i){
            
        }
    

    }
    
};

















struct MaxHeap {
	vector<int> heap;

	int parent(int i) { // returns index
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
		int l = this->left(i); //indexes
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
};


