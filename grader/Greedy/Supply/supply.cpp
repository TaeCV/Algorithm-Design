#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N, M, K;
    cin >> N >> M >> K;
    int D, action, label;
    pair<int, int> DAY[K];
    for (int i = 0; i < K; ++i) {
        cin >> D >> action >> label;
        DAY[D - 1] = {action, label};
    }
    queue<int> plant, store;
    for (int i = 0; i < K; ++i) {
        if (DAY[i].first) {
            // store request
            if (!plant.empty()) {
                cout << plant.front() << "\n";
                plant.pop();
            } else {
                cout << "0\n";
                store.push(DAY[i].second);
            }
        } else {
            // plant produce
            if (!store.empty()) {
                cout << store.front() << "\n";
                store.pop();
            } else {
                cout << "0\n";
                plant.push(DAY[i].second);
            }
        }
    }
}