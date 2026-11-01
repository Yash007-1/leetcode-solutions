class Solution {
public:
    int concat(int n1,int n2){
        string s1=to_string(n1);
        string s2=to_string(n2);
        string ans=s1+s2;
        return stoi(ans);
    }
    int minMergedInteger(vector<int>& nums) {
        int ans=INT_MAX;
        for(int i=0;i<nums.size()-1;i+=2){
            ans=min(ans,concat(nums[i],nums[i+1]));
        }
    return ans;}
};