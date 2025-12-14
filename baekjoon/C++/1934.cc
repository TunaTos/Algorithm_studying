#include <iostream>
#include <cmath>
#define endl '\n'
using namespace std;

int Tcase, num1, num2;

int getGcd(int num1, int num2) noexcept
{
    while (num2 != 0)
    {
        int r = num1 % num2;
        num1 = num2;
        num2 = r;
    }
    return num1;
}


void runTcase() noexcept
{
    cin >> num1 >> num2;
    if (num2 > num1)
        swap(num1, num2);
    cout << num1 * num2 / getGcd(num1, num2) << endl;

}

void solve() noexcept
{
    cin >> Tcase;
    for (size_t i = 0; i < Tcase; i++)
        runTcase();
}
int main(void) noexcept
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;
}