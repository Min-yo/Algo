#include<bits/stdc++.h>
using namespace std;

struct MaxHeap {
	vector<long long> heap;
	long long parent(long long i) {
		return (i - 1) / 2;
	}
	long long left(long long i) {
		return 2 * i + 1;
	}
	long long right(long long i) {
		return 2 * i + 2;
	}
	void insert(long long value) {
		this->heap.push_back(value);
		long long i = this->heap.size() - 1;
		while (i != 0 && this->heap[parent(i)] < this->heap[i]) {
			swap(this->heap[parent(i)], this->heap[i]);
			i = parent(i);
		}
	}
	long long extractMax() {
		if (this->heap.size() == 0) return INT_MAX;
		if (this->heap.size() == 1) {
			long long root = this->heap[0];
			this->heap.pop_back();
			return root;
		}
		long long root = this->heap[0];
		this->heap[0] = this->heap[this->heap.size() - 1];
		this->heap.pop_back();
		this->heapify(0);
		return root;
	}
	void heapify(long long i) {
		long long l = this->left(i);
		long long r = this->right(i);
		long long smallest = i;
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

int main() {
	MaxHeap heap;
	long long n, k;
	cin >> n >> k;
	while (n--) {
		long long temp;
		cin >> temp;
		heap.insert(temp);
	}
	long long sum = 0;
	while (k--) {
		long long maxi = heap.extractMax();
		sum += maxi;
		heap.insert(maxi - 1);
	}
	cout << sum;

	return 0;
}