#include <iostream>
#include<vector>
using namespace std;

struct MaxHeap{
    vector<int> v;

    int parent(int i){
        return (i-1)/2;
    }
    int left(int i){
        return 2*i +1;
    }
    int right(int i){
        return 2*i +2;
    }

    void add(int val){
        v.push_back(val);
        int i = v.size()-1;
        while(i !=0 && v[parent(i)] < v[i]){
            swap(v[parent(i)], v[i]);
            i=parent(i);
        }
    }

    void heapify(int i){
        int l = left(i), r = right(i), greatest = i;
        if(l<v.size() && v[l] > v[greatest]){
            greatest = l;
        }
        else if (r<v.size() && v[r] > v[greatest]){
            greatest = r;
        }
        else if(greatest != i){
            swap(v[greatest], v[i]);
            heapify(greatest);
        }
    }

    int extractMax(){
        if(v.empty()) return INT_MAX;
        else if(v.size() == 1) {
            int ans = v[0];
            v.pop_back();
            return ans;
        }
        int ret = v[0];
        v[0] = v.back();
        v.pop_back();
        heapify(0);
        return ret;
    }
};
