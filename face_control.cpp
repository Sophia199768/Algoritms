#include <iostream>
#include <vector>

std::vector<std::vector<int>> eadges(1000000, std::vector<int>(3));

struct Ford {
    int* dist;
    int* predki;

    Ford() {
        dist = (int*)malloc(100009 * sizeof(int));
        predki = (int*)malloc(100009 * sizeof(int));
    }

    bool ford_bellman(int V, int E, int start, int len) {
        for (int i = 0; i < 100009; i++) {
            dist[i] = 2000000000;
            predki[i] = 0;
        }

        dist[start] = 0;

        for (int i = 0; i < V - 1; i++) {
            int relax = 0;
            for (int j = 0; j < E; j++) {
                if (dist[eadges[j][1]] > dist[eadges[j][0]] + eadges[j][2] and (dist[eadges[j][0]] != 2000000000 or eadges[j][2] != 2000000000)) {
                    dist[eadges[j][1]] = dist[eadges[j][0]] + eadges[j][2];
                    predki[eadges[j][1]] = eadges[j][0];
                    relax++;
                }
            }

            if (relax == 0) {
                break;
            }

        }

        int first_cycle_vertex = 0;

        for (int i = 0; i < E; i++) {
            if (dist[eadges[i][1]] > dist[eadges[i][0]] + eadges[i][2] and dist[eadges[i][1]] != 2000000000 and eadges[i][2] != 2000000000) {
                first_cycle_vertex = eadges[i][1];
            }
        }

        if (first_cycle_vertex == 0) {
            return true;
        }

        for (int i = 0; i < V - 1; i++) {
            first_cycle_vertex = predki[first_cycle_vertex];
        }

        int k = predki[first_cycle_vertex];
        int count = 1;

        while (k != first_cycle_vertex) {
            k = predki[k];
            count++;
        }

        if (count > len) {
            return false;
        } else {
            return true;
        }
    }

};

int main() {
    int N;
    int k;
    int st;
    int n;
    int m;
    Ford ford;

    std::vector<std::string> answer;

    std::cin >> N;
    std::cin >> k;

    for (int i = 0; i < N; i++) {
        std::cin >> n >> m;
        bool flag;

        for (int j = 0; j < m; j++) {
            int s;
            int e;
            int w;
            std::cin >> s >> e >> w;

            j == 0 ? st = s : 0;

            eadges[j][0] = s;
            eadges[j][1] = e;
            eadges[j][2] = w;
        }

        flag = ford.ford_bellman(n, m, st, k);

        flag ? answer.push_back("YES") : answer.push_back("NO");
    }

    for (int i = 0; i < answer.size(); i++) {
        std::cout << answer[i] << '\n';
    }

    return 0;
}