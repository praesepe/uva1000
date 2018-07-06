#include <iostream>
#include <limits>
#include <stdint.h>


using namespace std;

int main() {
    uint32_t P, B, H, W;

    while (cin >> P >> B >> H >> W) {
        uint32_t result = numeric_limits<uint32_t>::max();
        for (uint32_t i = 0; i < H; i++) {
            uint32_t price_per_person;
            cin >> price_per_person;

            for (uint32_t j = 0; j < W; j++) {
                uint32_t free_bed;
                cin >> free_bed;
                if (price_per_person * P > B) continue;
                if (free_bed >= P) {
                    result = min(result, price_per_person * P);
                }
            }
        }

        if (result == numeric_limits<uint32_t>::max()) {
            cout << "stay home" << endl;
        } else {
            cout << result << endl;
        }
    }
}
