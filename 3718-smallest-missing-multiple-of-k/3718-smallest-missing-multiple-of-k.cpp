class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int prev=0;
        sort(nums.begin(),nums.end());
        for(auto i:nums){
            if(i%k==0){
                if(i/k==prev)continue;
                else if(i/k!=prev+1)break;
                else prev+=1;
            }
        }
    return k*(prev+1);}
};