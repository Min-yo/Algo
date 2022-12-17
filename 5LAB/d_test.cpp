#include<iostream>
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
        while(i != 0 && v[parent(i)] > v[i]){
            swap(v[parent(i)], v[i]);
            i = parent(i);
        }
    }
    void heapify(int i){
        int l = left(i), r = right(i), smallest = i;
        if(l < v.size() && v[l] < v[smallest]){
            smallest = l;
        }
        else if(r < v.size() && v[r] < v[smallest]){
            smallest = r;
        }
        if(smallest !=i){
            swap(v[smallest] , v[i]);
            heapify(0);
        }
    }

    int extract(){
        if(v.empty()) return 0;
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
    int size(){
        return v.size();
    }
    int val(int i){
        return v[i];
    }
};

int main(){
    int n, m, a, cnt = 0;
    cin >> n >> m;
    MinHeap h;
    while(n--){
        cin >> a;
        h.add(a);
    }
    while (h.size() >1){
        int x1 = h.extract(), x2 = h.extract();
        if(x1 >=m && x2 >=m && cnt == 0){
            cout << 0;
            return 0;
        }
        else if(x1 >=m && x2 >=m){
            cout << cnt;
            return 0;
        }
        h.add(x1 + 2*x2);
        cnt++;
        //cout << cnt << " ";
        
    }
    cout << -1;
    return 0;
}