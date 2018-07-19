#include <bits/stdc++.h>

using namespace std;

int main() {
    int A, B, C, X, Y;

    while (cin >> A >> B >> C >> X >> Y) {
        if (A == 0) break;

        unordered_set<int> cards = { A, B, C, X, Y };
        vector<int> princess = { A, B, C }, prince = { X, Y };
        sort(princess.begin(), princess.end());
        sort(prince.begin(), prince.end());

        auto find_smallest = [&cards](int start) -> int {
            for (int i = start; i <= 52; i++) {
                if (cards.find(i) == cards.end()) return i;
            }
            return -1;
        };

        int result = -1;
        if (prince[1] > princess[2]) {
            if (prince[0] > princess[2]) {
                result = find_smallest(1);
            } else if (prince[0] > princess[1]) {
                result = find_smallest(princess[1] + 1);
            } else if (prince[0] > princess[0]) {
                result = find_smallest(princess[2] + 1);
            } else {
                result = find_smallest(princess[2] + 1);
            }
        } else if (prince[1] > princess[1]) {
            if (prince[0] > princess[1]) {
                result = find_smallest(princess[1] + 1);
            }
        }
        cout << result << endl;
    }
    return 0;
}
