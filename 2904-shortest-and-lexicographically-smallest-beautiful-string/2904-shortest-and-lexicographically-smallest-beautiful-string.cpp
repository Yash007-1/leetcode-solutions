class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        unordered_map<char, int> m;
        int n = s.size();
int ones=0;
        string ans;
        for (int i = 0; i < n; i++)
            if(s[i]=='1')ones++;
        if (ones < k)
            return ans;
        int st = 0;
        for (int i = 0; i < n; i++) {
            string curr;
             m[s[i]]++;
             while(m['1']>k){
                m[s[st]]--;
                st++;
             }
            if (m['1'] == k) {
               
                    while(s[st]=='0'){
                    m[s[st]]--;
                    st++;
                    }

                
                
                for (int j = st; j <= i; j++) {
                    curr.push_back(s[j]);
                }
                
                if (ans.size() == 0 || curr.size() < ans.size()){
                    ans = curr;}
                
                    
                       else  if (curr.size()==ans.size()&&curr < ans) {
                            ans = curr;
                            
                        }
                    
                }
            }
           
        
        return ans;
    }
};