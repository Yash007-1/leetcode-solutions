class Solution {
public:
    
    string reverseParentheses(string s) {
        string ans;
        int n=s.size();
        stack<int>st;
        
   for(int i=0;i<n;i++){

    if(s[i]==')'){
        int prev=st.top();
        st.pop();
        reverse(s.begin()+prev+1,s.begin()+i);
        
    }
     else if(s[i]=='(')st.push(i);
   }
   for(int i=0;i<n;i++){
    if(s[i]!='('&&s[i]!=')'){
        ans.push_back(s[i]);
    }
   }
    return ans;}
};