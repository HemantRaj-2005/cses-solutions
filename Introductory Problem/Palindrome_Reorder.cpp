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
    string ans;

    for (char &c : s)
    {
        alpha[c - 'A']++;
    }

    //* condition when n is even
    if (n % 2 == 0)
    {
        bool possible = true;

        for (ll &i : alpha)
        {
            if (i % 2 == 1)
            {
                possible = false;
                break;
            }
        }

        if (!possible)
        {
            cout << "NO SOLUTION" << endl;
            return 0;
        }
        else
        {
            for (ll i = 0; i < 26; i++)
            {
                ll times = alpha[i] / 2;
                while (times--)
                {
                    ans.push_back('A' + i);
                }
            }
            for (ll i = 25; i >= 0; i--)
            {
                ll times = alpha[i] / 2;
                while (times--)
                {
                    ans.push_back('A' + i);
                }
            }
        }
    }
    //* condition when there are odd size of string
    else
    {
        ll odd_char_index = -1; // Store index of the odd character

        for (ll i = 0; i < 26; i++)
        {
            if (alpha[i] % 2 == 1)
            {
                if (odd_char_index != -1)
                {
                    cout << "NO SOLUTION" << endl;
                    return 0;
                }
                odd_char_index = i;
            }
        }

        if (odd_char_index == -1)
        {
            cout << "NO SOLUTION" << endl;
            return 0;
        }

        for (ll i = 0; i < 26; i++)
        {
            ll times = alpha[i] / 2;
            while (times--)
            {
                ans.push_back('A' + i);
            }
        }

        ans.push_back('A' + odd_char_index);

        for (ll i = 25; i >= 0; i--)
        {
            ll times = alpha[i] / 2;
            while (times--)
            {
                ans.push_back('A' + i);
            }
        }
    }
    cout << ans << endl;
    return 0;
}