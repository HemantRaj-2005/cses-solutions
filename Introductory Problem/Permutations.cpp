#include <bits/stdc++.h>
using namespace std;

void printBeatifulPermutation(int n){
    if(n == 1){
        cout << "1" << endl; 
        return;
    }
    if(n == 2 || n == 3){
        cout << "NO SOLUTION" << endl;
        return;
    }
    vector<int> permutation;

    // first printing even numbers in increasing order
    for(int i = 2; i <= n; i++){
        if(i%2 == 0){
            permutation.push_back(i);
        }
    }

    // then printing odd numbers in increasing order
    for(int i = 1; i <= n; i++){
        if(i%2 == 1){
            permutation.push_back(i);
        }
    }

    for (int i = 0; i < permutation.size(); i++)
    {
        cout << permutation[i] << " ";
    }
    cout << endl;
    
}

int main(){
    int input;
    cin >> input;
    printBeatifulPermutation(input);

    return 0;
}