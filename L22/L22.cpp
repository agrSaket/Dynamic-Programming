// Coin Change 2
/*
We are given an array Arr with N distinct coins and a target. We have an infinite supply of 
each coin denomination. We need to find the number of ways we sum up the coin values to give 
us the target.
Each coin can be used any number of times.
*/

#include<bits/stdc++.h>
using namespace std;

// recursion -- TC:O(2^n)  SC:O(n)
int KnapRec(int idx, vector<int> &coins, int target){
    if(idx==0){
        return (target%coins[0] == 0);
    }
    int notTake = KnapRec(idx-1, coins, target);
    int take = 0;
    if(target>=coins[idx]){
        take = KnapRec(idx, coins, target-coins[idx]);
    }
    return (take + notTake);
}

// memoization -- TC:O(n*target)  SC:O(n)+O(n*target)
int KnapMem(int idx, vector<int> &coins, int target, vector<vector<int>> &dp){
    if(idx==0){
        return (target%coins[0]== 0);
    }
    if(dp[idx][target]!=-1){return dp[idx][target];}
    int notTake = KnapMem(idx-1, coins, target, dp);
    int take = 0;
    if(target>=coins[idx]){
        take = KnapMem(idx, coins, target-coins[idx], dp);
    }
    return dp[idx][target] = (take + notTake);
}

// tabulation
int sumTab(int n, vector<int> &arr, int target){
    vector<vector<int>> dp(n, vector<int>(target+1, 0));
    for(int i=0; i<=target; i++){if(i%arr[0]==0){dp[0][i]=1;}}

    for(int i=1; i<n; i++){
        for(int k=0; k<=target; k++){
            int notTake = dp[i-1][k];
            int take = 0;
            if(k>=arr[i]){
                take = dp[i][k-arr[i]];
            }
            dp[i][k] = notTake + take;
        }
    }
    return dp[n-1][target];
}

// space optimised
int sumSp(int n, vector<int> &arr, int target){
    vector<int> prev(target+1, 0);
    vector<int> curr(target+1, 0);
    for(int i=0; i<=target; i++){if(i%arr[0]==0){prev[i]=1;}}

    for(int i=1; i<n; i++){
        for(int k=0; k<=target; k++){
            int notTake = prev[k];
            int take = 0;
            if(k>=arr[i]){
                take = curr[k-arr[i]];
            }
            curr[k] = notTake + take;
        }
        prev = curr;
    }
    return prev[target];
}

// print array
void printarray(vector<int> &arr, int n){
    cout<<"{ ";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<"}\n";
}


// driver code
int main(){
    int n; cout<<"enter n: "; cin>>n;
    vector<int> coins(n,0);         // = {1,2,4,5}
    cout<<"Enter elements of coins array: ";
    for(int i=0; i<n; i++){
        cin>>coins[i];
    }
    cout<<"Weight array: ";printarray(coins, n);
    int target; cout<<"Enter target: ";cin>>target;

    cout<<"\nUsing Recursion: "<<KnapRec(n-1, coins, target)<<endl;

    vector<vector<int>> dp(n, vector<int>(target+1, -1));
    cout<<"Using memoization: "<<KnapMem(n-1, coins, target, dp)<<"\n";

    cout<<"Using tabulation: "<<sumTab(n, coins, target)<<"\n";
    
    cout<<"Using space optimisation: "<<sumSp(n, coins, target)<<"\n";
    return 0;
}