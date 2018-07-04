#include <cstdint>
#include <iostream>

using namespace std;

int main() {
    size_t number_of_case = 0;
    cin >> number_of_case;

    for (size_t i = 0; i < number_of_case; i++) {
        int32_t a, b;
        cin >> a >> b;
        if (a > b) {
            cout << ">" << endl;
        } else if (a < b) {
            cout << "<" << endl;
        } else {
            cout << "=" << endl;
        }
    }

    return 0;
}
