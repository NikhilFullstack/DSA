// Very imp
#include<iostream>
#include<deque>
using namespace std;
#include<vector>
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            int t=nums[i];
            while(!q.empty() && nums[q.back()]<=t){
                q.pop_back();
            }
            q.push_back(i);
            if(i==k-1){
                ans.push_back(nums[q.front()]);
            }
            if(i/k>=1){

                int rem = i%k;
                    if(!q.empty() && i-k>=q.front())
                    q.pop_front();
                
                ans.push_back(nums[q.front()]);
            }
        }
        return ans;
    }
};