#include<iostream>
#include<deque>
using namespace std;

int main(){
    char c;
    int n;
    deque<int> d;
    deque<int> d2;

    while(c != '!'){
        
        cin >> c;
    
        if(c == '*'){
            if(d.empty()){
                cout << "error\n";
            }
            else{
                cout << (d.front()+d.back()) << endl;
                if(d.size() == 1){
                    d.pop_back();
                }
                else{
                    d.pop_back();
                    d.pop_front();
                }
            }
        }
        else if(c == '+'){
            cin >> n;
            d.push_front(n);
        }
        else if(c == '-'){
            cin >> n;
            d.push_back(n);
        }

    }
    return 0;
}