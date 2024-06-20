#include "bits/stdc++.h"
#pragma GCC optimize("O3")
#pragma GCC target("sse4")

using namespace std;

typedef long long ll;

int minimumSum(int n, vector<int> arr)
{
 

    // To store answer

    long long ans = 0;
 

    // To store maximum difference

    // between to adjacent elements

    int diff = 0;
 

    // Iterating over array

    for (int i = 1; i < n; i++) {
 

        // Sqaure of current adjacent

        // element difference

        long long temp = pow(abs(arr[i] - arr[i - 1]), 2);
 

        // Adding to answer

        ans += temp;
 

        // Taking maximum difference

        diff = max(diff, abs(arr[i] - arr[i - 1]));

    }
 

    // Difference of elements

    // in between element adding

    // after adding element

    int one = diff / 2, two = diff / 2;
 

    // If diff is odd

    if (diff % 2) {

        two++;

    }
 

    long long t = pow(one, 2) + pow(two, 2);
 

    t = pow(diff, 2) - t;
 

    // Decresing the sum after adding element

    ans -= t;
 

    return ans;
}
void solve()
{
    int n ;
    cin>>n;
    vector<int>arr(n,0);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<minimumSum(n,arr)<<endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // #ifndef ONLINE_JUDGE
    //     freopen("Input.txt", "r", stdin);
    //     freopen("Output.txt", "w", stdout);
    // #endif

    solve();

    return 0;
}
