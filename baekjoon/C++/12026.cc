    /**
     * 12026
     * 
     * 집은 1번에 있고, 링크의 집은 N번에 있다.
     * 
     * 보도 블럭은 B, O, J중에 하나가 있음
     * 1은 무조건 B이다.
     * 
     * 점프 -> 오른쪽으로만
     * 
     * N은 1000
     * 
     * 
     * 가장 짧은 선택지를 가는 것이 최선인가?
     * 
     * b(1)   o(3) j(4) b(5) o(6)
     * 1 -> 6 = 25
     * 4 + 1 + 1 + 1 -> 7
     *  
     * NO input 6
     * greedy x -> 완전탐색
     * 
     * F(n) = F(n-k) + (n-k) * (n -k)
     * DP
     * 
     * This code is rubbish
     * 
     */

    #include <iostream>
    #include <vector>
    #include <algorithm>
    #define INF 987654321
    using namespace std;
    using ull = unsigned long long;
    
    vector<int> bNum, oNum, jNum;
    vector<ull> bDP, oDP, jDP;

    int N;
    string str;

    void input() {
        cin >> N;
        cin >> str;

        for (int i = 0; i < str.length(); ++i) {
            switch (str[i])
            {
            case 'B':
                bNum.push_back(i+1);
                break;
            case 'O':
                oNum.push_back(i+1);
                break;
            case 'J':
                jNum.push_back(i+1);
                break;
            default:
                break;
            }
        }

        bDP.assign(N+1, INF);
        oDP.assign(N+1, INF);
        jDP.assign(N+1, INF);
    }



    int main(void) {
        ios::sync_with_stdio(0);
        cin.tie(0); cout.tie(0);


        input();
        if (str[0] != 'B')
        {
            cout << -1;
            return 0;
        }

        bDP[1] = 0;
        
        for (int i = 1; i <= N; ++i) {
            if (str[i-1] == 'B') {
                for (int j = 0; j < jNum.size(); ++j) {
                    if (jNum[j] >= i)
                        break;
                    bDP[i] = min(bDP[i], jDP[jNum[j]] + (i - jNum[j]) * (i - jNum[j]));
                }
            }
            else if (str[i-1] == 'O') {
                for (int j = 0; j < bNum.size(); ++j) {
                    if (bNum[j] >= i) {
                        break;
                    }
                    oDP[i] = min(oDP[i], bDP[bNum[j]] + (i - bNum[j]) * (i - bNum[j]));
                }
            }

            else  if (str[i-1] == 'J') {
                for (int j = 0; j < oNum.size(); ++j) {
                    if (oNum[j] >= i) {
                        break;
                    }
                    jDP[i] = min(jDP[i], oDP[oNum[j]] + (i - oNum[j]) * (i - oNum[j]));
                }
            }
        }

        
        ull res = min(oDP[N], bDP[N]);
        res = min(res, jDP[N]);
        
        if (res == INF)
            cout << -1;
        else   
            cout << res;


        return (0);
    }