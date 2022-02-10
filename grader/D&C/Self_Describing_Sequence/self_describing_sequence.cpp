#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, i, k = 2;
    cin >> N;
    vector<int> G(1000000);
    G[1] = 1;
    G[2] = 3;
    while (N--) {
        cin >> i;
        while (G[k] < i) {
            int num = lower_bound(G.begin(), G.begin() + k, k + 1) - G.begin();
            G[k + 1] = G[k] + num, ++k;
        }
        cout << lower_bound(G.begin(), G.begin() + k, i) - G.begin() << "\n";
    }
}