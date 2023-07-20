// Maximum sum of non adjacent elements
// You are given an arraylist Of 'N' integers. You are supposed to return the maximum Sum Of the
// subsequence with the constraint that no two elements are adjacent in the given arraynist.
#include<bits/stdc++.h>
using namespace std;

// recursion
int sumRec(int idx, vector<int> &arr){
    if(idx==0){return arr[idx];}
    if(idx<0){return 0;}
    int pick = arr[idx] + sumRec(idx-2, arr);
    int notpick = 0 + sumRec(idx-1, arr);
    return max(pick, notpick);
}   // TC-O(2^n)  SC-O(n)+O(n)

// memoization
int sumMem(int idx, vector<int> &arr, vector<int> &dp){
    if(idx==0){return arr[idx];}
    if(idx<0){return 0;}
    if(dp[idx]!=-1){return dp[idx];}
    int pick = arr[idx] + sumMem(idx-2, arr, dp);
    int notpick = 0 + sumMem(idx-1, arr, dp);
    return dp[idx] = max(pick, notpick);
}   // TC-O(n)  SC-O(n)+O(n)

// tabulation
int sumTab(int idx, vector<int> &arr, vector<int> &dp){
    dp[0] = arr[0];
    int neg = 0;
    for(int i=1; i<idx; i++){
        int pick = arr[idx];
        if(i>1){pick += dp[i-2];}
        int notpick = 0 + dp[i-1];
        dp[idx] = max(pick, notpick);
    }
    return dp[idx];
}   // TC-O(n)  SC-O(n)

// space optimised
int sumSp(int idx, vector<int> &arr){
    int prev = arr[0];
    int prev2 = 0;
    for(int i=1; i<idx; i++){
        int pick = arr[idx];
        if(i>1){pick += prev2;}
        int notpick = 0 + prev;
        int curr = max(pick, notpick);
        prev2 = prev;
        prev = curr;
    }
    return prev;
}

int main(){
    vector<int> arr{2, 1, 4, 9};
    int n = arr.size();
    cout<<"Using recursion: "<<sumRec(n-1, arr)<<endl;

    vector<int> dp(n, -1);
    cout<<"Using memoization: "<<sumMem(n-1, arr, dp)<<endl;

    vector<int> dp2(n, -1);
    cout<<"Using Tabulation: "<<sumTab(n-1, arr, dp2)<<endl;

    cout<<"Space Optimised: "<<sumSp(n-1, arr);

    return 0;
}