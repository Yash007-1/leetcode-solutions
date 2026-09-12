class Solution {
public:
    int characterReplacement(string s, int k) {
        
       int ans=0;
       for(char curr='A';curr<='Z';curr++){
        int other=0;
        int n=s.size();
        int i=0,r=0;
        int currcount=0;
        int maxlen=0;
        
        while(r<n){
            
            if(s[r]==curr)currcount++;
            else other++;
            while(other>k){
                if(s[i]!=curr)other--;
                i++;
            }
            maxlen=max(maxlen,r-i+1);
            r++;
            
        }
        ans=max(ans,maxlen);
    }
    return ans;}

};