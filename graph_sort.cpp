#include <iostream>
#include <algorithm>
#include <vector>

std::vector<std::vector<int>> edges[1000000];
std::vector<int> vertex;

template<typename T>
inline void remove(std::vector<T> & v, const T & item) {
    v.erase(std::remove(v.begin(), v.end(), item), v.end());
}

struct Way {

    std::string* visited;
    long long size;

    Way(int N) {
        visited = (std::string*)calloc(N + 1, sizeof(std::string));
        size = 0;
        for (int i = 0; i < N + 1; i++) {
            visited[i] = "white";
        }
    }

    int DFS(int sourse) {

        visited[sourse] = "grey";

        for (auto i : edges[sourse]) {
            if (visited[i[0]] == "white") {
                remove(edges[i[0]], {sourse, 1});
                DFS(i[0]);
            }
            if (visited[i[0]] == "grey") {
                answer(sourse);
                return 1;
            }
        }

        visited[sourse] = "black";
        return 0;
    }


    void answer(int sourse) {
        size++;

        vertex.push_back(sourse);
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

    int result = 0;

    for (int i = 1; i <= n; i++) {
        if (my_way.visited[i] == "white") {
            result = my_way.DFS(i);

            if (result == 1) {
                break;
            } else {
                my_way.size = 0;
                vertex.clear();
            }
        }
    }

    if (result == 1) {
        int a = vertex[0];
        vertex.clear();
        my_way.size = 0;
        for (int i = 0; i < n + 1; i++) {
            my_way.visited[i] = "white";
        }
        my_way.DFS(a);
        std::cout << "YES" << '\n';
        std::cout << my_way.size << '\n';
        std::cout << vertex[my_way.size - 1] << " ";
         for (int j = 0; j < my_way.size - 1; j++) {
             std::cout << vertex[j] << " ";
         }
         return 0;

    }

    std::cout << "NO";

    return 0;
}


