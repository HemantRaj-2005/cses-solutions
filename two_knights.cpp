#include<bits/stdc++.h>
#define  ll long long
using namespace std;


void countKnights(int n){
    for(int i = 1; i <= n; i++){
        ll tot_pos = ( ll )i * i * (i * i - 1) / 2; //total ways to place two knights
        ll invalid_pos = 4 * (i - 1)  *  (i - 2);
        cout << tot_pos - invalid_pos << endl;
    }
}

int main(){
    int n;
    cin >> n;
    countKnights(n);

    return 0;
}