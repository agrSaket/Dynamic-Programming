// Minimum Path Sum

/*
Ninjaland is a country in the shape of a 2-Dimensional grid 'GRID', with 'N' rows and 'M' 
columns. Each point in the grid has some cost associated with it.
Find a path from top left i.e. (0, 0) to the bottom right i.e. ('N'-1, 'M'-1) which minimizes 
the sum of the cost of all the numbers along the path. You need to tell the minimum sum of 
that path.
*/

#include<bits/stdc++.h>
using namespace std;

// recursion
int minpsRec(int i, int j, vector<vector<int>> &grid){
    if(i==0 && j==0){return grid[i][j];}
    if(i<0 || j<0){return INT_MAX;}
    int up = grid[i][j] + minpsRec(i-1, j, grid);
    int left = grid[i][j] + minpsRec(i, j-1, grid);
    return min(up, left);
}

// memoization
int minpsMem(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp){
    if(i==0 && j==0){return grid[i][j];}
    if(i<0 || j<0){return INT_MAX;}
    if(dp[i][j]!=-1){return dp[i][j];}
    int up = grid[i][j] + minpsMem(i-1, j, grid, dp);
    int left = grid[i][j] + minpsMem(i, j-1, grid, dp);
    return dp[i][j] = min(up, left);
}

// tabulation
int minpsTab(vector<vector<int>> &grid){
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(i==0 && j==0){dp[i][j]==grid[i][j];}
            else {
                int up = grid[i][j];
                if(i > 0) up += dp[i-1][j];
                else up += 1e9;
                int left = grid[i][j];
                if(j>0) left += dp[i][j-1];
                else left += 1e9;
                dp[i][j] = min(left, up);
            }
        }
    }
    return dp[n-1][m-1];
}

// print Grid
void printGrid(vector<vector<int>> &grid){
    int r = grid.size(), c = grid[0].size();
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<"\n";
    }
}

// driver code
int main(){
    int r, c;
    cout<<"Enter row: ";cin>>r;
    cout<<"Enter column: "; cin>>c;
    vector<vector<int>> grid(r, vector<int> (c, 0));
    for(int i=0; i<r; i++){
        cout<<"Enter elements in row "<<i<<": ";
        for(int j=0; j<c; j++){
            cin>>grid[i][j];
        }
    }
    printGrid(grid);

    cout<<"Using Recursion: "<<minpsRec(r-1, c-1, grid);

    vector<vector<int>> dp(r, vector<int> (c, -1));
    cout<<"Using Memoization: "<<minpsMem(r-1, c-1, grid, dp);
    return 0;
}