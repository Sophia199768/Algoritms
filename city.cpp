#include <iostream>
#include <vector>
#include <limits>
#include <queue>

std::vector<std::vector<int>> edges[1000000];

struct Way {

    std::queue<std::vector<int>> Q;
    int* dist;
    int size;


    Way(int N) {
        dist = (int*)malloc(1000000 * sizeof(int));
        size = N;
        visited = (bool**)malloc( 1000000 * sizeof(bool*));
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
                    Q.push({-dist[end], end});
                }

            }

        }
        dist[destination] == std::numeric_limits<int>::max() ? ans = -1 : ans = dist[destination];
        return ans;
    }


};


int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    int N;
    int M;
    int u, v;
    std::cin >> N;
    std::cin >> M;
    Way my_way(N);

    for (int i = 0; i < M; i++) {
        std::cin >> u >> v;
        edges[u].push_back({v, 1});
        edges[v].push_back({u, 1});
    }

    int from, to;
    int answer;
    std::cin >> from;
    std::cin >> to;

    if (from == to) {
        std::cout << 0;
        return 0;
    }
    
    answer = my_way.BFS(from, to);

    std::cout << answer;
    return 0;
}