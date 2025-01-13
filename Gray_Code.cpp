#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<string> gray(ll n){
    vector<string> res;
    if(n == 1){
        res.push_back("0");
        res.push_back("1");
        return res;
    }

    vector<string> pres = gray(n-1);
    ll s = pres.size();

    for(ll i = 0; i < s; i++){
        res.push_back("0"+pres[i]);
    }

    for(ll i = s-1; i >=0; i--){
        res.push_back("1"+pres[i]);
    }

    return res;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll n;
    cin >> n;
    vector<string> ans = gray(n);

    for(auto &it : ans){
        cout << it << endl;
    }

    return 0;
}