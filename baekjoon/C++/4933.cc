#include <iostream>
#include <vector>
#include <map>
#define endl '\n'
using namespace std;

struct Node {
    char val;
    int left, right;
};

int tcase;
vector<Node> tree1, tree2;
vector<string> strings;

void input() {
    string str;
    while (cin >> str) {
        if (str == "end") break;
        strings.push_back(str);
    }
}

int build_tree(vector<Node>& tree) {
    vector<int> st;

    for (auto& token : strings) {
        if (token == "nil") {
            st.push_back(-1);
        } else {
            int right = st.back(); st.pop_back();
            int left  = st.back(); st.pop_back();
            tree.push_back({token[0], left, right});
            st.push_back((int)tree.size() - 1);
        }
    }
    return st.back();
}

bool same_tree(int u, int v,
               const vector<Node>& A,
               const vector<Node>& B,
               map<pair<int,int>, bool>& memo) {

    auto key = make_pair(u, v);
    if (memo.count(key)) return memo[key];

    if (u == -1 && v == -1)
        return memo[key] = true;

    if (u == -1 || v == -1)
        return memo[key] = false;

    if (A[u].val != B[v].val)
        return memo[key] = false;

    bool ok =
        (same_tree(A[u].left,  B[v].left,  A, B, memo) &&
         same_tree(A[u].right, B[v].right, A, B, memo))
     || (same_tree(A[u].left,  B[v].right, A, B, memo) &&
         same_tree(A[u].right, B[v].left,  A, B, memo));

    return memo[key] = ok;
}

void solve() {
    cin >> tcase;
    while (tcase--) {

        tree1.clear();
        tree2.clear();

        // Tree 1
        strings.clear();
        input();
        int root1 = build_tree(tree1);

        // Tree 2
        strings.clear();
        input();
        int root2 = build_tree(tree2);

        map<pair<int,int>, bool> memo;
        cout << (same_tree(root1, root2, tree1, tree2, memo)
                 ? "true" : "false") << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}
