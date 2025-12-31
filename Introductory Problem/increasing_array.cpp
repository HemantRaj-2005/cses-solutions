#include <bits/stdc++.h>
using namespace std;

int main(){
    long long steps = 0;
    long long n;
    cin >> n;
    long long arr[n];
    for(long long i = 0; i < n; i++){
        cin >> arr[i];
    }

    for(long long j = 1;  j < n; j++){
        if(arr[j] < arr[j-1]){
            steps += arr[j-1] - arr[j];
            arr[j] = arr[j-1];
        }
    }
    cout << steps << endl;

    return 0;
}