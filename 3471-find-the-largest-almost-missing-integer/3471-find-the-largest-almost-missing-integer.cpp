class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int i=0,j=k-1;
        int mx=nums[0];
        
        for(auto x:nums)mx=max(x,mx);
        
        vector<int>freq(mx+1,0);
        while(j<nums.size()){
            unordered_map<int,int>s;
             for(int p=i;p<=j;p++){
                s[nums[p]]=1;

             }
             for(auto x:s){
                if(x.second==1)freq[x.first]++;
             }
             i++;
             j++;
        }
        int almost=-1;
        for(int p=0;p<freq.size();p++){
            if(freq[p]==1)almost=max(almost,p);        }
    return almost;}
};