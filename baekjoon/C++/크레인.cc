#include <bits/stdc++.h>
using namespace std;

vector<stack<int>> stacks;

void showBoard(vector<vector<int>>& board)
{
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[0].size(); ++j)
            cout << board[i][j] << " ";
        cout << endl;
    }
}

void setStacks(vector<vector<int>>& board)
{
    stacks.assign(board[0].size() + 1, stack<int>());

    for (int i = 0; i < board[0].size(); ++i) 
    {
        for (int j = board.size() - 1; j >= 0; --j)  // 역순으로 쌓기
        {
            if (board[j][i] != 0)
                stacks[i + 1].push(board[j][i]);
        }
    }
}

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    
    setStacks(board);
    deque<int> selected;

    for (const int dir : moves)
    {
        if (stacks[dir].empty())
            continue;

        int doll = stacks[dir].top();
        stacks[dir].pop();

        if (!selected.empty() && selected.back() == doll) 
        {
            selected.pop_back();
            answer += 2;
        } 
        else 
        {
            selected.push_back(doll);
        }
    }

    return answer;
}