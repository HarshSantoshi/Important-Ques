#include <bits/stdc++.h>
using namespace std;
int val[] = {1, 10, 100, 1000, 10000};
int an = -2e9;
void check(int p, string s)
{
    if (p == -1)
        return;
    for (char v : {0, 1, 2, 3, 4})
    {
        swap(v, s[p]);
        int prev = 0, currValue = 0;
        for (char c : s)
            currValue += c >= prev ? val[prev = c] : -val[c];
        an = max(an, currValue);
        swap(v, s[p]);
    }
}
int getmaxnum(string s)
{
    string newS = "";
    for (auto ch : s)
    {
        newS += ch - 'A';
    }
    s = newS;
    reverse(s.begin(), s.end());

    for (int i : {0, 1, 2, 3, 4})
        check(s.find_first_of(i), s),
        check(s.find_last_of(i), s);

    return an;
}
int main()
{
    string s;
    cin >> s;
    cout << getmaxnum(s) << endl;
    return 0;
}