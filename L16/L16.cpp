// Partition Set Into 2 Subsets With Min Absolute Sum Diff
/*
We are given an array ‘ARR’ with N positive integers. We need to partition the array into two 
subsets such that the absolute difference of the sum of elements of the subsets is minimum.

Return only the minimum absolute difference of the sum of elements of the two partitions.
*/

#include<bits/stdc++.h>
using namespace std;

// recursion -- TC:O(2^n)  SC:O(n)
int sumRec(int idx, vector<int> &arr, int target){
    if(target==0){return 1;}
    if(idx==0){return arr[0]==target;}
    bool notTake = sumRec(idx-1, arr, target);
    bool take = 0;
    if(target>=arr[idx]){
        take = sumRec(idx-1, arr, target-arr[idx]);
    }
    return take+notTake;
}

// memoization -- TC:O(n*target)  SC:O(n)+O(n*target)
int sumMem(int idx, vector<int> &arr, int target, vector<vector<int>> &dp){
    if(target==0){return 1;}
    if(idx==0){return arr[0]==target;}
    if(dp[idx][target]!=-1){return dp[idx][target];}
    bool notTake = sumRec(idx-1, arr, target);
    bool take = 0;
    if(target>=arr[idx]){
        take = sumRec(idx-1, arr, target-arr[idx]);
    }
    return dp[idx][target] = take+notTake;
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
    vector<int> arr(n,0);
    cout<<"Enter elements of array: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<"Array: ";printarray(arr, n);

    int target; cout<<"Enter target: ";cin>>target;
    cout<<"\nUsing Recursion: "<<sumRec(n-1, arr, target)<<endl;

    vector<vector<int>> dp(n, vector<int>(target+1, -1));
    cout<<"Using memoization: "<<sumMem(n-1, arr, target, dp)<<"\n";

    // cout<<"Using tabulation: "<<sumTab(n-1, arr, target)<<"\n";
    return 0;
}