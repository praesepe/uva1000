#include <bits/stdc++.h>

using namespace std;

int main() {
    unordered_map<string, unordered_map<string, string>> state;
    state["+x"] = {
        {"+y", "+y"},
        {"-y", "-y"},
        {"+z", "+z"},
        {"-z", "-z"}
    };
    state["-x"] = {
        {"+y", "-y"},
        {"-y", "+y"},
        {"+z", "-z"},
        {"-z", "+z"}
    };
    state["+y"] = {
        {"+y", "-x"},
        {"-y", "+x"},
        {"+z", "+y"},
        {"-z", "+y"},
    };
    state["-y"] = {
        {"+y", "+x"},
        {"-y", "-x"},
        {"+z", "-y"},
        {"-z", "-y"},
    };
    state["+z"] = {
        {"+y", "+z"},
        {"-y", "+z"},
        {"+z", "-x"},
        {"-z", "+x"},
    };
    state["-z"] = {
        {"+y", "-z"},
        {"-y", "-z"},
        {"+z", "+x"},
        {"-z", "-x"}
    };

    int L;
    while (cin >> L) {
        if (L == 0) break;

        string direct = "+x";
        string step;
        for (int i = 0; i < L - 1; i++) {
            cin >> step;
            if (step == "No") continue;
            direct = state[direct][step];
        }
        cout << direct << endl;
    }

    return 0;
}
