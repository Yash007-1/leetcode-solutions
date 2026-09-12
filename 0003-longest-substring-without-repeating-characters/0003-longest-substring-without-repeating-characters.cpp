class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=0,n=s.size();
        
        vector<int>hash(256,-1);
        int i=0,j=0;
       
        while(j<n){
            if(hash[s[j]]!=-1){
            i=max(i,hash[s[j]]+1);
            }
             ans=max(ans,j-i+1);
            hash[s[j]]=j;
            j++;

        }
        return ans;
    }
};