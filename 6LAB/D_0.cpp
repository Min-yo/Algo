#include<bits/stdc++.h>
using namespace std;

int make_ans(string s){
    int ans = 0;
    if(s[0] == '0'){
        return int(s[1]) - 48;
    }
    for (int i = 0; i < s.size(); i++) {
        ans += pow(10, s.size() - i - 1) * (int(s[i]) - 48);
    }
    return ans;
}

struct Date{
    int year, month, day;
    Date(string format) { 
        bool d = true;
        string string_date = "";
        for (int i = 0; i < format.size(); i++) {
            if(format[i] == '-'){
                if(d){ 
                    day = make_ans(string_date);
                    string_date = "";
                    d = false;
                }
                else{ 
                    month = make_ans(string_date);
                    string_date = "";
                }
                continue;
            }
            string_date += format[i]; 
        }
        year = make_ans(string_date); 
    }

    void print(){
        if(day < 10){ 
            if(month < 10){ 
                cout << '0' << day << '-' << '0' << month << '-' << year << endl;
                return;
            }
            cout << '0' << day << '-' << month << '-' << year << endl;
            return;
        }
        if(month < 10){
            cout << day << '-' << '0' << month << '-' << year << endl;
            return;
        }
        cout << day << '-' << month << '-' << year << endl;
    }
};

bool cmp(Date * d1, Date * d2){
    if(d1->year < d2->year) 
        return true;
    if(d1->year == d2->year) {
        if(d1->month < d2->month) 
            return true;
        if(d1->month == d2->month) { 
            return d1->day < d2->day;
        }
    }
    return false;
}

void heapify(vector <Date *> &v, int size, int i){
    int big = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if(l < size && cmp(v[big], v[l])){
        big = l;
    }
    if(r < size && cmp(v[big], v[r])){
        big = r;
    }
    if(big != i){
        swap(v[i], v[big]);
        heapify(v, size, big);
    }
}

void heapSort(vector<Date *> &v){
    for (int i = (v.size() - 1) / 2; i >= 0; i--) {
        heapify(v, v.size(), i);
    }
    for (int i = v.size() - 1; i >= 0; i--) {
        swap(v[0], v[i]);
        heapify(v, i, 0);
    }
}

int main(){
    int n;
    cin >> n;
    string s;
    vector<Date *> date; 
    for (int i = 0; i < n; i++) {
        cin >> s; 
        Date * newDate = new Date(s);
        date.push_back(newDate);
    }
    heapSort(date);
    for (int i = 0; i < n; i++){
        date[i]->print();
    }
    return 0;
}