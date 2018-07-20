#include <bits/stdc++.h>

using namespace std;

int main() {
    int cases;
    cin >> cases;

    for (int i = 0; i < cases; i++) {
        char c;
        int m, n;
        cin >> c >> m >> n;

        int result = 0;
        switch (c) {
        case 'Q':
        case 'r':
            result = min(m, n);
            break;
        case 'k':
            result = (((m + 1) / 2) * ((n + 1) / 2)) + ((m / 2) * (n / 2));
            break;
        case 'K':
            result = ((m + 1) / 2) * ((n + 1) / 2);
            break;
        }

        cout << result << endl;
    }

    return 0;
}
