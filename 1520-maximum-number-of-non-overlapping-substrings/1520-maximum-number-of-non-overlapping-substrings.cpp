class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        vector<int> first(26, -1);
        vector<int> last(26, -1);
        vector<int> freq(26, 0);
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (first[s[i] - 'a'] == -1)
                first[s[i] - 'a'] = i;
            freq[s[i] - 'a']++;
        }
        for (int i = n - 1; i >= 0; i--) {
            if (last[s[i] - 'a'] == -1)
                last[s[i] - 'a'] = i;
        }
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++) {
            if (first[s[i] - 'a'] != i)
                continue;
            int l = i;
            int r = last[s[i] - 'a'];
            bool ok = true;
            for (int j = l; j <= r; j++) {
                int x = s[j] - 'a';
                if (first[x] < l) {
                    ok = false;
                    break;
                }
                r = max(r, last[x]);
            }
            if (ok)
                v.push_back({l, r});
        }
        sort(
                v.begin(), v.end(), [](pair<int, int>& a, pair<int, int>& b) {
                    return a.second < b.second;
                });
        vector<string> ans;
        int prev = -1;
        for (auto p : v) {
            if (p.first > prev) {
                ans.push_back(s.substr(p.first, p.second - p.first + 1));
                prev = p.second;
            }
        }
        return ans;
    }
};