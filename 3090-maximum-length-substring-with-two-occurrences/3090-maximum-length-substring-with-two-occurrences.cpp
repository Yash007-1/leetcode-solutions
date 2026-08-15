class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char,int>m;
        int i=0,j=0;
        int len=0;
 m[s[j]]++;
        while(j<s.size()){
            while(m[s[j]]>2){
                m[s[i]]--;
                i++;
            }
            len=max(len,j-i+1);
            j++;
            if(j<s.size())m[s[j]]++;
        }
    return len;}
};