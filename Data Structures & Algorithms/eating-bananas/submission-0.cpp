#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    ll summ(vector<int> &arr, int div) {
    int n=arr.size();
    ll sum=0;
    for(int i=0;i<n;i++)
        sum +=ceil(((double)arr[i])/(double)(div));
    return sum;
    }
    int minEatingSpeed(vector<int>& arr,int limit) {
    int n=arr.size();
    if(n>limit) 
    return -1;
    int low=1,high=*max_element(arr.begin(),arr.end());
    while (low<=high){
        int mid=(low+high)/2;
        ll s=summ(arr,mid);
        if (s<=limit)
            high=mid-1;
        else 
            low=mid+1;
    }
    return low;
    }
};