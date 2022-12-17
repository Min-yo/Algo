#include<iostream>
#include<vector>
using namespace std;
int main(){
    struct node{
        int z;
        int x;
        int y;
        node(int a, int b, int c){
            x = a;
            y = b;
            z = c;
        }
    };
    struct heap{
        vector<node*> vec;
        void add(int a, int b, int c){
            node* n = new node(a, b, c);
            vec.push_back(n);
            upheap(vec.size()-1);
        }
        void upheap(int a){
            int b = (a-1)/2;
            if (b < 0)
                return;
            node *c;
            if (vec[a]->z < vec[b]->z){
                c = vec[a];
                vec[a] = vec[b];
                vec[b] = c;
                upheap(b);
            }
        }
        void pop(){
            if (vec.size() == 0)
                return;
            else{
                vec[0] = vec[vec.size()-1];
                vec.pop_back();
                downheap(0);
            }
        }
        void downheap(int a){
            int b, c, min = a;
            node* d;
            b = (a*2)+1;
            c = (a*2)+2;
            if (b < vec.size()){
                if (vec[min]->z > vec[b]->z){
                    min = b;
                }
            }
            if (c < vec.size()){
                if (vec[min]->z > vec[c]->z){
                    min = c;
                }
            }
            if (min != a){
                d = vec[a];
                vec[a] = vec[min];
                vec[min] = d;
                downheap(min);
            }
        }
    };
    int n, m, a, b, c, cnt = 0;
    long long sum = 0;
    heap heap;
    cin >> n >> m;
    int next[n];
    for (int i = 0; i < n; i++){
        next[i] = -1;
    }
    for (int i = 0; i < m; i++){
        cin >> a >> b >> c;
        heap.add(a, b - 1, c);
    }
    while (cnt < n - 1){
        for (int i = heap.vec[0]->x; i <= heap.vec[0]->y; i++){
            if (next[i] > -1)
                i = next[i];
            else{
                next[i] = heap.vec[0]->y;
                sum += heap.vec[0]->z;
                cnt++;
            }
        }
        heap.pop();
    }
    cout << sum << endl;
    return 0;
}