#include <bits/stdc++.h>
using namespace std;

struct minheap{
    vector<char> v;
    int parent(int i){
        return (i-1)/2;
    }
    int left(int i){
        return 2*i +1;
    }
    int right(int i){
        return 2*i +2;
    }

    void add(char val){
        v.push_back(val);
        int i = v.size()-1;
        while(i != 0 && v[parent(i)] > v[i]){
            swap(v[parent(i)], v[i]);
            i = parent(i);
        }
    }
    
    void heapify(int i){
        int l = left(i), r = right(i), small = i;
        if(l < v.size() && v[l] < v[small]) small = l;
        if(r < v.size() && v[r] < v[small]) small = r;
        if(i != small) {
            swap(v[small], v[i]);
            heapify(small);
        }
    }

    char extract(){
        if(v.empty()) return 0;
        if(v.size() == 1) {
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
        while(!v.empty()){
            cout << extract();
        }
    }
};

int main(){
    minheap heap1, heap2;
    int n;
    char a;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a;
        if(a == 'a' || a == 'o' || a == 'e' || a == 'i' || a == 'u') {
            heap1.add(a);
        }
        else{
            heap2.add(a);
        }
    }
    heap1.print(), heap2.print();
    return 0;
}