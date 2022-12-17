#include <bits/stdc++.h>
using namespace std;

vector<int> merge(vector<int> left, vector<int> right) {
	vector<int> result;
	int l = 0, r = 0;
	while (l < left.size() && r < right.size()) {
		if (left[l] <= right[r]) {
			result.push_back(left[l]);
			l++;
		} else {
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

vector<int> merge_sort(vector<int> a, int l, int r) {
	if (l == r) {
		vector<int> result;
		result.push_back(a[l]);
		return result;
	}
	int m = l + (r - l) / 2;
	vector<int> left = merge_sort(a, l, m);
	vector<int> right = merge_sort(a, m + 1, r);
	return merge(left, right);
}

int main(){
    int n, m;
    cin >> n >> m;
    
    vector<int> vec1, vec2, ans;
    for(int i = 0; i < n; i++){
        int ans; cin >> ans;
        vec1.push_back(ans);
    }
    for(int i = 0; i < m; i++){
        int x; cin >> x;
        vec2.push_back(x);
    }if(n ==0 || m == 0) return 0;
    //vec1=merge_sort(vec1, 0, n-1);
    //vec2=merge_sort(vec2, 0, m-1);
    for(int i = 0; i < vec1.size(); i++){
        for(int j = 0; j < vec2.size(); j++){
            if(vec1[i] == vec2[j]){
                ans.push_back(vec1[i]);
                vec1.erase(vec1.begin() + i);
                vec2.erase(vec2.begin() + j);
                i--; j--;
            }
        }
    }
    ans=merge_sort(ans, 0, ans.size()-1);
    sort(ans.begin(), ans.end());
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    return 0;
}
