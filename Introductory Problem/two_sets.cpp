#include <bits/stdc++.h>
#define ll long long
using namespace std;

void div( int n ){
    int n_even = 0, n_odd = 0;
    vector<int> first;
    vector<int> second;
    first.push_back(1);
    for(int i = 2; i <= n; i+= 2){
        n_even++;

        if(n_even%4 == 1 || n_even%4  == 2){
            first.push_back(i);
        } else{
            second.push_back(i);
        }
    }
    for(int i = 3; i <= n; i+= 2){
        n_odd++;

        if(n_odd%4 == 1 || n_odd%4  == 2){
            second.push_back(i);
        } else{
            first.push_back(i);
        }
    }

    cout << first.size() << endl;
    for(auto & it : first){
        cout << it << " ";
    }
    cout << endl;
    cout << second.size() << endl;
    for(auto & it : second){
        cout << it << " ";
    }
}


void div_even(int n){
    int n_even = 0, n_odd = 0;
    vector<int> first;
    vector<int> second;

    for(int i = 1; i <= n; i+=2){
        if(n_odd%2 == 0){
            first.push_back(i);
        } else{
            second.push_back(i);
        }
        n_odd++;
    }

    for(int i = 2; i <= n; i+= 2){
        if(n_even%2 == 0){
            second.push_back(i);
        } else{
            first.push_back(i);
        }
        n_even++;
    }

    cout << first.size() << endl;
    for(auto & it : first){
        cout << it << " ";
    }
    cout << endl;
    cout << second.size() << endl;
    for(auto & it : second){
        cout << it << " ";
    }

}
int main(){

    int n;
    cin >> n;

    ll tot_sum = (n * ( n + 1 ) ) / 2;
    if(tot_sum%2 != 0) cout << "NO" << endl;

    else if(n%2 == 0 && tot_sum % 2 == 0){
        cout << "YES" << endl;
        div_even(n);
    }

    else{
        cout << "YES" << endl;
        div(n);
    }
    return 0;
}