#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, a; 
    cin >> n;
    deque<int> d, dc;
    string s;
    while(n--){
        cin >> s;
        if(s[0] == 'a'){
            cin >> a;
            d.push_back(a);
        }
        else if(s[0] == 'd'){
            if(d.empty()){
                continue;
            }
            else{
                d.pop_back();
            }
        }
        else if(s[3] == 'm'){
            if(d.empty()){
                cout << "error" << endl;
            }
            else{/*
                int max = -1;
                dc = d;
                while(!dc.empty()){
                    if(max < dc.back()){
                        max = dc.back();
                    }
                    dc.pop_back();
                }*/
                int max = *max_element(d.begin(), d.end());
                cout << max << endl;
            }
        }
        else if(s[3] == 'c'){
            if(d.empty()){
                cout << "error" << endl;
            }
            else{
                cout << d.back() << endl;
            }
        }
    }
    return 0;
}