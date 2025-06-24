#include <bits/stdc++.h>
#define YES "YES"
#define NO "NO"
using namespace std;
using ull = unsigned long long;

struct Rec {
    int x1, y1, x2, y2;

    friend ostream& operator <<(ostream& out, Rec& r) {
        out << r.x1 << " " << r.y1 << " " << r.x2 << " " << r.y2;
        return out;
    }
};

int Tcase;
Rec white{}, black1{}, black2{};

ull getArea(const Rec& r) {
    if (r.x1 >= r.x2 || r.y1 >= r.y2) return 0;
    return static_cast<ull>(r.x2 - r.x1) * (r.y2 - r.y1);
}

Rec getIntersection(const Rec& r1, const Rec& r2) {
    int x1 = max(r1.x1, r2.x1);
    int y1 = max(r1.y1, r2.y1);
    int x2 = min(r1.x2, r2.x2);
    int y2 = min(r1.y2, r2.y2);
    if (x1 >= x2 || y1 >= y2) return {0, 0, 0, 0};  
    return {x1, y1, x2, y2};
}

void input() {
    cin >> white.x1 >> white.y1 >> white.x2 >> white.y2;
    cin >> black1.x1 >> black1.y1 >> black1.x2 >> black1.y2;
    cin >> black2.x1 >> black2.y1 >> black2.x2 >> black2.y2;
}

void solve() {
    ull whiteArea = getArea(white);

    Rec intersection1 = getIntersection(white, black1);
    ull overlap1 = getArea(intersection1);

    Rec intersection2 = getIntersection(white, black2);
    ull overlap2 = getArea(intersection2);

    Rec intersectionBoth = getIntersection(intersection1, black2);
    ull overlapBoth = getArea(intersectionBoth);

    ull remainingWhite = whiteArea - overlap1 - overlap2 + overlapBoth;

    if (remainingWhite > 0) cout << YES << "\n";
    else cout << NO << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> Tcase;
    while (Tcase--) {
        input();
        solve();
    }
    
    return 0;
}
