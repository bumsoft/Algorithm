#include <bits/stdc++.h>
// 정규화: (r, c) → (r - min_r, c - min_c) = 모든 r, c의 최솟값이 0
// 정규화된 상태에서 시계방향 90 회전
// (r,c) -> (c, max_r - r)
// 정규화된 상태에서 반시계방향 90 회전
// (r,c) -> (max_c - c, r)

using namespace std;

int dx[] = {1,0,-1,0};
int dy[] = {0,-1,0,1};

bool vis1[51][51];
bool vis2[51][51];
vector<vector<pair<int,int>>> board_pieces;
vector<vector<pair<int,int>>> table_pieces[4];


void normalize(vector<pair<int,int>>& piece)
{
    int min_r = 100;
    int min_c = 100;
    for(int i=0;i<piece.size();i++)
    {
        min_r = min(min_r, piece[i].first);
        min_c = min(min_c, piece[i].second);
    }
    for(int i=0;i<piece.size();i++)
    {
        piece[i].first -= min_r;
        piece[i].second -= min_c;
    }
}

// origin을 회전시켜 target에 저장 후 정규화까지
void rotate(vector<pair<int,int>>& origin, vector<vector<pair<int,int>>>& target)
{
    vector<pair<int,int>> V;
    // (r,c) -> (c, max_r - r)
    int max_r = -1;
    for(int i=0;i<origin.size();i++)
    {
        max_r = max(max_r, origin[i].first);
    }
    for(int i=0;i<origin.size();i++)
    {
        V.push_back({origin[i].second, max_r - origin[i].first});
    }
    normalize(V);
    target.push_back(V);
}

int verify(vector<pair<int,int>>& a, vector<pair<int,int>>& b)
{
    if(a.size() != b.size()) return 0;
    for(int i=0;i<a.size();i++)
    {
        if(a[i] != b[i]) return 0;
    }
    return 1;
}


int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    int answer = 0;
    int n = game_board.size();
    int m = game_board[0].size();
    // game_board에서 빈칸 추출
    for(int i=0;i<game_board.size();i++)
    {
        for(int j=0;j<game_board[i].size();j++)
        {
            if(vis1[i][j]) continue;
            if(game_board[i][j] == 1) continue;
            
            vector<pair<int,int>> V;
            vis1[i][j] = 1;
            queue<pair<int,int>> Q;
            Q.push({i,j});
            while(!Q.empty())
            {
                int x = Q.front().first;
                int y = Q.front().second;
                Q.pop();
                V.push_back({x,y});
                for(int t=0;t<4;t++)
                {
                    int nx = x + dx[t];
                    int ny = y + dy[t];
                    if(nx<0 || nx >=n || ny <0 || ny >=m ) continue;
                    if(vis1[nx][ny]) continue;
                    if(game_board[nx][ny] == 1) continue;
                    vis1[nx][ny] = 1;
                    Q.push({nx,ny});
                }
            }
            board_pieces.push_back(V);
        }
    }
    //추출한 컴포넌트들 정규화
    for(int i=0;i<board_pieces.size();i++)
    {
        normalize(board_pieces[i]);
        sort(board_pieces[i].begin(), board_pieces[i].end());
    }
    
    // table에서 빈칸 추출([0]에 저장 후, 회전시켜서 1~3에도 저장하기)
    // table에서 빈칸 추출
    for(int i=0;i<table.size();i++)
    {
        for(int j=0;j<table[i].size();j++)
        {
            if(vis2[i][j]) continue;
            if(table[i][j] == 0) continue;
            
            vector<pair<int,int>> V;
            vis2[i][j] = 1;
            queue<pair<int,int>> Q;
            Q.push({i,j});
            while(!Q.empty())
            {
                int x = Q.front().first;
                int y = Q.front().second;
                Q.pop();
                V.push_back({x,y});
                for(int t=0;t<4;t++)
                {
                    int nx = x + dx[t];
                    int ny = y + dy[t];
                    if(nx<0 || nx >=n || ny <0 || ny >=m ) continue;
                    if(vis2[nx][ny]) continue;
                    if(table[nx][ny] == 0) continue;
                    vis2[nx][ny] = 1;
                    Q.push({nx,ny});
                }
            }
            table_pieces[0].push_back(V);
        }
    }
    //[0] 저장 및 정규화
    for(int i=0;i<table_pieces[0].size();i++)
    {
        normalize(table_pieces[0][i]);
    }
    //[1] 저장 및 정규화 -> [2] 저장 및 정규화 -> [3] 저장 및 정규화
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<table_pieces[i].size();j++)
        {
            rotate(table_pieces[i][j], table_pieces[i+1]);
        }
    }
    for(int i=0;i<table_pieces[0].size();i++)
    {
        sort(table_pieces[0][i].begin(), table_pieces[0][i].end());
        sort(table_pieces[1][i].begin(), table_pieces[1][i].end());
        sort(table_pieces[2][i].begin(), table_pieces[2][i].end());
        sort(table_pieces[3][i].begin(), table_pieces[3][i].end());
    }
    
    vector<bool> used(table_pieces[0].size(), 0);
    // board_pieces와 table_pieces를 비교
    for(int i=0;i<board_pieces.size();i++)
    {
        // board_pieces[i] 와 table_pieces[0][0], [1][0], [2][0], [3][0]을 비교하기
        for(int t=0;t<table_pieces[0].size();t++)
        {
            if(used[t]) continue;
            int max_ = 0;
            max_ = max(max_, verify(table_pieces[0][t], board_pieces[i]));
            max_ = max(max_, verify(table_pieces[1][t], board_pieces[i]));
            max_ = max(max_, verify(table_pieces[2][t], board_pieces[i]));
            max_ = max(max_, verify(table_pieces[3][t], board_pieces[i]));
            if(max_)
            {
                used[t] = 1;
                answer += board_pieces[i].size();
                break;
            }
        }
        
    }
    
    return answer;
}