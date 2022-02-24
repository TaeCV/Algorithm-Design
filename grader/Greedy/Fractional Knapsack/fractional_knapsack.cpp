#include <bits/stdc++.h>

using namespace std;

double W, ans, Vi[100000], Wi[100000];
pair<double, int> F[100000];

int main() {
    int N;
    cin >> W >> N;
    for (int i = 0; i < N; ++i)
        cin >> Vi[i];
    for (int i = 0; i < N; ++i)
        cin >> Wi[i];
    for (int i = 0; i < N; ++i) {
        F[i] = {Vi[i] / Wi[i], i};
    }
    sort(F, F + N, greater<pair<double, int>>());
    int i = 0;
    while (W > 0 && i < N) {
        int idx = F[i].second;
        if (W >= Wi[idx]) {
            ans += Vi[idx];
            W -= Wi[idx];
        } else {
            ans += W * F[i].first;
            W = 0;
        }
        ++i;
    }
    printf("%.4lf", ans);
}