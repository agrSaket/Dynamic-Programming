// fibonacci number 
#include<bits/stdc++.h>
using namespace std;
// recursive solution
int fibRec(int n){
    if(n<=1){
        return n;
    }
    return fibRec(n-1)+fibRec(n-2);
}

// memoization method
int fibMem(int n, vector<int> &dp){
    if(n<=1){
        return n;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    return dp[n] = fibMem(n-1, dp)+fibMem(n-2, dp);
}   // TC - O(n)        SC - O(n)+O(n)

// Tabulation 
int fibTab(int n, vector<int> &dp){
    dp[0] = 0;
    dp[1] = 1;
    for(int i=2; i<=n; i++){
        dp[i] = dp[i-1]+dp[i-2];
    }
    return dp[n];
}   // TC-O(n)  SC-O(n)

// Space optimised
int fibSp(int n){
    int prev = 1;
    int prev2 = 0;
    for(int i=2; i<=n; i++){
        int curr = prev + prev2;
        prev2 = prev;
        prev = curr;
    }
    return prev;
}   // TC-O(n)   SC-O(1)

// Driver code
int main(){
    int n; cout<<"Enter n: "; cin>>n;
    cout<<"Using recursion: "<<fibRec(n)<<endl;

    vector<int> dp(n+1, -1);
    cout<<"Using memoization: "<<fibMem(n, dp)<<endl;

    vector<int> dp2(n+1, -1);
    cout<<"Using tabulation: "<<fibTab(n, dp2)<<endl;

    cout<<"Spacce optimised: "<<fibSp(n)<<endl;
    return 0;
}