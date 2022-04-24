#include <bits/stdc++.h>

using namespace std;

int N, E, a, b, color[50], mnC = 51;
vector<int> AdjMat[50];

bool check(int idx) {
    for (int u : AdjMat[idx]) {
        if (color[idx] == color[u])
            return false;
    }
    return true;
}

void paint(int idx) {
    if (idx == N) {
        int tmp = 0;
        for (int i = 0; i < N; ++i)
            tmp = max(tmp, color[i]);
        if (tmp < mnC)
            mnC = tmp;
        return;
    }
    for (int i = 1; i <= N; ++i) {
        if (i > mnC)
            return;
        color[idx] = i;
        if (check(idx))
            paint(idx + 1);
    }
}

int main() {
    cin >> N >> E;
    for (int i = 0; i < E; ++i) {
        cin >> a >> b;
        AdjMat[a].push_back(b);
        AdjMat[b].push_back(a);
    }
    color[0] = 1;
    paint(1);
    cout << mnC;
}