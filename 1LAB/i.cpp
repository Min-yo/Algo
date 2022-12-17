#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main(){
    deque<int> d_1, d_2;
    int n;
    string s;
    cin >> n >> s;
    for(int i = 0; i < s.size(); i++){
        if (s[i] == 'S')
            d_1.push_back(i);
        else
            d_2.push_back(i);
        
    }
    while(!d_1.empty() && !d_2.empty()){
        int i = d_1.front(); //S
        int j = d_2.front(); //K
        if (i < j){
            d_2.pop_front();
            d_1.push_back(i + s.size());
            d_1.pop_front();

        }
        else {
            d_1.pop_front();
            d_2.push_back(j + s.size());
            d_2.pop_front();
        }
    }
    if(d_1.empty())
        cout << "KATSURAGI";
    else
        cout << "SAKAYANAGI";
    return 0;
}