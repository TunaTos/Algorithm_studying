#include <iostream>
#include <algorithm>
#include <queue>
#define endl '\n'
using namespace std;

struct Node {
    int age, time;
    string name;
};

int n;
vector<Node> nodes;



int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; ++i) {
        auto node = Node{};
        cin >> node.age;
        cin >> node.name;
        node.time = i;

        nodes.push_back(node);
    }

    sort(nodes.begin(), nodes.end(), [](Node& n1, Node& n2) {
        if (n1.age == n2.age) {
            return n1.time < n2.time;
        } else {
            return n1.age < n2.age;
        }
    });

    for (Node node: nodes) {
        cout << node.age << " " << node.name << endl;
    }

    return (0);
}