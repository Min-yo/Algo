#include <iostream>
#include<vector>
using namespace std;

struct MinHeap{
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
        while(i !=0 && v[parent(i)] > v[i]){
            swap(v[parent(i)], v[i]);
            i=parent(i);
        }
    }

    void heapify(int i){
        int l = left(i), r = right(i), smallest = i;
        if(l<v.size() && v[l] < v[smallest]){
            smallest = l;
        }
        else if (r<v.size() && v[r] < v[smallest]){
            smallest = r;
        }
        else if(smallest != i){
            swap(v[smallest], v[i]);
            heapify(smallest);
        }
    }

    int extract(){
        if(v.empty()) return -1;
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
    int res(){
        int sum = 0;
        while(v.size() >1){
            int a = extract(), b = extract();
            sum += a+b;
            add(a+b);
        }
        return sum;
    }
};

int main(){
    int n, a;
    cin >> n;
    MinHeap heap;
    while(n--){
        cin >> a;
        heap.add(a);
    }
    cout << heap.res();
    return 0;
}