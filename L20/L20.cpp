// Minimum Coins
/*
We are given a target sum of ‘X’ and ‘N’ distinct numbers denoting the coin denominations. 
We need to tell the minimum number of coins required to reach the target sum. We can pick a 
coin denomination for any number of times we want
*/

#include<bits/stdc++.h>
using namespace std;

// recursion -- TC:O(2^n)  SC:O(n)
int KnapRec(int idx, vector<int> &coins, int target){
    if(idx==0){
        if(target%coins[0]== 0){return target/coins[0];}
        else return 1e9;
    }
    int notTake = KnapRec(idx-1, coins, target);
    int take = 1e9;
    if(target>=coins[idx]){
        take = 1 + KnapRec(idx, coins, target-coins[idx]);
    }
    return min(take, notTake);
}

// memoization -- TC:O(n*target)  SC:O(n)+O(n*target)
int KnapMem(int idx, vector<int> &coins, int target, vector<vector<int>> &dp){
    if(idx==0){
        if(target%coins[0]== 0){return target/coins[0];}
        else return 1e9;
    }
    if(dp[idx][target]!=-1){return dp[idx][target];}
    int notTake = KnapMem(idx-1, coins, target, dp);
    int take = 1e9;
    if(target>=coins[idx]){
        take = 1 + KnapMem(idx, coins, target-coins[idx], dp);
    }
    return dp[idx][target] = min(take, notTake);
}

// tabulation
int sumTab(int idx, vector<int> &arr, int target){
    vector<vector<bool>> dp(idx+1, vector<bool>(target+1, -1));
    for(int i=0; i<=idx; i++){if(dp[i][target]==0){return true;}}
    if(idx==0){return dp[0][arr[0]]==true;}
    for(int i=1; i<idx; i++){
        for(int k=1; k<=target; k++){
            bool notTake = dp[idx-1][target];
            bool take = false;
            if(target>=arr[idx]){
                take = dp[idx-1][target-arr[idx]];
            }
        }
    }
    return dp[idx][target];
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

    // cout<<"Using tabulation: "<<sumTab(n-1, coins, target)<<"\n";
    return 0;
}