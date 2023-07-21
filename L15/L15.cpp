// Partition Equal Subset Sum
/*
We are given an array ‘ARR’ with N positive integers. We need to find if we can partition the 
array into two subsets such that the sum of elements of each subset is equal to the other.
*/
/*
According to the question:
Sum of elements of S1 + sum of elements of S2 = sum of elements of S.
Sum of elements of S1 = sum of elements of S2.
These two conditions imply that S1 = S2 = (S/2). 

Now, 
If S (sum of elements of the input array) is odd , there is no way we can divide it into two 
equal halves, so we can simply return false.
If S is even, then we need to find a subsequence in the input array whose sum is equal to S/2 
because if we find one subsequence with sum S/2, the remaining elements sum will be automatically
S/2. So, we can partition the given array. Hence we return true.
*/

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

    int ans = sumArray(arr, n);
    cout<<"\nSum of elements of array: "<<ans<<endl;
    if(ans%2!=0){cout<<"False";}
    else{
        int target = ans/2; 
        cout<<"Target: "<<target;
        string res = (sumRec(n-1, arr, target)==1)?"Yes":"No";
        cout<<"\nUsing Recursion: "<<res<<endl;

        vector<vector<int>> dp(n, vector<int>(target+1, -1));
        res = (sumMem(n-1, arr, target, dp)==1)?"Yes":"No";
        cout<<"Using memoization: "<<res<<"\n";

        res = (sumTab(n-1, arr, target)==1)?"Yes":"No";
        cout<<"Using tabulation: "<<res<<"\n";
    }
    return 0;
}