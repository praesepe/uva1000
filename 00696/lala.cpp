#include <bits/stdc++.h>

using namespace std;

inline int compute(int m, int n) {
    int big_m = (m + 1) / 2;
    int big_n = (n + 1) / 2;
    int small_m = m - big_m;
    int small_n = n - big_n;

    return big_m * big_n + small_m * small_n;
}

int main() {
    int m, n;

    while (cin >> m >> n) {
        if (m == 0 && n == 0) break;

        int big, small;
        if (m > n) {
            big = m;
            small = n;
        } else {
            big = n;
            small = m;
        }

        int result = 0;
        switch (small) {
            case 1:
                result = big;
                break;
            case 2:
                result = max(big, (big / 4) * 4 + ((big % 4) >= 2 ? 2 : big % 4) * 2);
                break;
            default:
                result = compute(big, small);
        }
        cout << result << " knights may be placed on a ";
        cout << m << " row ";
        cout << n << " column board." << endl;
    }
    return 0;
}
