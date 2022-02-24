#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    pair<int, int> C[N]; // first = finish time, second = start time
    for (int i = 0; i < N; ++i)
        cin >> C[i].second;
    for (int i = 0; i < N; ++i)
        cin >> C[i].first;
    sort(C, C + N);
    int endTime = C[0].first, count = 1;
    for (int i = 1; i < N; ++i) {
        if (endTime <= C[i].second) {
            endTime = C[i].first;
            ++count;
        }
    }
    cout << count;
}