class Solution {
public:
   bool f(vector<vector<char>>&board,int i,int j,int idx,string word){
        
        if (i < 0 || i >= board.size() ||
            j < 0 || j >= board[0].size() ||
            board[i][j] != word[idx])
            return false;
            if(idx==word.size()-1)return true;
        int delr[]={-1,0,1,0};
        bool found=false;
        int delc[]={0,-1,0,1};
        
                  char temp=board[i][j];
                  
                  board[i][j]='.';
        for(int k=0;k<4;k++){
            int nrow=i+delr[k];
            int ncol=j+delc[k];
            if(nrow>=0&&nrow<board.size()&&ncol>=0&&ncol<board[0].size()&&board[nrow][ncol]!='.'){
                
                
                  found= found||f(board,nrow,ncol,idx+1,word);
                  
                
            }}
            board[i][j]=temp;
     return found;   
 }

    bool exist(vector<vector<char>>& board, string word) {

       for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (f(board, i, j, 0, word))
                    return true;
            }
        }

        return false;
    }
};