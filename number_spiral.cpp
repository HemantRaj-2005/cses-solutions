#include <bits/stdc++.h>
using namespace std;

long long position(long long row, long long col)
{
    long long num;
    if (col > row)
    {
        if (col % 2 == 1)
        {
            num = (col-1)*(col-1) + row;
        }
        else
        {
            num = col*col - (row - 1);
        }
    }

    else
    {
        if (row % 2 == 1)
        {
            num = row*row - (col - 1);
        }
        else
        {
            num = (row-1)*(row-1) + col;
        }
    }
    return num;
}
int main()
{
    int t, x, y;
    cin >> t;
    while (t > 0)
    {
        cin >> x >> y;
        cout << position(y, x) << endl;
        t--;
    }
    return 0;
}