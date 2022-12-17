#include <bits/stdc++.h>

using namespace std;

double getGpa(vector<pair<string, int> > w){
    double cnt = 0, summ = 0;
    for(int i = 0; i < w.size(); i++){
        if (w[i].first == "A+") summ+= w[i].second * 4;
        else if (w[i].first == "A") summ+= w[i].second * 3.75;
        else if (w[i].first == "B+") summ+= w[i].second * 3.5;
        else if (w[i].first == "B") summ+= w[i].second * 3;
        else if (w[i].first == "C+") summ+= w[i].second * 2.5;
        else if (w[i].first == "C") summ+= w[i].second * 2;
        else if (w[i].first == "D+") summ+= w[i].second * 1.5;
        else if (w[i].first == "D") summ+= w[i].second * 1;
        else if (w[i].first == "F") summ+= w[i].second * 0;
        cnt += w[i].second;
    }
    return summ / cnt;
}

bool comp(pair<pair<string, string>, double>& p1, pair<pair<string, string>, double>& p2) {
    if(p1.second == p2.second){
        if(p1.first.first == p2.first.first) return p1.first.second < p2.first.second;
        return p1.first.first < p2.first.first;
    }
	return p1.second < p2.second;
}

vector<pair<pair<string, string>, double> > merge(vector<pair<pair<string, string>, double> > left, vector<pair<pair<string, string>, double> > right) {
	vector<pair<pair<string, string>, double> > result;
	int l = 0, r = 0;
	while (l < left.size() && r < right.size()) {
		if (comp(left[l], right[r])){
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

vector<pair<pair<string, string>, double> > merge_sort(vector<pair<pair<string, string>, double> > &a, int l, int r) {
	if (l == r) {
		vector<pair<pair<string, string>, double> > result;
		result.push_back(make_pair(make_pair(a[l].first.first, a[l].first.second), a[l].second));
		return result;
	}
	int m = l + (r - l) / 2;
	vector<pair<pair<string, string>, double> > left = merge_sort(a, l, m);
	vector<pair<pair<string, string>, double> > right = merge_sort(a, m + 1, r);
	return merge(left, right);
}

int main(){
    string first_n, last_n;
    int n; cin >> n;
    vector<pair<pair<string, string>, double> > vec;
    for(int i = 0; i < n; i++){
        cin >> last_n >> first_n;
        int k; cin >> k;
        vector<pair<string, int> > w;
        for(int j = 0; j < k; j++){
            string g; int c;
            cin >> g >> c;
            w.push_back(make_pair(g, c));
        }
        vec.push_back(make_pair(make_pair(last_n, first_n), getGpa(w)));
    }
	vector<pair<pair<string, string>, double> > ans = merge_sort(vec, 0, n - 1);
    for(int i = 0; i < n; i++){
        cout << ans[i].first.first << " " << ans[i].first.second << " " << fixed << setprecision(3) << ans[i].second << "\n";
    }
}