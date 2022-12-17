#include <bits/stdc++.h>
using namespace std;

struct maxheap{
    vector<int> v;
    int parent(int i){
        return (i-1)/2;
    }
    int left(int i) {
        return 2*i +1;
    }
    int right(int i) {
        return 2*i +2;
    }
    void add(int val){
        v.push_back(val);
        int i = v.size()-1;
        while(i != 0 && v[parent(i)] < v[i]){
            swap(v[parent(i)], v[i]);
            i = parent(i);
        }
    }
    void heapify(int i){
        int l = left(i), r = right(i), big = i;
        if(l < v.size() && v[big] < v[l]) big = l;
        else if(r < v.size() && v[big] < v[r]) big = r;
        else if(big != i){
            swap(v[big], v[i]);
            heapify(big);
        }
    }
    int extract(){
        if(v.empty()) return INT_MAX;
        else if(v.size() == 1){
            int ans = v[0];
            v.pop_back();
            return ans;
        }
        int ans = v[0];
        v[0] = v.back();
        v.pop_back();
        heapify(0);
        return ans;
    }
    int inorder(){
        int t = v.size(), cnt = 0;
        for(int i = 0; i < t; i++){
            if(left(i) < t && right(i) < t && v[left(i)] < v[right(i)]) cnt++;
        }
        return cnt;
    }
};


int main(){
    int n, a;
    cin >> n;
    maxheap heap;
    while(n--){
        cin >> a;
        heap.add(a);
    }
    cout << heap.inorder();
}