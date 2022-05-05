#include <bits/stdc++.h>

using namespace std;

int N, M, K[8], a, b, w;
vector<pair<int, int>> AdjMtx[20];

int sumLeft(vector<bool> used) {
    int sm = 0;
    for (int i = 0; i < N; ++i)
        if (!used[i])
            for (auto each : AdjMtx[i])
                if (!used[each.first]) {
                    sm += each.second;
                }
    return sm / 2;
}

bool check(int now, int preSum, int target, vector<bool> used, int u) {
    used[u] = true;
    if (now + preSum < target)
        return false;
    if (now == target) {
        return true;
    } else {
        for (auto each : AdjMtx[u]) {
            int v = each.first, weight = each.second;
            if (!used[v] && now + weight <= target) {
                int pre = sumLeft(used);
                used[v] = true;
                if (check(now + weight, pre, target, used, v))
                    return true;
                used[v] = false;
            }
        }
        used[u] = false;
    }
    return false;
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < 8; ++i)
        cin >> K[i];
    for (int i = 0; i < M; ++i) {
        cin >> a >> b >> w;
        AdjMtx[a].push_back({b, w});
        AdjMtx[b].push_back({a, w});
    }
    for (int i = 0; i < 8; ++i) {
        bool isTrue = false;
        for (int j = 0; j < 8; ++j) {
            vector<bool> used(N, false);
            if (check(0, INT_MAX, K[i], used, j)) {
                isTrue = true;
                break;
            }
        }
        cout << (isTrue ? "YES\n" : "NO\n");
    }
}

/*
4 4
10 20 30 40 50 60 70 80
0 1 10
0 2 15
1 2 5
0 3 35

20 150
2508 1081 1669 1090 328 2927 3139 2587
15 17 101
14 16 189
4 15 168
3 4 123
7 14 103
0 17 17
1 13 4
1 4 9
1 12 91
0 10 23
6 16 58
15 16 159
10 15 70
0 11 191
0 9 154
11 18 43
6 11 21
4 8 127
4 5 21
10 18 96
5 7 152
2 3 197
8 11 126
2 16 194
7 11 113
6 18 186
9 15 126
16 17 132
8 18 69
12 15 194
9 10 53
8 19 113
13 16 40
6 10 57
2 14 91
3 19 162
9 16 63
12 17 117
2 4 58
4 7 18
10 14 26
4 10 67
10 11 16
0 4 22
6 7 188
13 17 53
2 19 95
10 17 188
5 17 125
5 16 5
1 8 156
7 19 70
9 19 64
8 17 170
1 17 83
16 19 130
18 19 107
8 10 75
7 18 136
1 5 124
11 19 57
5 18 68
3 9 45
3 10 39
1 18 190
0 2 117
1 16 172
13 15 139
4 13 55
5 8 113
4 18 105
3 18 89
7 9 13
0 8 108
6 12 57
12 19 79
3 17 178
2 9 114
2 18 174
10 16 101
5 15 170
3 15 183
11 12 147
5 19 92
2 11 5
1 9 180
3 16 105
3 7 3
5 10 100
6 19 70
15 18 80
5 9 27
1 7 37
0 3 138
14 19 98
8 12 18
8 13 37
8 15 180
2 12 149
0 1 126
7 10 73
6 13 99
0 13 139
7 16 124
11 17 138
0 16 133
0 5 100
4 17 138
17 18 21
14 18 117
12 18 60
7 15 127
8 9 168
8 14 11
1 2 54
1 11 186
1 6 191
2 5 49
7 8 196
12 13 24
2 7 182
3 12 4
2 17 4
5 14 50
7 12 150
6 17 16
5 6 80
3 11 44
16 18 189
0 18 85
3 14 178
9 14 198
11 14 114
4 14 34
9 18 66
6 8 117
1 14 36
14 17 86
9 11 132
13 18 68
2 8 52
7 13 41
3 5 92
1 10 106
4 11 47
2 15 193
2 6 67
5 12 197
1 19 57
10 19 150
*/