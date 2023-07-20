// DP on Grids/2d Matrix

// -> Count paths with obstacle
/*
Given a 'N'*'M' maze with obstacles, count and return the number of paths to reach the 
right-bottom cell from the top-left cell. A cell in the given maze has a value -1 if it 
is a blockage or dead-end, else 0. From a given cell, we are allowed to move to 
cells (i+1, j) and (i,j+1) only. Since the answer can be large, print it modulo 10^9 + 7.
*/

#include<bits/stdc++.h>
using namespace std;

// recursion
int grRec(int i, int j, vector<vector<int>> &arr){
    if(i>=0 && j>=0 && arr[i][j]==-1){return 0;}
    if(i==0 && j==0){return 1;}
    if(i<0 || j<0){return 0;}
    int up = grRec(i-1, j, arr);
    int left = grRec(i, j-1, arr);
    return up + left;
}

// Memoization
int grMem(int i, int j, vector<vector<int>> &dp, vector<vector<int>> &arr){
    if(i>=0 && j>=0 && arr[i][j]==-1){return 0;}
    if(i==0 && j==0){return 1;}
    if(i<0 || j<0){return 0;}
    if(dp[i][j]!=-1){return dp[i][j];}
    int up = grMem(i-1, j, dp, arr);
    int left = grMem(i, j-1, dp, arr);
    return dp[i][j] = up + left;
}

// Tabulation
int greTab(int m, int n, vector<vector<int>> &arr){
    int dp[m][n];
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(i==0 && j==0){dp[i][j]=1;}
            if(arr[i][j]==-1){dp[i][j] = 0;}
            else{
                int up = 0, left = 0;
                if(i>0){up=dp[i-1][j];}
                if(j>0){left = dp[i][j-1];}
                dp[i][j] = up+left;
            }
        }
    }
    return dp[m-1][n-1];
}

// space optimised
int greSp(int m, int n, vector<vector<int>> &arr){
    vector<int> prev(n,0);
    for(int i=0; i<m; i++){
        vector<int> curr(n,0);
        for(int j=0; j<n; j++){
            if(i==0 && j==0){curr[j]=1;}
            if(arr[i][j]==-1){curr[j] = 0;}
            else{
                int up = 0, left = 0;
                if(i>0){up = prev[j];}
                if(j>0){left = curr[j-1];}
                curr[j] = up+left;
            }
        }
        prev = curr;
    }
    return prev[n-1];
}

// driver code
int main(){
    int m{3},n{3};
    vector<vector<int>> arr{{0,0,0},{0,-1,0},{0,0,0}};
    cout<<"Using Recursion: "<<grRec(m-1, n-1, arr)<<endl;

    vector<vector<int>> dp(m, vector<int>(n, -1));
    cout<<"Using Memoization: "<<grMem(m-1, n-1, dp, arr)<<endl;

    cout<<"Using Tabulation: "<<greTab(m, n, arr)<<endl;

    cout<<"Using Space Optimisation: "<<greSp(m, n, arr)<<endl;

    return 0;
}