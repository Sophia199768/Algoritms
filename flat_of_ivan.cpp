#include <iostream>
#include <vector>
#include <queue>

std::string** graph;

template<typename T>
struct Way {
    int n;
    int m;

    Way(int width, int length) {
        n = width + 1;
        m = length + 1;


    }

    void DFS(int i, int j) {
        if (graph[i][j] == "white") {
            graph[i][j] = "grey";
        } else {
            graph[i][j] = "black";
        }

        if (graph[i][j] == "grey") {
            if (i >= 1 or j >= 1) {
                if (i >= 1) {
                    DFS(i - 1, j);
                }
                if (j >= 1) {
                    DFS(i, j - 1);
                }
            }
            if (i < n or j < m) {
                if (i < n) {
                    DFS(i + 1, j);
                }
                if (j < m) {
                    DFS(i, j + 1);
                }
            }
        }

    }


};


int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    int n;
    int m;

    std::cin >> n;
    std::cin >> m;
    char f;
    int y = 1;
    graph = (std::string**)malloc(10000 * sizeof(std::string*));


    for (int i = 0; i < 10000; i++) {
        graph[i] = (std::string*)malloc(10000 * sizeof(std::string));
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> f;
            if (f == '.') {
                graph[i][j] = "white";
                y++;
            } else {
                graph[i][j] = "black";
            }
        }
    }


    int flats = 0;
    Way<int> count_of_flats(n, m);
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (graph[i][j] == "white") {
                flats += 1;
                count_of_flats.DFS(i, j);
            }
        }
    }

    std::cout << flats;
    return 0;
}