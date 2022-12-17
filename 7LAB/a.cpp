#include<bits/stdc++.h>
using namespace std;

bool check(pair<string, int> left, pair<string, int> right){
  return left.second <= right.second;
}

vector<pair<string, int> > merge(vector<pair<string, int> > left, vector<pair<string, int> > right) {
	vector<pair<string, int> > result;
	int l = 0, r = 0;
	while (l < left.size() && r < right.size()) {
		if (check(left[l], right[r])) {
			result.push_back(left[l]);
			l++;
		}
        else{
			result.push_back(right[r]);
			r++;
		}
	}
	while (l < left.size()) {
		result.push_back(left[l]);
		l++;
	}
	while (r < right.size()) {
		result.push_back(right[r]);
		r++;
	}
	return result;
}

vector<pair<string, int> > merge_sort(vector<pair<string, int> > vec, int l, int r) {
	if (l == r) {
		vector<pair<string, int> > result;
		result.push_back(make_pair(vec[l].first, vec[l].second));
		return result;
	}
	int m = l + (r - l) / 2;
	vector<pair<string, int> > left = merge_sort(vec, l, m);
	vector<pair<string, int> > right = merge_sort(vec, m + 1, r);
    return merge(left, right);
}

int main(){
    int n, k =0;
    cin >> n;
    //n++;
    vector<pair<string, int> > vec;
    for (int i = 0; i < n+1; i++){
        string line, str;
        getline(cin, line);  
        stringstream X(line); 
		if(i==0){
			X.str("");
			continue;
		}
        while (getline(X, str, ' ')) {  
            vec.push_back(make_pair(str, str.size()));
        }
        
        vec = merge_sort(vec, 0, (vec.size()-1));
		for(int i = 0; i < vec.size(); i++){
            cout << vec[i].first << " ";
        }
		cout << endl;
        X.str("");vec.clear();        
    }  
    return 0;
}
