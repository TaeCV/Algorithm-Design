#include <bits/stdc++.h>

using namespace std;

int N, ans = 0;

void cal(int sm, int last) {
    if (sm == N)
        ans++;
    else {
        for (int i = last; i <= N; ++i)
            if (sm + i <= N)
                cal(sm + i, i);
    }
}

int main() {
    cin >> N;
    cal(0, 1);
    cout << ans;
}