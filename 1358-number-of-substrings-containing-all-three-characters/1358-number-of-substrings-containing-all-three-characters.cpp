class Solution {
public:
    int lesser(string s){
        int n=s.size();
         int a=0,b=0,c=0;
        int l=0;
        int ans=0;
        for(int r=0;r<n;r++){
            if(s[r]=='a')a++;
            else if(s[r]=='b')b++;
            else c++;
            while(a>0&&b>0&&c>0){
               if(s[l]=='a')a--;
            else if(s[l]=='b')b--;
            else c--; 
            l++;
            }
            ans+=r-l+1;
        }
        return ans;
    }
    int numberOfSubstrings(string s) {
       int atmost=0;
        int n=s.size();
        for(int r=0;r<n;r++){
           
            atmost+=r+1;
            
        }
        return atmost-lesser(s);
    }
};