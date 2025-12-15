/**
 * 4박자(한박에 1비트)를 사용한다
 * 0에서는 박자를 비우고, 1에서는 딸기를 외친다
 * 
 * 침묵 -> V
 * 딸기 -> 딸기
 * 
 * 1 <= x <= 16 까지 반복됨
 * 
 */
#include <iostream>
#include <vector>
#include <math.h>
#define endl '\n'
using namespace std;

int T, N;

void check(const int& n) {
    if (N >= n) {
        cout << "딸기";
        N -= n;
    } else {
        cout << "V";
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> T;
    
    for (int i = 0; i < T; i++)
    {
        cin >> N;
        N = (N - 1) % 28 + 1;
        
        if (N > 15) {
            N = 30 - N;
        }
        check(8);
        check(4);
        check(2);
        check(1);
        cout << endl;
    }
    
    
    return (0);

}