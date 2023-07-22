// Count Partitions with Given Difference
/*
Given an array 'ARR', partition it into two subsets (possibly empty) such that their union is
the original array. Let the sum of the elements of these two subsets be 'SI' and 'S2'.
Given a difference count the number of partitions in which 'SI' is greater than or equal to 'S2' 
and the difference between 'SI' and 'S2' is equal to Since the answer may be too large, return it 
modulo '10^9+7'.
*/

#include<bits/stdc++.h>
using namespace std;
int mod =(int)1e9+7;

// recursion -- TC:O(2^n)  SC:O(n)
int sumRec(int idx, vector<int> &arr, int target){
    if(target==0){return 1;}
    if(idx==0){return arr[0]==target;}
    int notTake = sumRec(idx-1, arr, target);
    int take = 0;
    if(target>=arr[idx]){
        take = sumRec(idx-1, arr, target-arr[idx]);
    }
    return take+notTake;
}

// memoization -- TC:O(n*target)  SC:O(n)+O(n*target)
int sumMem(int idx, vector<int> &arr, int target, vector<vector<int>> &dp){
    if(idx == 0){
        if(target==0 && arr[0]==0)
            return 2;
        if(target==0 || target == arr[0])
            return 1;
        return 0;
    }
    if(dp[idx][target]!=-1){return dp[idx][target];}
    int notTake = sumMem(idx-1, arr, target, dp);
    int take = 0;
    if(target>=arr[idx]){
        take = sumMem(idx-1, arr, target-arr[idx], dp);
    }
    return dp[idx][target] = (take+notTake)%mod;
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

// sum Array
int sumArray(vector<int> &arr, int n){
    int ans = 0;
    for(int i=0; i<n; i++){
        ans += arr[i];
    }
    return ans;
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
    int target; cout<<"Enter difference: ";cin>>target;

    int ans = sumArray(arr, n);
    cout<<"\nSum of elements of array: "<<ans<<endl;

    if(ans-target<0 || (ans-target)%2){cout<<false;}
    else{
        int s2 = (ans-target)/2;
        cout<<"\nUsing Recursion: "<<sumRec(n-1, arr, s2)<<endl;

        vector<vector<int>> dp(n, vector<int>(s2+1, -1));
        cout<<"Using memoization: "<<sumMem(n-1, arr, s2, dp)<<"\n";

        // cout<<"Using tabulation: "<<sumTab(n-1, arr, target)<<"\n";
    }
    return 0;
}