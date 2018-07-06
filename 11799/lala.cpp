#include <iostream>
#include <algorithm>
#include <limits>

using namespace std;

int main() {
    int number_of_cases;
    cin >> number_of_cases;

    for (int i = 1; i <= number_of_cases; i++) {
        int number_of_creatures;
        cin >> number_of_creatures;

        int result = numeric_limits<int>::min();
        for (int j = 1; j <= number_of_creatures; j++) {
            int speed;
            cin >> speed;

            result = max(result, speed);
        }

        cout << "Case " << i << ": " << result << endl;
    }
    return 0;
}
