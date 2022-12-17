#include<algorithm>
#include<iostream>
#include<vector>

using namespace std;
struct MinHeap {
	vector<long long> heap;
	long long capacity;
	long long cookies = 0;

	MinHeap(unsigned long long capacity) {
		this->capacity = capacity;
	}

	int parent(int i) {
		return (i - 1) / 2;
	}
	int left(int i) {
		return 2 * i + 1;
	}
	int right(int i) {
		return 2 * i + 2;
	}

	void insertWithCheck(long long value) {
		if (heap.size() == capacity) {
			int minimal = extractMin();
			if (minimal >= value) {
				insert(minimal);
				return;
			} else {
				insert(value);
				cookies += value;
				cookies -= minimal;
			}
		} else {
			insert(value);
			cookies += value;
		}
	}
	
	void insert(long long value) {
		this->heap.push_back(value);
		int i = this->heap.size() - 1;
		while (i != 0 && this->heap[parent(i)] > this->heap[i]) {
			swap(this->heap[parent(i)], this->heap[i]);
			i = parent(i);
		}
	}
	int extractMin() {
		if (this->heap.size() == 0) return 2147483647;
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
		unsigned int l = this->left(i);
		unsigned int r = this->right(i);
		int smallest = i;
		if (l < this->heap.size() && this->heap[l] < this->heap[smallest])
			smallest = l;
		if (r < this->heap.size() && this->heap[r] < this->heap[smallest])
			smallest = r;
		if (smallest != i) {
			swap(this->heap[i], this->heap[smallest]);
			this->heapify(smallest);
		}
	}
};

int main() {
	long long n, k;
	cin >> n >> k;
	MinHeap heap(k);
	while (n--) {
		string command;
		cin >> command;
		if (command == "print") {
			cout << heap.cookies << endl;
		} else if (command == "insert") {
			long long x;
			cin >> x;
			heap.insertWithCheck(x);
		}
	}
	return 0;
}