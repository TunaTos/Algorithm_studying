#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

class AlpaNum {
private:
    int a_num, c_num, g_num, t_num;

public:
    // 생성자
    AlpaNum(int a = 0, int c = 0, int g = 0, int t = 0)
        : a_num(a), c_num(c), g_num(g), t_num(t) {}

    // 빌더 패턴: 입력을 통해 객체 생성
    static AlpaNum fromInput(istream& in) {
        int a, c, g, t;
        in >> a >> c >> g >> t;
        return AlpaNum(a, c, g, t);
    }

    // 연산자 오버로딩
    AlpaNum& operator+=(const AlpaNum& other) noexcept {
        a_num += other.a_num;
        c_num += other.c_num;
        g_num += other.g_num;
        t_num += other.t_num;
        return *this;
    }

    AlpaNum& operator-=(const AlpaNum& other) noexcept {
        a_num -= other.a_num;
        c_num -= other.c_num;
        g_num -= other.g_num;
        t_num -= other.t_num;
        return *this;
    }

    bool meetsRequirement(const AlpaNum& requirement) const noexcept {
        return a_num >= requirement.a_num &&
               c_num >= requirement.c_num &&
               g_num >= requirement.g_num &&
               t_num >= requirement.t_num;
    }
};

class DNAAnalyzer {
private:
    int Len, subLen;
    string str;
    AlpaNum stand;
    vector<AlpaNum> dp;

public:
    DNAAnalyzer(istream& in) 
	{
        in >> Len >> subLen >> str;
        stand = AlpaNum::fromInput(in);
        dp.resize(Len + 1);
    }

    void calculatePrefixSum() noexcept 
	{
        for (int i = 0; i < Len; i++) 
		{
            if (str[i] == 'A') dp[i + 1] = dp[i + 1] + AlpaNum(1, 0, 0, 0);
            if (str[i] == 'C') dp[i + 1] = dp[i + 1] + AlpaNum(0, 1, 0, 0);
            if (str[i] == 'G') dp[i + 1] = dp[i + 1] + AlpaNum(0, 0, 1, 0);
            if (str[i] == 'T') dp[i + 1] = dp[i + 1] + AlpaNum(0, 0, 0, 1);
            dp[i + 1] += dp[i];
        }
    }

    int countValidSubstrings() noexcept 
	{
        int result = 0;
        for (int i = subLen; i <= Len; i++) {
            int rear = i - subLen;
            AlpaNum current = dp[i];
            current -= dp[rear];
            if (current.meetsRequirement(stand)) {
                result++;
            }
        }
        return result;
    }

    void analyzeAndPrint() noexcept {
        calculatePrefixSum();
        cout << countValidSubstrings() << endl;
    }
};

int main() noexcept {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    DNAAnalyzer analyzer(cin);
    analyzer.analyzeAndPrint();

    return 0;
}
