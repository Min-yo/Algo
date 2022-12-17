#include <bits/stdc++.h>

using namespace std;

class Graph{
    vector <list <int> > g;
    vector <int> c;
    int n;
    public:
    Graph(int n){
        this->n = n;
        this->g.resize(n);
        this->c.resize(n, false);
    }

    void add(int vec1, int vec2){
        g[vec1].push_back(vec2);
        g[vec2].push_back(vec1);
    }

    void coloring(int v){
        c[v] = 1; 
    }

    int BFS(int v){
        deque <int> dec;
        vector <bool> visited;
        int cnt = 0;
        dec.push_back(v);
        visited.resize(this->n, false);
        visited[v] = true;


        while(!dec.empty()){
            int size = dec.size();
            for(int i = 0; i < size; i++){
                int sts = dec.front();
                dec.pop_front();
                if(c[sts] == 1){
                    return cnt;
                }
                for(auto adj: g[sts]){
                    if(!visited[adj]){
                        visited[adj] = true;
                        dec.push_back(adj);
                    }
                }
            }
            cnt++;
        }
        return -1;
    }
};

int main(){
    int n, m, q, cm, v;
    cin >> n >> m >> q;
    Graph * graph = new Graph(n);
    while(m--){
        int vec1, vec2;
        cin >> vec1 >> vec2;
        vec1--; vec2--;
        graph->add(vec1, vec2);
    }
    while(q--){
        cin >> cm >> v;
        v--;
        if(cm == 1){
            graph->coloring(v);
        }
        else{
            cout << graph->BFS(v) << endl;
        }
    }
    return 0;
}