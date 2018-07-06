#include <iostream>
#include <cstdint>

using namespace std;

int main() {
    int64_t H, U, D, F;
    while (cin >> H >> U >> D >> F) {
        if (H == 0) break;

        H *= 100;
        U *= 100;
        D *= 100;

        int64_t down_speed = U * F / 100;
        int64_t current_height = 0;
        int64_t current_speed = U;
        int64_t day = 1;
        while (true) {
            current_height += current_speed;
            if (current_height > H) {
                cout << "success on day " << day << endl;
                break;
            }

            current_speed = current_speed - down_speed > 0 ?
                current_speed - down_speed : 0;
            current_height -= D;
            if (0 > current_height) {
                cout << "failure on day " << day << endl;
                break;
            }

            day++;
        }
    }

    return 0;
}
