#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s;
    cin >> s;
    ll n = s.size();
    vector<ll> alpha(26, 0);

    for (char c : s)
        alpha[c - 'A']++;

    ll odd_count = 0, odd_index = -1;
    for (ll i = 0; i < 26; i++)
    {
        if (alpha[i] % 2 == 1)
        {
            odd_count++;
            odd_index = i;
        }
    }

    // Agar ek se zyada odd frequency hai toh palindrome banana impossible hai
    if (odd_count > 1)
    {
        cout << "NO SOLUTION" << endl;
        return 0;
    }

    string half = "", mid = "";

    // Construct half part aur agar koi odd character hai toh mid part
    for (ll i = 0; i < 26; i++)
    {
        half += string(alpha[i] / 2, 'A' + i);
        if (i == odd_index)
            mid = string(alpha[i] % 2, 'A' + i);
    }

    // Final palindrome: half + mid + reversed(half)
    string ans = half + mid + string(half.rbegin(), half.rend());
    cout << ans << endl;

    return 0;
}
