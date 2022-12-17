#include<bits/stdc++.h>
using namespace std;

int summ(vector<int> v){
    int sum = 0;
    for(int i = 0; i < v.size(); i++) sum += v[i];
    return sum;
}
bool compare(vector<int> left, vector<int> right){
    return lexicographical_compare(left.begin(), left.end(), right.begin(), right.end());
}
vector<vector<int> > merge(vector<vector<int> > left, vector<vector<int> > right) {
	vector<vector<int> > result;
	int l = 0, r = 0;
	while (l < left.size() && r < right.size()) {
		if (summ(left[l]) > summ(right[r])) {
			result.push_back(left[l]);
			l++;
		}
        else if(summ(left[l]) == summ(right[r])) {
            if(compare(left[l], right[r])) {
                result.push_back(left[l]);
			    l++;
            }
            else{
                result.push_back(right[r]);
			    r++;
            }
        }
        else if(summ(left[l]) < summ(right[r])){
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

vector<vector<int> > merge_sort(vector<vector<int> > vec, int l, int r) {
	if (l == r) {
		vector<vector<int> > result;
		result.push_back(vec[l]);
		return result;
	}
	int m = l + (r - l) / 2;
	vector<vector<int> > left = merge_sort(vec, l, m);
	vector<vector<int> > right = merge_sort(vec, m + 1, r);
    return merge(left, right);
}
int main(){
    int n, m, p;
    cin >> n >> m;
    vector<vector<int> > vec, ans;
    for(int i = 0; i < n; i++){
        vector<int> tem;
        for(int j = 0; j < m; j++){
            cin >> p;
            tem.push_back(p);
        }
        vec.push_back(tem);
        tem.clear();
    }
    ans = merge_sort(vec, 0, vec.size()-1);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}