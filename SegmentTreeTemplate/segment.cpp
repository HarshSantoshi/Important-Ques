#include <bits/stdc++.h>
using namespace std;
vector<int> arr;
vector<int> seg(1e6);
class SGTree
{
    vector<int> seg;

public:
    SGTree(int n)
    {
        seg.resize(4 * n + 1, 0);
    }
    void build(int idx, int low, int high , vector<int>&arr)
    {
        if (low == high)
        {
            seg[idx] = arr[low];
            return;
        }
        int mid = low + (high - low) / 2;
        build(2 * idx + 1, low, mid , arr);
        build(2 * idx + 2, mid + 1, high , arr);
        // According to ques :
        seg[idx] = max(seg[2 * idx + 1], seg[2 * idx + 2]);
    }
    void update(int idx, int low, int high, int i, int val)
    {
        if (low == high)
        {
            seg[idx] = val;
            return;
        }
        int mid = low + (high - low) / 2;
        if (i <= mid)
            update(2 * idx + 1, low, mid, i, val);
        else
            update(2 * idx + 2, mid + 1, high, i, val);
        // According to ques :
        seg[idx] = max(seg[2 * idx + 1], seg[2 * idx + 2]);
    }
    int pointQuery(int idx, int low, int high, int l, int r)
    {
        if (low >= l && high <= r)
        {
            return seg[idx];
        }
        if (high < l || low > r)
            return INT_MIN;
        int mid = low + (high - low) / 2;

        int left = pointQuery(2 * idx + 1, low, mid, l, r);
        int right = pointQuery(2 * idx + 2, mid + 1, high, l, r);
        return max(left, right);
    }
};
void build(int idx, int low, int high)
{
    if (low == high)
    {
        seg[idx] = arr[low];
        return;
    }
    int mid = low + (high - low) / 2;
    build(2 * idx + 1, low, mid);
    build(2 * idx + 2, mid + 1, high);
    // According to ques :
    seg[idx] = max(seg[2 * idx + 1], seg[2 * idx + 2]);
}
void update(int idx, int low, int high, int i, int val)
{
    if (low == high)
    {
        seg[idx] = val;
        return;
    }
    int mid = low + (high - low) / 2;
    if (i <= mid)
        update(2 * idx + 1, low, mid, i, val);
    else
        update(2 * idx + 2, mid + 1, high, i, val);
    // According to ques :
    seg[idx] = max(seg[2 * idx + 1], seg[2 * idx + 2]);
}
int query(int idx, int low, int high, int l, int r)
{
    if (low >= l && high <= r)
    {
        return seg[idx];
    }
    if (high < l || low > r)
        return INT_MIN;
    int mid = low + (high - low) / 2;

    int left = query(2 * idx + 1, low, mid, l, r);
    int right = query(2 * idx + 2, mid + 1, high, l, r);
    return max(left, right);
}
int main()
{
    int n;
    cin >> n;
    arr.resize(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    build(0, 0, n - 1);

    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        query(0, 0, n - 1, l, r);
    }
}