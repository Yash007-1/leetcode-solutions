class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {

        int n = s.size();
        int ones = 0;
        string ans;
        for (int i = 0; i < n; i++)
            if (s[i] == '1')
                ones++;
        if (ones < k)
            return ans;

        ones=0;    
        int st = 0;
        for (int i = 0; i < n; i++) {
            
            if(s[i]=='1')ones++;
            while (ones > k) {
                if(s[st]=='1')ones--;
                st++;
            }

            if (ones == k) {
                string curr;
                while (s[st] == '0') {
                    st++;
                }

                for (int j = st; j <= i; j++) {
                    curr.push_back(s[j]);
                }

                if (ans.size() == 0 || curr.size() < ans.size()) {
                    ans = curr;
                }

                else if (curr.size() == ans.size() && curr < ans) {
                    ans = curr;
                }
            }
        }

        return ans;
    }
};