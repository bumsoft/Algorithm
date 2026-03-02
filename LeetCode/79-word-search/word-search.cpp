class Solution {
public:
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};

    bool back_tracking(int now, vector<vector<char>>& board, int x, int y, string& word)
    {
        if(now == word.size()-1) return 1;

        for(int i=0;i<4;i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= board.size() ||ny < 0 || ny >= board[0].size()) continue;
            if(board[nx][ny] == '0') continue;
            if(board[nx][ny] != word[now+1]) continue;
            char t = board[nx][ny];
            board[nx][ny] = '0';
            bool r = back_tracking(now+1, board, nx, ny, word);
            if(r) return 1;
            board[nx][ny] = t;
        }
        return 0;
    }

    bool exist(vector<vector<char>>& board, string word) {

        char start = word[0];
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[i].size();j++)
            {
                if(board[i][j] == start)
                {
                    board[i][j] = '0';
                    if(back_tracking(0,board, i,j, word)) return 1;
                    board[i][j] = start;
                }
            }
        }
        return 0;
    }
};