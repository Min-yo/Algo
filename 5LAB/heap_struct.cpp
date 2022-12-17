#include <iostream>
#include <vector>

using namespace std;

struct MinHeap{
    vector <int> heap;

    int left(int i){
        return 2*i +1;
    }

    int right(int i){
        return 2*i +2;
    }

    int parent(int i){
        return (i-1)/2;
    }

    void add(int val){
        heap.push_back(val);
        int i = heap.size()-1;
        while(i!=0 && heap[parent(i)] > heap[i]){ // while smaller than parent
            swap(heap[parent(i)], heap[i]);
            i = parent(i);
        }
    }


    void heapify(int i){
        int l = left(i), r = right(i), smallest = i;
        if(l < heap.size() && heap[l] < heap[smallest]){
            smallest = l;
        }
        if(r < heap.size() && heap[r] < heap[smallest]){
            smallest = r;
        }
        if(smalelst != i){
            swap(heap[i], heap[smallest]);
            heapify(smallest); // check children of smallest index
        }

    }
};