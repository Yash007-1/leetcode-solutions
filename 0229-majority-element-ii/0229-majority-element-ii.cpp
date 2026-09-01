class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int t=nums.size()/3;
        unordered_map<int,int>m;
        for(auto i:nums){
            m[i]++;
        }
    vector<int>ans;
    for(auto x:m){
        if(x.second>t)ans.push_back(x.first);
    }
    return ans;
    }
};