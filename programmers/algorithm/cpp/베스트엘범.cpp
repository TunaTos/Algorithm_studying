#include <bits/stdc++.h>
using namespace std;

struct Song {
    int plays;
    int id;
};

vector<int> solution(vector<string> genres, vector<int> plays) {
    unordered_map<string, int> sum;                  // 장르 총합
    unordered_map<string, vector<Song>> songs;       // 장르별 곡들

    int n = (int)genres.size();
    for (int i = 0; i < n; ++i) {
        sum[genres[i]] += plays[i];
        songs[genres[i]].push_back({plays[i], i});
    }

    // 장르를 총합 기준으로 정렬하기 위한 배열
    vector<pair<string,int>> g;
    g.reserve(sum.size());
    for (auto &kv : sum) g.push_back({kv.first, kv.second});

    sort(g.begin(), g.end(), [](auto &a, auto &b){
        return a.second > b.second; // 총합 내림차순 (문제에서 "모든 장르 총합이 다름" 보장)
    });

    vector<int> answer;

    for (auto &genrePair : g) {
        const string &genre = genrePair.first;
        auto &v = songs[genre];

        // 장르 내 곡 정렬: 재생수 desc, id asc
        sort(v.begin(), v.end(), [](const Song &a, const Song &b){
            if (a.plays != b.plays) return a.plays > b.plays;
            return a.id < b.id;
        });

        // 최대 2개 뽑기
        answer.push_back(v[0].id);
        if (v.size() >= 2) answer.push_back(v[1].id);
    }

    return answer;
}
