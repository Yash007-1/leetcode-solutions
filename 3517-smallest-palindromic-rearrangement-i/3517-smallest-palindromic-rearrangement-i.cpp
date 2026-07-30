class Solution {
public:
    string smallestPalindrome(string s) {
        if(s.size()==1)return s;

        int mid=s.size()/2;
        sort(s.begin(),s.begin()+mid);
        sort(s.end()-mid,s.end(),greater<int>());
    return s;
    }
};