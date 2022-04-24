#include <bits/stdc++.h>

using namespace std;

double W, v[100], w[100];
vector<pair<double, int>> f;
int N;

double maxV(int idx, double temp) {
    double V = 0;
    while (temp > 0 && idx < N) {
        if (temp > w[f[idx].second]) {
            V += v[f[idx].second];
            temp -= w[f[idx].second];
        } else {
            V += v[f[idx].second] * temp;
            temp -= temp;
        }
        idx++;
    }
    return V;
}

pair<double, double> sumInRange(vector<int> &x, int idx) {
    double tmpV = 0, tmpW = 0;
    for (int i = 0; i < idx; ++i) {
        tmpV += x[i] * v[f[i].second];
        tmpW += x[i] * w[f[i].second];
    }
    return {tmpV, tmpW};
}

double knapsack() {
    double mxV = 0;
    priority_queue<pair<double, vector<int>>> pq;
    vector<int> x(0);
    pq.push({maxV(0, W), x});
    while (!pq.empty()) {
        pair<double, vector<int>> temp = pq.top();
        pq.pop();
        int m = temp.second.size();
        if (mxV >= temp.first) {
            break;
        }
        if (m == N && temp.first > mxV) {
            mxV = temp.first;
            continue;
        }
        pair<double, double> tmp = sumInRange(temp.second, m);
        double sumV = tmp.first, sumW = tmp.second;
        vector<int> x1(temp.second);
        x1.push_back(0);
        pq.push({sumV + maxV(m + 1, W - sumW), x1});
        if (W - sumW - w[f[m].second] >= 0) {
            vector<int> x2(temp.second);
            x2.push_back(1);
            pq.push({sumV + v[f[m].second] + maxV(m + 1, W - sumW - w[f[m].second]), x2});
        }
    }
    return mxV;
}

int main() {
    cin >> W >> N;
    f = vector<pair<double, int>>(N);
    for (int i = 0; i < N; ++i)
        cin >> v[i];
    for (int i = 0; i < N; ++i)
        cin >> w[i];
    for (int i = 0; i < N; ++i)
        f[i] = {v[i] / w[i], i};
    sort(f.begin(), f.end(), greater<pair<double, int>>());
    cout << knapsack();
}