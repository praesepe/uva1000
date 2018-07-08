#include <bits/stdc++.h>

using namespace std;

struct Proposal {
    string name;
    double price;
    int count;
};

int main() {
    int n, p;
    int case_index = 1;
    while (cin >> n >> p) {
        if (n == 0 && p == 0) break;

        // ignore proposals
        for (int i = 0; i < n + 1; i++) cin.ignore(80, '\n');

        string tmp;
        Proposal result = { "", numeric_limits<double>::max(), -1 };
        for (int i = 0; i < p; i++) {
            Proposal current;
            getline(cin, current.name, '\n');
            cin >> current.price >> current.count;

            result = max(result, current, [n](const Proposal& a, const Proposal& b) -> bool {
                int a_count = min(a.count, n);
                int b_count = min(b.count, n);
                if (a_count < b_count) return true;
                if (a_count == b_count) return a.price > b.price;

                return false;
            });

            // ignore proposals
            for (int i = 0; i < current.count + 1; i++) cin.ignore(80, '\n');
        }

        // result
        if (case_index != 1) cout << endl;
        cout << "RFP #" << case_index++ << endl;
        cout << result.name << endl;
    }
    return 0;
}
