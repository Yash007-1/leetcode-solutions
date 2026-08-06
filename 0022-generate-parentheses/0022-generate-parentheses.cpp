class Solution {
public:
vector<string>ans;
void helper(int n,int open,int close,string &curr){
      if(curr.size()==2*n){
        ans.push_back(curr);
        return ;
      }
      if(open<n){
       curr.push_back('(');
       helper(n,open+1,close,curr);
       curr.pop_back();
      }
      if(close<open){
               curr.push_back(')');
               helper(n,open,close+1,curr);
               curr.pop_back();
      }
}
    vector<string> generateParenthesis(int n) {
        string curr;
        helper(n,0,0,curr);
        return ans;
    }
};