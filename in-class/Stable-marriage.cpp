#include <bits/stdc++.h>

using namespace std;

set<pair<int, int>> gale_shapley(int &n, int &c, vector<vector<int>> &pm, vector<vector<int>> &pw) {
    set<pair<int, int>> ans;
    vector<bool> mFree(n, true), wFree(c, true);
    map<int, int> pairM, pairW;
    int i = 0, cnt = 0;
    while (true) {
        if (mFree[i % n]) {
            int idx = pairM[i % n]++;
            if (idx < c) {
                int w = pm[i % n][idx];
                if (wFree[w]) {
                    ans.emplace(i % n, w);
                    pairW[w] = i % n;
                    wFree[w] = false;
                    mFree[i % n] = false;
                } else {
                    int mPrime = pairW[w];
                    auto it = ans.find({mPrime, w});
                    auto itM1 = find(pw[w].begin(), pw[w].end(), i % n);
                    auto itMPrime = find(pw[w].begin(), pw[w].end(), mPrime);
                    if (itMPrime - itM1 < 0) {
                        pairW[w] = i % n;
                        mFree[mPrime] = true;
                        mFree[i % n] = false;
                        ans.emplace(i % n, w);
                        ans.erase(it);
                    }
                }
                cnt = 0;
            } else {
                cnt++;
                if (cnt == n)
                    break;
            }
        } else {
            cnt++;
            if (c == n)
                break;
        }
        i++;
    }
    return ans;
}

int main() {
    int n, c;                   // n = number of men, c= number of women
    vector<vector<int>> pm, pw; //  pm = preference of man to women, pw = preference of woman to men
    set<pair<int, int>> answer = gale_shapley(n, c, pm, pw);
}