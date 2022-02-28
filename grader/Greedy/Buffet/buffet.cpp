#include <bits/stdc++.h>

using namespace std;

int main() {
    int F, W, N, x;
    cin >> F >> W >> N;
    int L[F];
    for (int i = 0; i < F; ++i)
        cin >> L[i];
    sort(L, L + F);
    int cnt = 0, i = 0, start;
    while (i < F) {
        ++cnt;
        start = L[i];
        while (i < F && L[i] <= start + 2 * W) {
            ++i;
        }
    }
    cout << cnt;
}
/*
10 5 10
1 10 9 2 3 4 8 7 5 6

1

12 5 100
1 10 9 4 8 7 6 11 12 20 25 29

3

*/