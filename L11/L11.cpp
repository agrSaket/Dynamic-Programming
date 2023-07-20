// minimum path sum in triangular grid

/*
You are given a triangular array/list 'TRIANGLE'. Your task is to return the minimum path sum 
to reach from the top to the bottom row.
The triangle array will have N rows and the i-th row, where O<=i<N will have i+1 elements.
You can move only to the adjacent number of row below each step. For example, if you are at 
index j in row i, then you can move to i or i+1 index in row j+1 in each step.
*/

#include<bits/stdc++.h>
using namespace std;

// recursion
int minTRec(int i, int j, int r, vector<vector<int>> &grid){
    if(i==r-1){return grid[i][j];}
    int bottom = grid[i][j] + minTRec(i+1, j, r, grid);
    int botRight = grid[i][j] + minTRec(i+1, j+1, r, grid);
    return min(bottom, botRight);
}

// memoization
int minTMem(int i, int j, int r, vector<vector<int>> &grid, vector<vector<int>> &dp){
    if(dp[i][j]!=-1){return dp[i][j];}
    if(i==r-1){return grid[i][j];}
    int bottom = grid[i][j] + minTRec(i+1, j, r, grid);
    int botRight = grid[i][j] + minTRec(i+1, j+1, r, grid);
    return dp[i][j] = min(bottom, botRight);
}

// space optimised
int minTSp(vector<vector<int>> &grid, int r){
    vector<int> front(r,0), cur(r,0);
    for(int j=0;j<r;j++){
        front[j] = grid[r-1][j];
    }
    
    for(int i=r-2; i>=0; i--){
        for(int j=i; j>=0; j--){
            
            int down = grid[i][j]+front[j];
            int diagonal = grid[i][j]+front[j+1];
            
            cur[j] = min(down, diagonal);
        }
        front=cur;
    }
    return front[0];
}

// print Grid
void printGrid(vector<vector<int>> &grid){
    int r = grid.size();
    for(int i=0; i<r; i++){
        int c = grid[i].size();
        for(int j=0; j<c; j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<"\n";
    }
}

// driver code
int main(){
    int r;
    cout<<"Enter row: ";cin>>r;
    vector<vector<int>> grid;
    for(int i=0; i<r; i++){
        cout<<"Enter elements in row "<<i<<": ";
        vector<int> temp(i+1, 0);
        for(int j=0; j<i+1; j++){
            cin>>temp[j];
        }
        grid.push_back(temp);
    }
    printGrid(grid);

    cout<<"Using Recursion: "<<minTRec(0, 0, r, grid)<<endl;

    vector<vector<int> > dp(r,vector<int>(r,-1));
    cout<<"Using Memoization: "<<minTMem(0, 0, r, grid, dp)<<endl;

    cout<<"Using Space Optimised: "<<minTSp(grid, r)<<endl;
    return 0;
}