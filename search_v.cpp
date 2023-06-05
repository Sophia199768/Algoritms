#include <iostream>
#include <vector>
#include <queue>

std::vector<std::vector<int>> eadges[1000000];
std::vector<int> answer;

template<typename T>
struct Sort {
    bool operator()(std::vector<int>& eadge1, std::vector<int>& eadge2) {
        if (eadge1[1] > eadge2[1]) {
            return true;
        }
        return false;
    }
};

struct Dijkstra {
    int* d;
    std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, Sort<std::vector<int>>> Q;

    Dijkstra() {
        d = (int *) malloc(100000 * sizeof(int));
    }

    void dekstra(int s) {

        for (int i = 0; i < 100000; i++) { //000
            d[i] = 2000000000;
        }

        Q.push({s, 0});
        d[s] = 0;

        while (!Q.empty()) {
            for (auto edge: eadges[Q.top()[0]]) {
                int u = edge[0];
                if (d[u] > d[Q.top()[0]] + edge[1] and d[Q.top()[0]] != 2000000000) {
                    d[u] = d[Q.top()[0]] + edge[1];
                    Q.push({u, d[u]});
                }
            }
            Q.pop();
        }
    }
};

int main() {
    int N;
    int M;
    int Q;
    int start;
    std::cin >> N;
    std::cin >> M;
    std::cin >> Q;
    std::cin >> start;
    Dijkstra my_dijkstra;

    int si;
    int ei;
    int wi;

    for (int i = 0; i < M; i++) {
        std::cin >> si >> ei >> wi;
        eadges[si].push_back({ei, wi});
        eadges[ei].push_back({si, wi});
    }

    my_dijkstra.dekstra(start);
    int q;

    for (int i = 0; i < Q; i++) {
        std::cin >> q;
        if (my_dijkstra.d[q] == 2000000000) {
            answer.push_back(-1);
        } else {
            answer.push_back(my_dijkstra.d[q]);
        }
    }

    for (int i = 0; i < answer.size(); i++) {
        std::cout << answer[i] << '\n';
    }

    return 0;
}