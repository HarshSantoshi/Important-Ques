#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <climits>
#include<set>
using namespace std;
typedef long long ll;
int mod = 1e9 + 7;

int countPairs(vector<int> &nums, int target) {
    int n = nums.size();
    multiset<int> s;
    int ans = 0;
    s.insert(nums[n - 1]);
    for (int i = n - 2; i >= 0; i--) {
        int needed = nums[i] - target;
        auto it = s.lower_bound(needed);
        if ( it!=s.end()) {
            ans += distance(it , s.end()); 
        }
        s.insert(nums[i]);
    }
    
    return ans;
}
void solve(){
    int n, c, d;
    cin >> n >> c >> d;
    vector<int> a(n, 0);
    vector<int> b(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++)
    {
        nums[i] = a[i] - b[i];
    }
    int target = d - c;
    int ans = countPairs(nums, target);

    cout << ans << endl;
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    
    return 0;
}