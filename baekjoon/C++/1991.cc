#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;

vector<vector<char>> adj;
vector<bool> visited;
int n;


int char_to_int(char c) 
{
    return c - 'A' + 1;
}

void input() noexcept 
{
    cin >> n;
    
    // init container
    adj.assign(n+1, vector<char>());
    char r, c1, c2;

    for (int i = 1; i <= n; ++i) {
        cin >> r >> c1 >> c2;
        
        adj[char_to_int(r)].push_back(c1);
        adj[char_to_int(r)].push_back(c2);
    }
}

void preorder(char c)
{

    if (c == '.')
        return ;

    cout << c;
    visited[char_to_int(c)] = true;

    for (char n_char: adj[char_to_int(c)])
        if (!visited[char_to_int(n_char)])
            preorder(n_char);
}

void postorder(char c)
{
    if (c == '.')
        return ;
    visited[char_to_int(c)] = true;

    for (char n_char: adj[char_to_int(c)])
        if (!visited[char_to_int(n_char)])
            postorder(n_char);
    
    cout << c;
}

void inorder(char c)
{
    if (c == '.')
        return ;
    visited[char_to_int(c)] = true;

    char left_child = adj[char_to_int(c)][0];
    char right_child = adj[char_to_int(c)][1];

    if (left_child == '.' && right_child == '.')
    {
        cout << c;
        return ;
    }

    else if (left_child != '.' && right_child != '.')
    {
        inorder(left_child);
        cout << c;
        inorder(right_child);
        
        return ;
    }

    else if (left_child != '.' && right_child == '.')
    {
        inorder(left_child);
        cout << c;

        return ;
    }

    else if (left_child == '.' && right_child != '.')
    {
        cout << c;
        inorder(right_child);
        
        return ;
    }
}


void solve()
{
    visited.assign(n+1, false);
    preorder('A');
    cout << endl;

    visited.assign(n+1, false);
    inorder('A');
    cout << endl;

    visited.assign(n+1, false);
    postorder('A');
}

int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

    input();
    solve();


    return (0);
}