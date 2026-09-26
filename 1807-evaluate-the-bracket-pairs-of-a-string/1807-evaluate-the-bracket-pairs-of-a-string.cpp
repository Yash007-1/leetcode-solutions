class Solution {
public:
    string  bsearch(string a,vector<vector<string>>&k){
        string res="?";
        int  n=k.size();
        int st=0,end=n-1;
        while(st<=end){
            int mid=(st+end)/2;
            if(a==k[mid][0]){
                return k[mid][1];

            }
            else if(a>k[mid][0]){
               st=mid+1;
            }
            else{
                end=mid-1;
            }
          
        }  return res;
    }
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string ,string>m;
        for(auto i:knowledge){
            m[i[0]]=i[1];
        }
        string ans;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]!='('){
                ans.push_back(s[i]);
            }
            if(s[i]=='('){
                int x=i;
                while(s[x]!=')')x++;
                if(m.find(s.substr(i+1,x-i-1))!=m.end())
                ans+=m[s.substr(i+1,x-i-1)];
                else ans+="?";
                i=x;
            }

        }
    return ans;}
};