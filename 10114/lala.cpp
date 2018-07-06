#include <iostream>
#include <queue>

using namespace std;

int main() {
    int months, number_of_depreciated;
    double down, borrowing;

    while (true) {
        cin >> months >> down >> borrowing >> number_of_depreciated;
        if (months <= 0) break;

        // make queue
        queue<pair<int, double>> q;
        for (int i = 0; i < number_of_depreciated; i++) {
            int duration;
            double depreciated;
            cin >> duration >> depreciated;
            q.emplace(duration, depreciated);
        }

        // simulation
        int current_month = 0;
        double car_init_value = borrowing + down;
        double pay_per_month = borrowing / (double) months;
        double current_depreciated = 1.0, month_depreciated = 1.0; 
        while (current_month <= months) {
            if (!q.empty() && current_month >= q.front().first) {
                month_depreciated = 1.0 - q.front().second;
                q.pop();
            }

            current_depreciated *= month_depreciated;
            double car_current_value = car_init_value *  current_depreciated;

            if (borrowing < car_current_value) break;

            borrowing -= pay_per_month;
            current_month++;
        }

        cout << current_month;
        cout << (current_month != 1 ? " months" : " month") << endl;
    }

    return 0;
}
