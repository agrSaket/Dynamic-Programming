// DP on Grids/2d Matrix
// -> Count paths
// -> Count paths with obstacle
// -> Min Path Sum
// -> Max path sum
// -> triangle
// -> 2 start points

// total unique paths
/*
You are present at point 'A' which s the top-left cell Of an M X N matrix. your destination 
is point 'B', which is the bottom-right cell Of the same matrix. Your task is to find the 
total number Of unique paths from point 'A' to point 'B'. In other words, you will be given the 
dimensions of the matrix as integers 'M' and 'N', your task is to find the total number of 
unique paths from the cell MATRIX[0][0] to MATRIX['M'-1]['N'-1].
To traverse in the matrix. you can either move Right or Down at each step. For example in 
a given point MATRIX[i][j], you can move to either MATRIX[i+1][j] or MATRIX[i][j+1]  .
*/

#include<bits/stdc++.h>
using namespace std;

// recursion   - TC(2^(m*n))
int grRec(int i, int j){
    if(i==0 && j==0){return 1;}
    if(i<0 || j<0){return 0;}
    int up = grRec(i-1, j);
    int left = grRec(i, j-1);
    return up + left;
}

// memoization
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

// optimal solution - combination 
// video link - "https://youtu.be/t_f0nwwdg5o"
int optimal(int m, int n){
    int N = m+n-2;
    int r = m-1;
    double res = 1;
    for(int i=1; i<=r; i++){
        res *= (N-r+i)/i;
    }
    return (int)res;
}


// driver code
int main(){
    int m{3},n{4};
    cout<<"Using Recursion: "<<grRec(m-1, n-1)<<endl;
    
    vector<vector<int>> dp(m, vector<int>(n, -1));
    cout<<"Using Memoization: "<<grMem(m-1, n-1, dp)<<endl;

    cout<<"Using Tabulation: "<<greTab(m, n)<<endl;

    cout<<"Using Optimal approach: "<<optimal(m, n)<<endl;

    return 0;
}