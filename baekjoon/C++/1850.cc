#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
using ull = unsigned long long;

class GCD
{
private:
    ull num1, num2;
public:
    GCD(const ull& input1, const ull& input2):
            num1(input1), num2(input2) { }
    void showNumbers()  {std::cout << num1 << " " << num2 << '\n';}
    void getGcd()
    {
        ull r{1};
        while (num2 != 0)
        {
            ull r = num1 % num2;
            num1 = num2;
            num2 = r;
        }
        for (size_t i = 0; i < num1; i++)
        {
            cout << '1';
        }cout << endl;
    }
};

void solve()
{
    ull num1, num2;
    cin >> num1 >> num2;

    auto G = GCD{num1, num2};
    G.showNumbers();
    G.getGcd();
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
    return (0);
}