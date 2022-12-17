#include <bits/stdc++.h>
using namespace std; 
#define ull unsigned long long int


string dec2binary(ull x){
    string s = "";
    while(x){
        s = char(x % 2 + 48) + s;
        x /= 2;
    }
    return s;
}
//char(48) = 0
//char(49) = 1

/*
found=str.find("needles are small",found+1,6);
  if (found!=std::string::npos)
*/

bool check(string s){
    stack<char> st;
    for(ull i = 0; i < s.size(); i++){/*
        if(s[i] == '1') st.push('1');
        else if(s[i] == '0' && st.top() == '1') st.pop();
        else if(st.empty()) return false;*/
        if(!st.empty() && st.top() == '1' && s[i] == '0') st.pop();
        else st.push(s[i]);
    }
    return st.empty();
}


int main(){
    ull n;
    cin >> n;
    ull a;
    while(n--){
        cin >> a;
        /*
        stringstream ss;
        ss << decTObi(a);
        string s;
        ss >> s;
        /*
        while(!s.empty()){
            ull found = s.find("10");
            if(found==string::npos){
                cout << "NO\n";
                flag = false;
                break;
            }
            else s.erase(found, 2);
        }*/
        //if(flag) cout << "YES\n";
        check(dec2binary(a)) ? cout << "YES\n" : cout << "NO\n";
    }
    return 0;
}

