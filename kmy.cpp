#include <iostream>
#include <vector>

int chet = 0;
int ans = 0;

template<typename T>
inline void remove(std::vector<T> & v, const T & item) {
    v.erase(std::remove(v.begin(), v.end(), item), v.end());
}

template<typename T>
struct Sort {
    bool operator()(std::vector<int>& eadge1, std::vector<int>& eadge2) {
        if (eadge1[2] < eadge2[2]) {
            return true;
        }
        return false;
    }
};

struct UnionFind {
    std::vector <int> array;
    int* rang;
    int n;

    UnionFind(int n_) {
        n = n_;
        rang = (int*)malloc(100009 * sizeof(int));

        for (int i = 0; i < n + 1; i++) {
            array.push_back(i);
            rang[i] = 0;
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

    void clear() {
        for (int i = 0; i < n + 1; i++) {
            rang[i] = 0;
            array[i] = i;
        }
    };

    void unite(int u, int v, int weight) {
        int x = get(u);
        int y = get(v);

        if (x == y) {
            return;
        }

        ans += weight;
        chet++;

        if (rang[x] == rang[y]) {
            rang[x]++;
        }

        rang[x] < rang[y] ? array[x] = y : array[y] = x;
    }

};

int main() {
    int N;
    int M;
    std::cin >> N;
    std::cin >> M;

    std::vector<std::vector<int>> eadges(M + 1, std::vector<int>(3));

    int Ai;
    int Bi;
    int Ci;

    UnionFind my_union_find(N);

    for (int i = 0; i < M; i++) {
        std::cin >> Ai >> Bi >> Ci;
        eadges[i][0] = Ai;
        eadges[i][1] = Bi;
        eadges[i][2] = Ci;
    }

    std::sort(eadges.begin(), eadges.begin() + M, Sort<int>());

    for (int i = 0; i < eadges.size(); i++) {
        my_union_find.unite(eadges[i][0], eadges[i][1], eadges[i][2]);
    }

    int ans1 = ans;
    int ans2 = 1000000000;
    ans = 0;

    int k = chet;

    for (int i = 0; i < k * 2; i++) {
        my_union_find.clear();

        int u = eadges[i][0];
        int v = eadges[i][1];
        int c = eadges[i][2];

        eadges.erase(eadges.begin() + i);

        for (int j = 0; j < M - 1; j++) {
            my_union_find.unite(eadges[j][0], eadges[j][1], eadges[j][2]);
        }
        if (ans != ans1) {
            ans2 = std::min(ans2, ans);
        }
        ans = 0;

        eadges.push_back({u, v, c});
        std::sort(eadges.begin(), eadges.end(), Sort<int>());
    }

    std::cout << ans1 << " " << ans2;

    return 0;
}