#include <iostream>

using namespace std;

int main() {
    int number_of_case, N, M;

    while (cin >> number_of_case) {
        cin >> N >> M;
        for (int i = 0; i < number_of_case; i++) {
            int n, m;
            cin >> n >> m;
            if (n == N || m == M) {
                cout << "divisa" << endl;
            } else if (n > N && m > M) {
                cout << "NE" << endl;
            } else if (n > N && m < M) {
                cout << "SE" << endl;
            } else if (n < N && m > M) {
                cout << "NO" << endl;
            } else if (n < N && m < M) {
                cout << "SO" << endl;
            }
        }
    }

    return 0;
}
