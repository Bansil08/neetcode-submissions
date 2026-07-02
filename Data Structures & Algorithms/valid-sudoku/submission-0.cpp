class Solution {
public:
    
    
    bool isValidSudoku(vector<vector<char>>& board) {
        int n=board.size();
        set<char>r[9],c[9],b[9];

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                char ch=board[i][j];
                if(ch=='.')continue;
                int bo=(i/3)*3+(j/3);
                if(r[i].count(ch) || c[j].count(ch) || b[bo].count(ch))return false;

                r[i].insert(ch);
                c[j].insert(ch);
                b[bo].insert(ch);
            }
        }
        return true;
    }
};
