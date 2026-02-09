#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

string str;
int n;
vector<string> words;
vector<vector<int>> chars;
vector<long> dp;
vector<int> sub_char(26+1, 0);


// func for debug 
void show_chars() {
   for (int i = 0; i < n; i++)
   {
      for (int c: chars[i]) {
         cout << c << " ";
      } cout << endl;
   }
}

template<typename T>
void show_vector(const T& t) {
   for (int i =0 ; i < t.size(); ++i) {
      cout << t[i] << " ";
   }cout << endl;
}

void input() noexcept {
   cin >> str;

   cin >> n;
   words.assign(n, "");
   chars.assign(n, vector<int>(26+1));
   
   for (int i = 0; i < n; i++) {
      cin >> words[i];

      for (char c : words[i]) {
         chars[i][c -'a'] += 1;
      }
   }
   
   dp.assign(str.size()+1, LONG_MAX);
   dp[0] = 0;
}


void solve() {

   for (int i = 0; i < str.size(); ++i) {
      if (dp[i] == LONG_MAX) continue;
      
      for (int w = 0; w < words.size(); ++w) {
         int wLen = words[w].size();
         
         if (i + wLen -1 > str.size()) continue;
         // 같은 단어로 이루어져 있는가?

         // substring의 charset
         for (int z = i; z < i + wLen; ++z) {
            sub_char[str[z] -'a']++;
         }


         bool flag = true;
         for (int j = 0; j <= 26; ++j) {
            if (sub_char[j] != chars[w][j]) {
               flag = false;
               break;
            } 
         }
         fill(sub_char.begin(), sub_char.end(), 0);
         if (!flag) continue;
         
         // 몇개가 다른가? 
         int difCount = 0;
         for (int j = 0; j < wLen; ++j) 
            if (str[i+j] != words[w][j])
               ++difCount;
         
         
         dp[i+wLen] = min(dp[i+wLen], dp[i] + difCount);      
      }
   }
}


int main(void) {
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);

   input();
   // show_chars();
   solve();
   //show_vector(dp);
   dp[str.size()] == LONG_MAX ? cout << -1 : cout << dp[str.size()];

   return (0);
}