#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int number_of_case;
    cin >> number_of_case;

    for (int i = 0; i < number_of_case; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        vector<int> v = {a, b, c};
        sort(v.begin(), v.end());

        cout << "Case " << i + 1 << ": " << v[1] << endl;
    }

    return 0;
}
