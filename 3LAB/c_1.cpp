#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

pair<int , int> getRange(vector<int> &nums, int lx, int rx) {
    pair<int, int> res;
    res.first = -1;
    res.second = -2;

    if(nums.back() < lx || nums[0] > rx)
        return res;

    int l = -1, r = nums.size()-1;

    while(l + 1 < r) {
        int mid = (l+r)/2;
        if(nums[mid] >= lx)
            r = mid;
        else
            l = mid;
    }
    res.first = r;

    l = 0;
    r = nums.size();

    while(l + 1 < r) {
        int mid = (l+r)/2;
        if(nums[mid] <= rx)
            l = mid;
        else
            r = mid;
    }

    res.second = l;

    return res;
}

int main(){
    int n, q, cnt = 0, a, t;
    cin >> n >> q;
    vector<int> nums;
    for(int i = 0; i < n; i++){
        cin >> a;
        nums.push_back(a);
    }
    int l1, l2, r1, r2;
    for(int i = 0; i<q; i++){
        cin >> l1 >> r1 >> l2 >> r2;
        pair<int , int> range = getRange(nums, l1, r1);
        cnt = range.first + range.second;
        pair<int , int> range1 = getRange(nums, l2, r2);
        t = range1.first + range1.second;

        cout << t+cnt << endl;
        
    }
    return 0;
}