// Buy and Sell Stock – II
/*
We are given an array Arr[] of length n. It represents the price of a stock on ‘n’ days. The 
following guidelines need to be followed:

1. We can buy and sell the stock any number of times.
2. In order to sell the stock, we need to first buy it on the same or any previous day.
3. We can’t buy a stock again after buying it once. In other words, we first buy a stock and then 
sell it. After selling we can buy and sell again. But we can’t sell before buying and can’t buy 
before selling any previously bought stock.
*/

#include<bits/stdc++.h>
using namespace std;

// recursion
int BSRec(vector<int> &prices, int idx, int buy, int n){
    if(idx==n) return 0; //base case
        
    int profit;
    if(buy==0){// We can buy the stock
        profit = max(0+BSRec(prices,idx+1,0,n), -prices[idx]+BSRec(prices,idx+1,1,n));
    }
    if(buy==1){// We can sell the stock
        profit = max(0+BSRec(prices,idx+1,1,n), prices[idx]+BSRec(prices,idx+1,0,n));
    }
    return profit;
}

// memoization
int BSMem(vector<int> &prices, int idx, int buy, int n, vector<vector<int>> &dp){
    if(idx==n) return 0; //base case
    if(dp[idx][buy] != -1){return dp[idx][buy];}
    int profit;
    if(buy==0){// We can buy the stock
        profit = max(0+BSMem(prices,idx+1,0,n, dp), -prices[idx]+BSMem(prices,idx+1,1,n, dp));
    }
    if(buy==1){// We can sell the stock
        profit = max(0+BSMem(prices,idx+1,1,n, dp), prices[idx]+BSMem(prices,idx+1,0,n, dp));
    }
    return dp[idx][buy] = profit;
}

// tabulation
int BSTab(vector<int> &prices, int idx, int buy, int n){
    vector<vector<int>> dp(n+1, vector<int>(2, -1));
    dp[n][0] = dp[n][1] = 0;
    int profit;
    for(idx = n-1; idx>=0; idx--){
        for(buy=0; buy<2; buy++){
            if(buy==0){// We can buy the stock
            profit = max(0+dp[idx+1][0], -prices[idx]+dp[idx+1][1]);
        }
        if(buy==1){// We can sell the stock
            profit = max(0+dp[idx+1][1], prices[idx]+dp[idx+1][0]);
        }
        dp[idx][buy] = profit;
        }
    }
    return dp[0][0];
}

// driver code
int main(){
    int n; cout<<"Enter n: ";cin>>n;
    vector<int> prices(n, 0);
    for(int i=0; i<n; i++){
        cin>>prices[i];
    }

    cout<<"Using Recursion: "<<BSRec(prices, 0, 0, n)<<endl;

    vector<vector<int>> dp(n, vector<int>(2,-1));
    cout<<"Using Memoization: "<<BSMem(prices, 0, 0, n, dp)<<endl;

    cout<<"Using Tabulation: "<<BSTab(prices, 0, 0, n)<<endl;

    return 0;
}