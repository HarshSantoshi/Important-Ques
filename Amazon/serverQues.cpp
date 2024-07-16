
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int solve(string s, int k)
{
    vector<int> clusters0;
    vector<int> clusters1;
    int cons0 = 0;
    int cons1 = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '1')
        {
            cons1++;
            if (cons0)
            {
                clusters0.push_back(cons0);
            }
            cons0 = 0;
        }
        else
        {
            if (cons1)
            {
                clusters1.push_back(cons1);
            }
            cons1 = 0;
            cons0++;
        }
    }
    if (cons0)
    {
        clusters0.push_back(cons0);
    }
    if (cons1)
    {
        clusters1.push_back(cons1);
    }

    if (clusters0.size() <= k)
    {
        return s.length();
    }
    // use sliding window to take those k clusters which make largest consecutive 1
    int left = 0, right = 0;
    int sum = 0;
    int maxSum = 0;
    int K = k;
    while (right < clusters0.size())
    {
        // calculating sum of prev1s , curr0s and next1s
        sum += clusters0[right] + clusters1[right] + clusters1[right + 1];
        K--;
        if (K == 0)
        {
            maxSum = max(maxSum, sum);
            sum -= clusters0[left] + clusters1[left] + clusters1[left + 1];
            K++;
        }
        right++;
    }
    return maxSum;
}
int main()
{
    string s = "11101010110011";
    int k = 2;
    int ans = solve(s, k);
    cout << ans << endl;

    return 0;
}