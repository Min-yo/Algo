#include <bits/stdc++.h>
using namespace std;

double gpa(string grade){
    if(grade == "A+")
        return 4.0;
    if(grade == "A")
        return 3.75;
    if(grade == "B+")
        return 3.50;
    if(grade == "B")
        return 3.0;
    if(grade == "C+")
        return 2.50;
    if(grade == "C")
        return 2.0;
    if(grade == "D+")
        return 1.5;
    if(grade == "D")    
        return 1.0;
}
bool check(pair <pair <string, string>, double> &p1, pair <pair <string, string>, double>&p2){
    if(p1.second < p2.second)
        return true;
    if(p1.second == p2.second) { 
        if(p1.first.first < p2.first.first)
            return true;
        if(p1.first.first == p2.first.first) { 
            return p1.first.second < p2.first.second;
        }
        return false;
    }
    return false;
}

void heapify(vector <pair <pair <string, string>, double> > &heap, int size, int i){
    int biggest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if(l < size && check(heap[biggest], heap[l])) {
        biggest = l;
    }
    if(r < size && check(heap[biggest], heap[r])) {
        biggest = r;
    }
    if(i != biggest) {
        swap(heap[biggest], heap[i]);
        heapify(heap, size, biggest);
    }
}

void heapSort(vector <pair <pair <string, string>, double> > &heap){
    int size = heap.size();
    for(int i = (size - 1) / 2; i >= 0; i--) {
        heapify(heap, size, i);
    }
    for(int i = size - 1; i >= 0; i--) {
        swap(heap[0], heap[i]);
        heapify(heap,  i, 0);
    }
}

int main(){
    int n, k, count;
    cin >> n; 
    vector <pair <pair <string, string>, double> > v;
    string name, surname, grade;
    for(int i = 0; i < n; i++) {
        cin >> surname >> name >> k; 
        int cnt = 0;
        double sum = 0;
        for(int j = 0; j < k; j++) {
            cin >> grade >> count; 
            sum += gpa(grade) * count; 
            cnt += count;
        }
        v.push_back(make_pair(make_pair(surname, name), sum / cnt));
    }
    heapSort(v);
    cout << fixed << setprecision(3);
    for(int i = 0; i < n; i++){
        cout << (v[i]).first.first << " " << (v[i]).first.second << " " << (v[i]).second << endl;
    }
    return 0;
}

/*
sum += gpa(grade) * count; 
cnt += count;
*/
#include<bits/stdc++.h>
using namespace std;

/*
void merge_array(int a, int b, int c, int d, vector<int> vec) {
    vector<int> result(50);
    int i = a, j = c, k = 0;

    while (i <= b && j <= d) {
        if (vec[i].length() < vec[j].length())
            result.push_back(vec[i++]);
        else
            result.push_back(vec[j++]);
    }
    while (i <= b)
        result.push_back(vec[i++]);

    while (j <= d)
        result.push_back(vec[j++]);

    for (i = a, j = 0; i <= d; i++, j++)
        vec[i] = result[j];
}
void merge_sort(vector<int> vec, int i, int j) {
    if (i < j) {
        int m = (i + j) / 2;
        merge_sort(vec, i, m);
        merge_sort(vec, m + 1, j);
        merge_array(i, m, m + 1, j, vec);
    }
}*/
