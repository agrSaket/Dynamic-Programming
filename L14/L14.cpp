// Subset sum equal to target
/*
We are given an array ‘ARR’ with N positive integers. We need to find if there is a subset 
in “ARR” with a sum equal to K. If there is, return true else return false.
*/

#include<bits/stdc++.h>
using namespace std;

// recursion -- TC:O(2^n)  SC:O(n)
int sumRec(int idx, vector<int> &arr, int target){
    if(target==0){return true;}
    if(idx==0){return arr[idx]==target;}
    bool notTake = sumRec(idx-1, arr, target);
    bool take = false;
    if(target>=arr[idx]){
        take = sumRec(idx-1, arr, target-arr[idx]);
    }
    return take||notTake;
}

// memoization -- TC:O(n*target)  SC:O(n)+O(n*target)
int sumMem(int idx, vector<int> &arr, int target, vector<vector<int>> &dp){
    if(target==0){return true;}
    if(idx==0){return arr[idx]==target;}
    if(dp[idx][target]!=-1){return dp[idx][target];}
    bool notTake = sumRec(idx-1, arr, target);
    bool take = false;
    if(target>=arr[idx]){
        take = sumRec(idx-1, arr, target-arr[idx]);
    }
    return dp[idx][target] = take||notTake;
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
void printarray(vector<int> &arr){
    int n = arr.size();
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
    cout<<"Array: ";printarray(arr);

    int target; cout<<"Enter target: "; cin>>target;
    string res = (sumRec(n-1, arr, target)==1)?"Yes":"No";
    cout<<"Using Recursion: "<<res<<endl;

    vector<vector<int>> dp(n, vector<int>(target+1, -1));
    res = (sumMem(n-1, arr, target, dp)==1)?"Yes":"No";
    cout<<"Using memoization: "<<res<<"\n";

    res = (sumTab(n-1, arr, target)==1)?"Yes":"No";
    cout<<"Using tabulation: "<<res<<"\n";
    return 0;
}