#include<iostream>
#include<stack>
using namespace std;

int main(){
    int n;
    cin >> n;
    stack<int> st;
    int index = 1, prime = 2, flag = 1;
    int cnt = 0;

    while(cnt != n){
        prime++;

        for(int i = 2; i <= prime / 2; i++){
            if(prime % i == 0){
                flag = 0;
                break;
            }
        }
        
        if (flag == 1) {
            index++;
            if (index == 2) {
                cnt++;
                st.push(prime);
            } 
            else {
                for (int i = 2; i <= index / 2; i++) {
                    if (index % i == 0) {
                        flag = 0;
                        break;
                    }
                }
                if (flag == 1) {
                    cnt ++;
                    st.push(prime);
                } 
                else {
                    flag = 1;
                }
            }
        } 
        else {
            flag = 1;                          
        }
    }
        cout << st.top();
        return 0;
}
