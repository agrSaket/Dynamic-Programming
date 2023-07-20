// climbing stairs

#include<bits/stdc++.h>
using namespace std;

// using recursion
int cntstair(int n){
    if(n==0){return 1;}
    if(n==1){return 1;}
    int left = cntstair(n-1);
    int right = cntstair(n-2);
    return left + right;
}

// memoization
int cntMem(int n, vector<int> &dp){
    if(n==0){return 1;}
    if(n==1){return 1;}
    if(dp[n] != -1){return dp[n];}
    return dp[n] = cntMem(n-1, dp)+cntMem(n-2, dp);
}

// driver code
int main(){
    int n; cout<<"Enter n: "; cin>>n;
    cout<<"Using Recursion: "<<cntstair(n)<<endl;

    vector<int> dp(n+1, -1);
    cout<<"Using Memoization: "<<cntMem(n, dp)<<endl;
    return 0;
}