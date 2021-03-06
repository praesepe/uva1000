#include <bits/stdc++.h>

using namespace std;

int main() {
    size_t cases;
    cin >> cases;

    for (size_t i = 1; i <= cases; i++) {
        vector<string> piles(53, "");
        for (size_t j = 1; j <= 52; j++) {
            string card;
            cin >> card;
            piles[j] = card;
        }

        int Y = 0;
        int pos = 27;
        for (size_t j = 0; j < 3; j++) {
            char rank = piles[pos][0];
            if ('2' <= rank && rank <= '9') {
                int val = (rank - '0');
                pos -= (1 + 10 - val);
                Y += val;
            } else {
                pos -= 1;
                Y += 10;
            }
        }

        string result = Y <= pos ? piles[Y] : piles[27 + Y - pos];
        cout << "Case " << i << ": " << result << endl;
    }

    return 0;
}
