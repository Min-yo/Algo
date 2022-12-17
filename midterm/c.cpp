#include <bits/stdc++.h>
using namespace std;

struct maxheap{
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
        while(i!=0 && v[parent(i)] < v[i]){
            swap(v[parent(i)], v[i]);
            i = parent(i);
        }
    }
    void heapify(int i){
        int big = i;
        if(left(i) < v.size() && v[left(i)] > v[big]) big = left(i);
        if(right(i)<v.size() && v[right(i)] > v[big]) big = right(i);
        if(i != big){
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
    void print(){
        for(int i = 0; i < v.size(); i++){
            cout << v[i] << " ";
        }
    }
    void update_value(int i, int x){
        v[--i] += x;
        while(i!=0 && v[parent(i)] < v[i]){
            swap(v[parent(i)], v[i]);
            i = parent(i);
        }
        cout << i+1 << endl;
    }
    
};

int main(){
    int n, a, x;
    cin >> n;
    maxheap heap;
    while(n--){
        cin >> a;
        heap.add(a);
    } cin >> a;
    while(a--){
        cin >> n >> x;
        heap.update_value(n, x);
    }
    
    heap.print();
    return 0;

}