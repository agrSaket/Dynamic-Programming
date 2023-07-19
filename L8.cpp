// DP on Grids/2d Matrix
// -> Count paths
// -> Count paths with obstacle
// -> Min Path Sum
// -> Max path sum
// -> triangle
// -> 2 start points

#include<bits/stdc++.h>
using namespace std;

// recursion
int grRec(int i, int j){
    if(i==0 && j==0){return 1;}
    if(i<0 || j<0){return 0;}
    int up = grRec(i-1, j);
    int left = grRec(i, j-1);
    return up + left;
}

int grMem(int i, int j, vector<vector<int>> &dp){
    if(i==0 && j==0){return 1;}
    if(i<0 || j<0){return 0;}
    if(dp[i][j]!=-1){return dp[i][j];}
    int up = grMem(i-1, j, dp);
    int left = grMem(i, j-1, dp);
    return dp[i][j] = up + left;
}

// Tabulation
int greTab(int m, int n){
    int dp[m][n];
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(i==0 && j==0){dp[i][j]=1;}
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


// driver code
int main(){
    int m{3},n{4};
    cout<<"Using Recursion: "<<grRec(m-1, n-1)<<endl;

    vector<vector<int>> dp(m, vector<int>(n, -1));
    cout<<"Using Memoization: "<<grMem(m-1, n-1, dp)<<endl;

    cout<<"Using Tabulation: "<<greTab(m, n)<<endl;

    return 0;
}