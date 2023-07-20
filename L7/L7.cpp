// 2D dp
// Ninja's Training
/*
Problem Statement - 
Ninja is planing this 'N' days-long training schedule. Each day, he can perform any one of these
three activities. (Running. Fighting Practice or Learning New Moves), Each activity has some 
merit points on each day. As Ninja has to improve all his Skills. he can't do the same activity 
in two consecutive days. Can you help Ninja find out the maximum merit points Ninja can earn?

You are given a 2D array Of Size N*3 'POINTS' with the points corresponding to each day ond
activity. Your task is to calculate the maximum of merit that Ninja can earn.
*/

#include<bits/stdc++.h>
using namespace std;

// recursion
int TwodRec(int day, int last, vector<vector<int>>& arr){
    if(day==0){
        int maxi = 0;
        for(int task=0; task<3; task++){
            if(task!=last){
                maxi = max(maxi, arr[0][task]);
            }
        }
        return maxi;
    }
    int maxi=0;
    for(int task=0; task<3; task++){
        if(task!=last){
            int point = arr[day][task] + TwodRec(day-1, task, arr);
            maxi = max(maxi, point);
        }
    }
    return maxi;
}

// memoization
int TwodMem(int day, int last, vector<vector<int>>& arr, vector<vector<int>>& dp){
    if(day==0){
        int maxi = 0;
        for(int task=0; task<3; task++){
            if(task!=last){
                maxi = max(maxi, arr[0][task]);
            }
        }
        return maxi;
    }
    if(dp[day][last] != -1){return dp[day][last];}
    int maxi=0;
    for(int task=0; task<3; task++){
        if(task!=last){
            int point = arr[day][task] + TwodMem(day-1, task, arr, dp);
            maxi = max(maxi, point);
        }
    }
    return dp[day][last] = maxi;
}

// tabulation


// driver code
int main(){
    vector<vector<int>> arr {{18, 11, 19}, {4, 13, 7}, {1, 8, 13}};
    int n = arr.size();
    cout<<"Using recursion: "<<TwodRec(n-1, 3, arr)<<endl;

    vector<vector<int>> dp(n, vector<int>(4, -1));
    cout<<"Using memoization: "<<TwodMem(n-1, 3, arr, dp)<<endl;

    return 0;
}