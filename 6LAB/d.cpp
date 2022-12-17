#include <bits/stdc++.h>
using namespace std;
struct minheap{
    vector<vector<int> > v;
    int parent(int i){
        return (i-1)/2;
    }
    int left(int i){
        return 2*i +1;
    }
    int right(int i){
        return 2*i +2;
    }
    void add(vector<int> val, int t){
        v[t][0] = val[0];
        v[t][1] = val[1];
        v[t][2] = val[2];
        int i = v.size()-1;
        while(i !=0 && check(v[parent(i)], v[i])){
            swap(v[parent(i)], v[i]);
            i=parent(i);
        }
    }
    bool check(vector<int> v1, vector<int> v2){
        if(v1[2] < v2[2]){
            return true;
        }
        else if(v1[2] == v2[2] && v1[1] < v2[1]){
            return true;
        }
        else if(v1[2] == v2[2] && v1[1] == v2[1] && v1[0] < v2[0]){
            return true;
        }
        return false;
    }
    void heapify(int i, vector<vector<int> > v){
        int l = left(i), r = right(i), greatest = i;
        if(l<v.size() && check(v[greatest], v[l])){
            greatest = l;
        }
        else if (r<v.size() && check(v[greatest], v[r])){
            greatest = r;
        }
        else if(greatest != i){
            swap(v[greatest], v[i]);
            heapify(greatest, v);
        }
    }
    vector<int> extract(int i, vector<vector<int> > v){
        vector<int> ret = v[0];
        v[0] = v.back();
        v.pop_back();
        heapify(0, v);
        return ret;
    }
    void clear(){
        v.clear();
    }
};

int main(){
    int n; cin >> n;
    string s, s1, s2, s3;
    vector<int> v;
    vector<vector<int> > vv, vv1;

    for(int i = 0; i < n; i++){
        cin >> s;
        s1 = s[0]; s1 += s[1];
        s2 = s[3]; s2 += s[4];
        s3 = s[6]; s3 += s[7]; s3 += s[8]; s3 += s[9];
        stringstream ss1 ,ss2, ss3;
        int n1, n2, n3;
        ss1<< s1; ss1>> n1; ss2<<s2; ss2>> n2; ss3<< s3; ss3>>n3;
        v[0] = n1;
        v[1] = n2;
        v[2] = n3;
        vv.push_back(v);
    }
    
    
    
    minheap heap;
    cout<<vv[0][1];
    for(int i = 0; i < n; i ++){
        heap.add(vv[i], i);
    }/*
    for(int i  =0 ; i < n; i++){
        vv1[i] = heap.extract(i, vv);
    }
    for(int i = 0; i< n; i++){
        for(int j = 0; j < 3; j++){
            if(vv1[i][0] < 10){
                if(vv1[i][1] < 10){
                    cout << '0' << vv1[i][0] << '-' << '0' << vv1[i][1] << '-' << vv1[i][2] << endl;
                    continue;
                }
                cout << '0' << vv1[i][0] << '-' << vv1[i][1] << '-' << vv1[i][2] << endl;
                continue;
            }
            if(vv1[i][1] < 10){
                cout << vv1[i][0] << '-' << '0' << vv1[i][1] << '-' << vv1[i][2] << endl;
                continue;
            }
            cout << vv1[i][0] << '-' << vv1[i][1] << '-' << vv1[i][2] << endl;
            continue;
        }
    }*/
}