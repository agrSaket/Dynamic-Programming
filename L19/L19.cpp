// 0/1 Knapsack
/*
A thief wants to rob a store. He is carrying a bag of capacity W. The store has ‘n’ items. 
Its weight is given by the ‘wt’ array and its value by the ‘val’ array. He can either include 
an item in its knapsack or exclude it but can’t partially have it as a fraction. We need to find 
the maximum value of items that the thief can steal.
*/

#include<bits/stdc++.h>
using namespace std;

// recursion -- TC:O(2^n)  SC:O(n)
int KnapRec(int idx, vector<int> &wt, vector<int> &val, int target){
    if(idx==0){
        if(wt[0]<=target){return val[0];}
        else return 0;
    }
    int notTake = KnapRec(idx-1, wt, val, target);
    int take = INT_MIN;
    if(target>=wt[idx]){
        take = val[idx] + KnapRec(idx-1, wt, val, target-wt[idx]);
    }
    return max(take, notTake);
}

// memoization -- TC:O(n*target)  SC:O(n)+O(n*target)
int KnapMem(int idx, vector<int> &wt, vector<int> &val, int target, vector<vector<int>> &dp){
    if(idx==0){
        if(wt[0]<=target){return val[0];}
        else return 0;
    }
    if(dp[idx][target]!=-1){return dp[idx][target];}
    int notTake = KnapMem(idx-1, wt, val, target, dp);
    int take = 0;
    if(target>=wt[idx]){
        take = val[idx] + KnapMem(idx-1, wt, val, target-wt[idx], dp);
    }
    return dp[idx][target] = max(take, notTake);
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
    vector<int> wt(n,0);         // = {1,2,4,5}
    vector<int> val(n,0);        // = {5,4,8,6}
    cout<<"Enter elements of weight array: ";
    for(int i=0; i<n; i++){
        cin>>wt[i];
    }
    cout<<"\nEnter elements of val array: ";
    for(int i=0; i<n; i++){
        cin>>val[i];
    }
    cout<<"Weight array: ";printarray(wt, n);
    cout<<"Value array: ";printarray(val, n);
    int target; cout<<"Enter max weight: ";cin>>target;

    cout<<"\nUsing Recursion: "<<KnapRec(n-1, wt, val, target)<<endl;

    vector<vector<int>> dp(n, vector<int>(target+1, -1));
    cout<<"Using memoization: "<<KnapMem(n-1, wt, val, target, dp)<<"\n";

    // cout<<"Using tabulation: "<<sumTab(n-1, wt, target)<<"\n";
    return 0;
}