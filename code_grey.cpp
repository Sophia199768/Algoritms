#include <iostream>
#include <vector>
#include <math.h>

struct my_code {
    std::string code_grey(int N, int size) {
        long long dv = 0;
        long long d = 1;
        long long y;
        std::string ans;

        y = N ^ (N >> 1);

        while (y > 0) {
            dv += (y % 2) * d;
            y = y / 2;
            d = d * 10;
        }

        ans = std::to_string(dv);

        while (ans.size() < size) {
            ans = "0" + ans;
        }
        return ans;
    }
};

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    int N;
    int k = 1;
    std::vector<std::string> answer;
    std::string ans;
    std::cin >> N;

    for (int i = 0; i < N; i++) {
        ans += "0";
    }

    answer.push_back(ans);

    for (int i = 0; i < pow(2, N) - 1; i++) {
        my_code code;
        ans = code.code_grey(k, N);
        answer.push_back(ans);
        k++;
    }

    for (int i = 0; i < answer.size(); i++) {
        std::cout << answer[i] << '\n';
    }
    return 0;
}