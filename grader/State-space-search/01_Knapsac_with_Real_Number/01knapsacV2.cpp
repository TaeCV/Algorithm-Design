#include <bits/stdc++.h>

using namespace std;

struct item {
    float v, w;
    bool operator<(const item &other) const {
        return v * other.w > other.v * w;
    }
};
item items[100];
int N;
float W, ans = 0, s[100];

float cost(int idx, float weight) {
    float c = 0;
    for (int i = idx; i < N; ++i) {
        if (weight - items[i].w > 0) {
            c += items[i].v;
            weight -= items[i].w;
        } else {
            c += items[i].v * weight / items[i].w;
            break;
        }
    }
    return c;
}

void knapsack(int idx, float sumv, float sumw) {
    if (sumw > W)
        return;
    if (idx == N) {
        ans = max(ans, sumv);
        return;
    }
    if (sumv + s[idx] < ans)
        return;
    if (sumv + cost(idx, W - sumw) < ans)
        return;
    knapsack(idx + 1, sumv + items[idx].v, sumw + items[idx].w);
    knapsack(idx + 1, sumv, sumw);
}

int main() {
    cin >> W >> N;
    for (int i = 0; i < N; ++i)
        cin >> items[i].v;
    for (int i = 0; i < N; ++i)
        cin >> items[i].w;
    sort(items, items + N);
    s[N - 1] = items[N - 1].v;
    for (int i = N - 2; i >= 0; --i)
        s[i] = s[i + 1] + items[i].v;
    knapsack(0, 0.0, 0.0);
    printf("%f", ans);
}