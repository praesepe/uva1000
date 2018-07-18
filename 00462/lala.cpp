#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
    string buffer;
    while (getline(cin, buffer, '\n')) {
        if (buffer.empty()) break;

        // parse
        unordered_map<char, unordered_set<char>> um = {
            { 'H', {} },
            { 'S', {} },
            { 'D', {} },
            { 'C', {} }
        };
        stringstream ss(buffer);
        for (size_t i = 0; i < 13; i++) {
            string card;
            ss >> card;

            char rank = card[0];
            char suit = card[1];
            um[suit].insert(rank);
        }

        // compute points
        int points = 0;
        int bonus_points = 0;
        bool all_stop = true;
        for (const auto itr : um) {
            const auto &ranks = itr.second;
            bool stop = false;

            bonus_points += ranks.size() == 2 ? 1 : 0;
            bonus_points += ranks.size() <= 1 ? 2 : 0;
            if (ranks.find('A') != ranks.end()) {
                points += 4;
                stop = true;
            }
            if (ranks.find('K') != ranks.end()) {
                points += 3;
                points += ranks.size() <= 1 ? -1 : 0;
                stop = stop || ranks.size() >= 2;
            }
            if (ranks.find('Q') != ranks.end()) {
                points += 2;
                points += ranks.size() <= 2 ? -1 : 0;
                stop = stop || ranks.size() >= 3;
            }
            if (ranks.find('J') != ranks.end()) {
                points += 1;
                points += ranks.size() <= 3 ? -1 : 0;
            }
            all_stop = all_stop && stop;
        }

        if (all_stop && points >= 16) {
            cout << "BID NO-TRUMP" << endl;
        } else if (points + bonus_points < 14) {
            cout << "PASS" << endl;
        } else {
            vector<pair<char, int>> scores = {
                { 'S', um['S'].size() },
                { 'H', um['H'].size() },
                { 'D', um['D'].size() },
                { 'C', um['C'].size() }
            };

            auto result = *max_element(
                scores.begin(),
                scores.end(),
                [](const pair<char, int>& a, const pair<char, int>& b) -> bool {
                    return a.second < b.second;
                }
            );

            cout << "BID " << result.first << endl;
        }
    }
    return 0;
}
