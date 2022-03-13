#include <bits/stdc++.h>

using namespace std;

int paren(string T) {
    int n = T.length();
    int ans = 0, parenR = 0;
    for (int i = 0; i < n; ++i) {
        if (T[i] == '(') {
            if (parenR > 0)
                ans += parenR;
            parenR--;
        } else if (T[i] == ')') {
            parenR++;
        }
    }
    return ans;
}

int main() {
    string test1 = "())()(";   // 2
    string test2 = "))(()(";   // 4
    string test3 = "((()()))"; // 0
    string test4 = ")))(((";   // 6
    printf("test1 needs to swap %d times\n", paren(test1));
    printf("test2 needs to swap %d times\n", paren(test2));
    printf("test3 needs to swap %d times\n", paren(test3));
    printf("test4 needs to swap %d times\n", paren(test4));
}