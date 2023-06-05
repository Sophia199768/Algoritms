#include <iostream>
#include <vector>

std::vector<std::vector<int>> questions;
std::vector<std::string> answer;
std::vector<std::vector<int>> vertexes[100009];

template<typename T>
inline void remove(std::vector<T> & v, const T & item) {
    v.erase(std::remove(v.begin(), v.end(), item), v.end());
}

struct UnionFind {
    std::vector <int> array;
    int* rang;
    int n;

    UnionFind(int n_) {
        n = n_;
        rang = (int*)malloc(100009 * sizeof(int));

        for (int i = 0; i < n + 1; i++) {
            array.push_back(i);
        }
    }

    std::string find(int u, int v) {
        if (get(u) == get(v)) {
            return "YES";
        }
        return "NO";
    }

    int get(int x) {
        if (array[x] != x) {
            array[x] = get(array[x]);
        }
        return array[x];
    }

    void unite(int u, int v) {
        int x = get(u);
        int y = get(v);

        if (x == y) {
            return;
        }

        if (rang[x] == rang[y]) {
            rang[x]++;
        }
        rang[x] < rang[y] ? array[x] = y : array[y] = x;
    }

};

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    int n;
    int m;
    int q;
    int ai;
    int bi;
    char oper;
    std::string flag;

    std::cin >> n;
    std::cin >> m;
    std::cin >> q;

    UnionFind my_unoin_find(n);

    for (int i = 0; i < m; i++) {
        std::cin >> ai >> bi;
        vertexes[ai].push_back({bi, 1});
        vertexes[bi].push_back({ai, 1});
    }

    for (int i = 0; i < q; i++) {
        std::cin >> oper >> ai >> bi;

        if (oper == '?') {
            int elem = '?';
            questions.push_back({elem, ai, bi});

        } else if (oper == '-') {
            std::string str = '-' + std::to_string(ai) + " " + std::to_string(bi);
            int elem = '-';
            questions.push_back({elem, ai, bi});
            remove(vertexes[ai], {bi, 1});
            remove(vertexes[bi], {ai, 1});
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < vertexes[i].size(); j++) {
            my_unoin_find.unite(i, vertexes[i][j][0]);
        }
    }

    for (int i = q - 1; i >= 0; i--) {
        if (questions[i][0] == '?') {
            flag = my_unoin_find.find(questions[i][1], questions[i][2]);
            answer.push_back(flag);

        } else if (questions[i][0] == '-') {
            my_unoin_find.unite(questions[i][1], questions[i][2]);
        }
    }

    for (int i = answer.size() - 1; i >= 0; i--) {
        std::cout << answer[i] << '\n';
    }

    return 0;
}