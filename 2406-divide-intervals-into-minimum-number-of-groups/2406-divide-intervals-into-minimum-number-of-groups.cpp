
class Solution {
   
    
public:
    int minGroups(vector<vector<int>>& intervals) {
     
        vector<int>st;
        vector<int>end;
        for(auto i:intervals){st.push_back(i[0]);end.push_back(i[1]);}
        sort(st.begin(),st.end());
    sort(end.begin(),end.end());

     int grp=0;
     int e=0;
     for(auto s:st){
        if(s>end[e])e++;
        else grp++;
     }
       return grp;

    }
};