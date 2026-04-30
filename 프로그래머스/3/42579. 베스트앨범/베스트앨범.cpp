#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;

    unordered_map<string, int> total;
    unordered_map<string, vector<pair<int, int>>> songs;
    // songs[genre] = {play, id}

    for (int i = 0; i < genres.size(); i++) {
        total[genres[i]] += plays[i];
        songs[genres[i]].push_back({plays[i], i});
    }

    vector<pair<int, string>> genreRank;

    for (auto [genre, sum] : total) {
        genreRank.push_back({sum, genre});
    }

    sort(genreRank.begin(), genreRank.end(), greater<pair<int, string>>());

    for (auto [sum, genre] : genreRank) {
        auto& v = songs[genre];

        sort(v.begin(), v.end(), [](auto a, auto b) {
            if (a.first != b.first) return a.first > b.first;
            return a.second < b.second;
        });

        for (int i = 0; i < v.size() && i < 2; i++) {
            answer.push_back(v[i].second);
        }
    }

    return answer;
}