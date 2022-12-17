#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main(){
    int a, x, c;
    deque<int> d, s;
    for(int i = 0; i < 5; i++){
        cin >> a;
        d.push_back(a);
    }
    for(int i = 0; i < 5; i++){
        cin >> a;
        s.push_back(a);
    }
    int cnt = 0;
    while(cnt != 1000000){
        x = d.front();
        c = s.front();
        if(x == 0 && c == 9){
            d.pop_front();
            s.pop_front();
            d.push_back(x);
            d.push_back(c);
        }
        else if(c == 0 && x == 9){
            d.pop_front();
            s.pop_front();
            s.push_back(x);
            s.push_back(c);
        }
        else if (x>c){
            d.pop_front();
            s.pop_front();
            d.push_back(x);
            d.push_back(c); 
        }
        else if (c>x){
            d.pop_front();
            s.pop_front();
            s.push_back(x);
            s.push_back(c);
        }
        cnt++;
        if(cnt == 1000000){
            cout << "blin nichya";
            break;
        }
        if(d.empty()){
            cout << "Nursik " << cnt;
            break;
        }
        if(s.empty()){
            cout << "Boris " << cnt;
            break;
        }
    }
    return 0;
}