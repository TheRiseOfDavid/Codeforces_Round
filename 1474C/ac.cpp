#include <bits/stdc++.h>

using namespace std;

const int A = 1e6 + 12;

int cnt[A];

void reset(vector<int> a)
{
    for (int i = 0; i < a.size(); i++)
    {
        cnt[a[i]] = 0;
    }
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(2 * n);
    for (int i = 0; i < 2 * n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int t = 0; // t = flag
    for (int i = 0; i < 2 * n - 1; i++)
    {
        for (int j = 0; j < 2 * n; j++)
            cnt[a[j]]++; //知道每個值的位置
        int j = 2 * n - 1;
        int x = a[i] + a[j]; // x 為最大值
        vector<int> rm;
        for (int op = 0; op < n; op++)
        {
            while (j > 0 && cnt[a[j]] == 0) //整理並找出 a 陣列中可以用的值
                j--;
            rm.push_back(a[j]);
            rm.push_back(x - a[j]);
            cnt[a[j]]--, cnt[x - a[j]]--;
            if (cnt[a[j]] < 0 || cnt[x - a[j]] < 0)
            {
                cnt[a[j]] = 0;
                cnt[x - a[j]] = 0;
                break;
            }
            x = max(x - a[j], a[j]);
            if (op + 1 == n)
                t = 1;
        }
        reset(a);
        if (t)
        {
            cout << "YES\n";
            cout << rm[0] + rm[1] << "\n";
            for (int i = 0; i < rm.size(); i++)
            {
                cout << rm[i] << " \n"[i % 2];
            }
            return;
        }
    }
    cout << "NO\n";
    reset(a);
}

int main(int argc, char* argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}