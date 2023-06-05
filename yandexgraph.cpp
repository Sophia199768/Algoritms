#include <iostream>
#include <vector>
#include <queue>
#include <limits>

std::vector<std::vector<int>> edges[1000000];
std::vector<int> ans;

struct Way {

    std::queue<std::vector<int>> Q;
    int* dist;
    int size;

    Way(int N) {
        dist = (int*)malloc(1000000 * sizeof(int));
        size = N;
    }

    int BFS(int sourse, int destination) {
        int ans;

        for (int i = 1; i <= size; i++) {
            dist[i] = std::numeric_limits<int>::max();
        }

        dist[sourse] = 0;
        Q.push({0, sourse});

        while(!Q.empty()) {
            int v = Q.front()[1];
            Q.pop();

            for(auto i : edges[v]) {
                int end = i[0];
                int start = i[1];
                if (dist[v] + start < dist[end]) {
                    dist[end] = dist[v] + start;
                    Q.push({-1, end});
                    std::cout << i[0] << " ";
                }

            }

        }
        std::cout << '\n';
        dist[destination] == std::numeric_limits<int>::max() ? ans = -1 : ans = dist[destination];
        return ans;
    }

    void answers(int N, int y, int to) {
        while (y != 1) {
             if (dist[N - 1] == y - 1) {
                N--;
                ans.push_back(N);
                y--;
            } else {
                N--;
            }
        }

        ans.push_back(to);
        std::reverse(ans.begin(), ans.end());
        for (int i = 0; i < ans.size(); i++) {
            std::cout << ans[i] << " ";
        }
    }

};



int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    int n;
    std::cin >> n;
    int f;

    int** graph;


    Way my_way(n);
    graph = (int**)malloc(10000 * sizeof(int*));


    for (int i = 0; i < 10000; i++) {
        graph[i] = (int*)malloc(10000 * sizeof(int));
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> f;
            if (f == 1) {
                graph[i + 1][j + 1] = 1;
            } else {
                graph[i + 1][j + 1] = 0;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (graph[i][j] != 0) {
                edges[i].push_back({j, 1});
            }
        }
    }

    int from, to;
    int answer;
    std::cin >> from;
    std::cin >> to;

    ans.push_back(to);
    if (from == to) {
        std::cout << 0;
        return 0;
    }

    answer = my_way.BFS(from, to);

    std::cout << answer << '\n';
    my_way.answers(n, answer, from);
    return 0;
}

