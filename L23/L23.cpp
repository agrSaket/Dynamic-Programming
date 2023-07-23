// Unbounded Knapsack
/*
A thief wants to rob a store. He is carrying a bag of capacity W. The store has ‘n’ items of 
infinite supply. Its weight is given by the ‘wt’ array and its value by the ‘val’ array. He can 
either include an item in its knapsack or exclude it but can’t partially have it as a fraction. 
We need to find the maximum value of items that the thief can steal. He can take a single item 
any number of times he wants and put it in his knapsack.
*/

#include<bits/stdc++.h>
using namespace std;

// recursion -- TC:O(2^n)  SC:O(n)
int KnapRec(int idx, vector<int> &weight, vector<int> &val, int target){
    if(idx==0){
        return ((target/weight[0])*val[0]);
    }
    int notTake = KnapRec(idx-1, weight, val, target);
    int take = INT_MIN;
    if(target>=weight[idx]){
        take = val[idx] + KnapRec(idx, weight, val, target-weight[idx]);
    }
    return max(take, notTake);
}

// memoization -- TC:O(n*target)  SC:O(n)+O(n*target)
int KnapMem(int idx, vector<int> &weight, vector<int> &val, int target, vector<vector<int>> &dp){
    if(idx==0){
        return ((target/weight[0])*val[0]);
    }
    if(dp[idx][target]!=-1){return dp[idx][target];}
    int notTake = KnapMem(idx-1, weight, val, target, dp);
    int take = INT_MIN;
    if(target>=weight[idx]){
        take = val[idx] + KnapMem(idx, weight, val, target-weight[idx], dp);
    }
    return dp[idx][target] = max(take, notTake);
}

// tabulation
int sumTab(int n, vector<int> &weight, vector<int> &val, int target){
    vector<vector<int>> dp(n, vector<int>(target+1, 0));
    for(int i=weight[0]; i<=target; i++){
        dp[0][i] = ((int)i/weight[0])*val[0];
    }

    for(int i=1; i<n; i++){
        for(int k=0; k<=target; k++){
            int notTake = dp[i-1][k];
            int take = INT_MIN;
            if(k>=weight[i]){
                take = val[i] + dp[i][k-weight[i]];
            }
            dp[i][k] = max(notTake, take);
        }
    }
    return dp[n-1][target];
}

// space optimised
int sumSp(int n, vector<int> &weight, vector<int> &val, int target){
    vector<int> prev(target+1, 0);
    vector<int> curr(target+1, 0);
    for(int i=weight[0]; i<=target; i++){
        prev[i] = ((int)i/weight[0])*val[0];
    }

    for(int i=1; i<n; i++){
        for(int k=0; k<=target; k++){
            int notTake = prev[k];
            int take = INT_MIN;
            if(k>=weight[i]){
                take = val[i] + curr[k-weight[i]];
            }
            curr[k] = max(notTake, take);
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
    vector<int> weight(n,0);         // = {2,4,6}
    cout<<"Enter elements of weight array: ";
    for(int i=0; i<n; i++){
        cin>>weight[i];
    }
    vector<int> val(n,0);         // = {5,11,13}
    cout<<"Enter elements of val array: ";
    for(int i=0; i<n; i++){
        cin>>val[i];
    }

    cout<<"Weight array: ";printarray(weight, n);
    cout<<"Value array: ";printarray(val, n);
    int target; cout<<"Enter target: ";cin>>target;

    cout<<"\nUsing Recursion: "<<KnapRec(n-1, weight, val, target)<<endl;

    vector<vector<int>> dp(n, vector<int>(target+1, -1));
    cout<<"Using memoization: "<<KnapMem(n-1, weight, val, target, dp)<<"\n";

    cout<<"Using tabulation: "<<sumTab(n, weight, val, target)<<"\n";
    
    cout<<"Using space optimisation: "<<sumSp(n, weight, val, target)<<"\n";
    return 0;
}