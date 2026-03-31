/**
 * solve)
 * 1) dfs를 하면서 component를 구한다
 * 2) component끼리의 연결하는 edge를 구한다
 * 3) mst를 구한다
 * 
 */

#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;
using edge = pair<int,pair<int,int>>; // weight, p1, p2

int row, col, com_count;
const vector<int> x_move = {-1,1,0,0}, y_move = {0,0,-1,1};
vector<vector<int>> matrix;
vector<vector<bool>> visited;
vector<int> parents, weights;
vector<edge> edges;


// debug
template<typename T>
void show_matrix(const T& m) {
    for (int i = 1; i <= row; ++i) {
        for (int j =1; j <= col; ++j) {
            cout << m[i][j] << " ";
        }cout << endl;
    }
}
// debug
void show_edges() {
    for (edge e: edges) {
        cout << e.first << " " << e.second.first << " " << e.second.second << endl;
    }
}


void input() noexcept {
    cin >> row >> col;
    
    // init datastructures
    matrix.assign(row+1, vector<int>(col+1, 0));
    visited.assign(row+1, vector<bool>(col+1, false));
    
    for (int i = 1; i <= row; ++i) 
        for (int j = 1; j <= col; ++j) 
            cin >> matrix[i][j];
}

bool in_the_matrix(int xpos, int ypos) {
    return xpos >= 1 && xpos <= row && ypos >= 1 && ypos <= col;
}

void dfs(int xpos, int ypos) {

    visited[xpos][ypos] = true;
    matrix[xpos][ypos] = com_count;

    for (int i = 0; i < 4; ++i) {
        int x = xpos + x_move[i];
        int y = ypos + y_move[i];

        if (!in_the_matrix(x,y)) continue;
        if (visited[x][y]) continue;
        if (matrix[x][y] == 0) continue;

        dfs(x,y);
    }
}


void set_component() {
    for (int i = 1; i <= row; ++i) {
        for (int j = 1; j <= col; ++j) {
            if (matrix[i][j] == 1 && !visited[i][j]) {
                ++com_count;
                dfs(i,j);
            }
        }
    }
}

void set_edges() {
    vector<pair<int,int>> dummy;
    
    // horizontal
    for (int i = 1; i <= row; ++i) {
        dummy.clear();
        for (int j = 1; j <= col; ++j)
            if (matrix[i][j] != 0)
                dummy.push_back({j, matrix[i][j]});

        if (dummy.size() < 2) continue;

        pair<int,int> stand = dummy[0];
        for (int k = 1; k < (int)dummy.size(); ++k) {
            if (stand.second != dummy[k].second) {
                int len = dummy[k].first - stand.first - 1;
                if (len >= 2)
                    edges.push_back({len, {stand.second, dummy[k].second}});
            }
            stand = dummy[k];
        }
    }

    // vertical
    for (int i = 1; i <= col; ++i) {
        dummy.clear();
        for (int j = 1; j <= row; ++j)
            if (matrix[j][i] != 0)
                dummy.push_back({j, matrix[j][i]});

        if (dummy.size() < 2) continue;

        pair<int,int> stand = dummy[0];
        for (int k = 1; k < (int)dummy.size(); ++k) {
            if (stand.second != dummy[k].second) {
                int len = dummy[k].first - stand.first - 1;
                if (len >= 2)
                    edges.push_back({len, {stand.second, dummy[k].second}});
            }
            stand = dummy[k];
        }
    }
}


void set_parents_and_weights() {
    parents.assign(com_count+1, 0);
    weights.assign(com_count+1, 1);

    for (int i = 1; i <= com_count; ++i)
        parents[i] = i;
}

// function for mst && union-find
int Find(int node) {
    if (parents[node] == node) {
        return node;
    } else {
        return parents[node] = Find(parents[node]);
    }
}

void Union(int x, int y) {
    x = Find(x); y = Find(y);

    if (x == y) return;
    else if (weights[x] <= weights[y]) {
        parents[x] = y;
        weights[y] += weights[x];
    } else {
        parents[y] = x;
        weights[x] += weights[y];
    }
}

void mst() {
    
    sort(edges.begin(), edges.end());
    int res = 0;
    int mst_edge_count = 0;

    for (edge e: edges) {
        int w = e.first;
        int x = e.second.first;
        int y = e.second.second;

        if (Find(x) == Find(y)) continue;

        Union(x,y);
        res += w;
        mst_edge_count++;

        if (mst_edge_count == com_count-1) {
            cout << res;
            return;
        }

    }

    cout << -1;
}


int main(void) {
    input();
    set_component();
    set_parents_and_weights();
    //cout << endl;
    //show_matrix(matrix); // debug
    set_edges();
    mst();
    return (0);
}