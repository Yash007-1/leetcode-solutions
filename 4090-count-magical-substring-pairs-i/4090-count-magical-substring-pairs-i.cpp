class Solution {
public:
    
    int countMagicalPairs(string s) {
        int n = s.size();
        int count = 0;
       
  
        vector<vector<int>>dp(n,vector(27,0));
      
           for (int i = 0; i < n; i++) {
           set<char>m;
           for(int j=i;j<n;j++){
            m.insert(s[j]);
            dp[i][m.size()]++;
           }
        }
        
        for (int i = 0; i < n - 1; i++) {
            set<char>m;
            for (int j = i; j < n - 1; j++) {
                m.insert(s[j]);
                int sz=m.size();
              count+=dp[j+1][sz];

            
                }
            }
        
        return count;
    }
};
