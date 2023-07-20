#include<bits/stdc++.h>
using namespace std;

// recursion
int frogRec(int n, vector<int> &heights, int k){
    if(n==0){return 0;}
    int minsteps = INT_MAX;
    for(int i=1; i<=k; i++){
        int jump = INT_MAX;
        if(n-i>=0){
            jump = frogRec(n-i, heights, k)+ abs(heights[n]-heights[n-i]);
        }
        minsteps = min(minsteps, jump);
    }
    return minsteps;
}

// memoization
int frogMem(int n, vector<int> &height, int k, vector<int> &dp){
    if(n==0){return 0;}
    if(dp[n]!=-1){return dp[n];}
    int left = frogMem(n-1, height, k, dp) + abs(height[n]-height[n-1]);
    int right = INT_MAX;
    if(n>1){
        right = frogMem(n-2, height, k, dp) + abs(height[n]-height[n-2]);
    }
    return dp[n] = min(left, right);
}

// tabulation
int frogTab(int n, vector<int> &height, int k){
    vector<int> dp(n, 0);
    dp[0] = 0;
    for(int i=1; i<n; i++){
        int minsteps = INT_MAX;
        for(int j=1; j<=k; j++){
            int jump = INT_MAX;
            if(i-j>=0){
                jump = dp[i-j] + abs(height[n]-height[n-j]);
            }
            minsteps = min(minsteps, jump);
        }
        dp[i] = minsteps;
    }
    return dp[n-1];
}


// driver code
int main(){
    int n; cout<<"Enter n: "; cin>>n;
    vector<int> heights(n,0);
    for(int i=0; i<n; i++){
        int temp;
        cin>>temp;
        heights[i] = temp;
    }
    int k; cout<<"Enter k: "; cin>>k;
    cout<<"Using recursion: "<<frogRec(n-1, heights, k)<<endl;

    vector<int> dp(n, -1);
    // cout<<"Using Memoization: "<<frogMem(n-1, heights, k, dp)<<endl;

    cout<<"Using tabulation: "<<frogTab(n, heights, k)<<endl;

    return 0;
}