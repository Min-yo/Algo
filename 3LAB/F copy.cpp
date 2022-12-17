#include <bits/stdc++.h>
using namespace std;

int last_comp(vector<int> &competitors, int power) {
    if(power < competitors[0])
        return -1;

    int left = 0, right = competitors.size();

    while(left + 1 < right) {
        int midl = (left+right)/2;
        if(competitors[midl] <= power)
            left = midl;
        else
            right = midl;
    }
    return left;
}


int main() {
    int n;
    cin >> n;
    vector<int> comp(n);
    vector<int> Sum(n);

    for(int &i : comp){  
        cin >> i; 
    }

    sort(comp.begin(), comp.end()); 


    Sum[0] = comp[0];
    for(int i = 1; i < n; i++)
        Sum[i] = comp[i] + Sum[i-1];


    int t;
    cin >> t; 
    while (t--) {
        int power;
        cin >> power;
        int id = last_comp(comp, power);
        cout << (id != -1? id+1: 0) << ' ' << (id != -1 ? Sum[id]: 0) << endl; 
    }

    return 0;
}


