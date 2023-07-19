#include<bits/stdc++.h>
using namespace std;

// recursion
int frogRec(int n, vector<int> &heights){
    if(n==0){return 0;}
    int left = frogRec(n-1, heights) + abs(heights[n]-heights[n-1]);
    int right = INT_MAX;
    if(n>1){
        right = frogRec(n-2, heights) + abs(heights[n]-heights[n-2]);
    }
    return min(left, right);
}

// memoization
int frogMem(int n, vector<int> &height, vector<int> &dp){
    if(n==0){return 0;}
    if(dp[n]!=-1){return dp[n];}
    int left = frogMem(n-1, height, dp) + abs(height[n]-height[n-1]);
    int right = INT_MAX;
    if(n>1){
        right = frogMem(n-2, height, dp) + abs(height[n]-height[n-2]);
    }
    return dp[n] = min(left, right);
}

// tabulation
int frogTab(int n, vector<int> &height){
    vector<int> dp(n, 0);
    dp[0] = 0;
    for(int i=1; i<n; i++){
        int left = dp[i-1] + abs(height[i]-height[i-1]);
        int right = INT_MAX;
        if(n>1){
            right = dp[i-2] + abs(height[i]-height[i-2]);
        }
        dp[i] = min(left, right);
    }
    return dp[n-1];
}

// space optimised
int frogSP(int n, vector<int> &height){
    int prev = 0, prev2 = 0;
    for(int i=1; i<n; i++){
        int left = prev + abs(height[i]-height[i-1]);
        int right = INT_MAX;
        if(n>1){
            right = prev2 + abs(height[i]-height[i-2]);
        }
        int curr = min(left, right);
        prev2 = prev;
        prev = curr;
    }
    return prev;
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

    cout<<"Using recursion: "<<frogRec(n-1, heights)<<endl;

    vector<int> dp(n, -1);
    cout<<"Using Memoization: "<<frogMem(n-1, heights, dp)<<endl;

    cout<<"Using tabulation: "<<frogTab(n, heights)<<endl;

    cout<<"Space optimised: "<<frogSP(n, heights)<<endl;
    return 0;
}