#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <climits>
using namespace std;
typedef long long ll;

int solve(string &s)
{
    vector<int> Rpos;
    int n = s.length();
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'R')
            Rpos.push_back(i);
    }
    // for(auto it : Rpos){
    //     cout<<it<<" ";
    // }
    // cout<<endl;
    if(Rpos.size() == 0){
        return 0;
    }
    if (Rpos.size() % 2)
    {
        int midPos = Rpos[Rpos.size() / 2];
        long long ans = 0;
        int end = midPos;
        for (int i = Rpos.size()/2 - 1; i >= 0; i--)
        {
            ans += end - Rpos[i] - 1;
            end--;
        }
        end = midPos;
        for (int i = Rpos.size()/2 + 1; i < Rpos.size(); i++)
        {
            ans += Rpos[i] - end - 1;
            end++;
        }
        // cout<<end<<endl;
        if(ans >=1e9){
            return -1;
        }
        else return ans;
    }
    else{
        int midPos = Rpos[Rpos.size() / 2];
        long long ans1 = 0;
        int end = midPos;
        for (int i = Rpos.size() / 2 - 1; i >= 0; i--)
        {
            ans1 += end - Rpos[i] - 1;
            end--;
        }
        end = midPos;
        for (int i = Rpos.size() / 2 + 1; i < Rpos.size(); i++)
        {
            ans1 += Rpos[i] - end - 1;
            end++;
        }
        midPos = Rpos[Rpos.size() / 2-1];
        long long ans2 = 0;
        end = midPos;
        for (int i = Rpos.size() / 2-1 - 1; i >= 0; i--)
        {
            ans2 += end - Rpos[i] - 1;
            end--;
        }
        end = midPos;
        for (int i = Rpos.size() / 2-1 + 1; i < Rpos.size(); i++)
        {
            ans2 += Rpos[i] - end - 1;
            end++;
        }
        long long ans = min(ans1 , ans2);
        if(ans >=1e9){
            return -1;
        }
        else return ans;

    }
}

    int main()
    {
        // int n;
        // cin >> n;
        string s;
        cin >> s;
        cout << solve(s) << endl;
        return 0;
    }