// house robber
#include<bits/stdc++.h>
using namespace std;

// recursion


// memoization


// tabulation


// space optimised
int sumSp(vector<int> &arr){
    int idx = arr.size();
    int prev = arr[0];
    int prev2 = 0;
    for(int i=1; i<idx; i++){
        int pick = arr[idx];
        if(i>1){pick += prev2;}
        int notpick = 0 + prev;
        int curr = max(pick, notpick);
        prev2 = prev;
        prev = curr;
    }
    return prev;
}

int main(){
    vector<int> arr{2, 3, 2};
    int n = arr.size();
    if(n==1){return arr[0];}
    vector<int> temp1, temp2;
    for(int i=0; i<n; i++){
        if(i!=0){temp1.push_back(arr[i]);}
        if(i!=n-1){temp2.push_back(arr[i]);}
    }
    cout<<max(sumSp(temp1), sumSp(temp2)); 
    return 0;
}