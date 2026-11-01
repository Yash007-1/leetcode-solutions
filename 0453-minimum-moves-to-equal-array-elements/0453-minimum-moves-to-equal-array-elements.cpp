class Solution {
public:
    int minMoves(vector<int>& nums) {
        int  sum=0,mine=INT_MAX;;
        for(auto i:nums){
            mine=min(mine,i);
            sum+=i;
        }
        

        return sum-nums.size()*mine;
        
    }
};