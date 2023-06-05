#include <iostream>
#include <vector>

std::string** graph;

struct Matrix {
    int** matrix;
    int** ways;
    int n;
    int m;

   Matrix(int n_, int m_) {
       n = n_;
       m = m_;

       graph = (std::string**) malloc(1001 * sizeof(std::string*));
       matrix = (int**)malloc(1001 * sizeof(int*));
       ways = (int**)malloc(1001 * sizeof(int*));

       for (int i = 0; i < 1001; i++) {
           matrix[i] = (int*)malloc(1001 * sizeof(int));
           ways[i] = (int*)calloc(1001, sizeof(int));
           graph[i] = (std::string*)malloc(1001 * sizeof(std::string));

           for (int j = 0; j < 1001; j++) {
               graph[i][j] = "white";
           }
       }
   }

    void DFS(int i, int j) {
       int ma = 0;

        if (graph[i][j] != "white") {
            return;
        }
            if (i >= 1) {
                if (matrix[i][j] > matrix[i - 1][j]) {
                    DFS(i - 1, j);
                    ma = std::max(ma, ways[i - 1][j] + 1);
                }
            }

            if (j >= 1) {
                if (matrix[i][j] > matrix[i][j - 1]) {
                    DFS(i, j - 1);
                    ma = std::max(ma, ways[i][j - 1] + 1);;
                }
            }

            if (i < n - 1) {
                if (matrix[i][j] > matrix[i + 1][j]) {
                    DFS(i + 1, j);
                    ma = std::max(ma, ways[i + 1][j] + 1);
                }
            }

            if (j < m - 1)
                if (matrix[i][j] > matrix[i][j + 1]) {
                    DFS(i, j + 1);
                    ma = std::max(ma, ways[i][j + 1] + 1);
                }

       ways[i][j] = ma;
       graph[i][j] = "grey";
    }

    int find_answer(int N, int M) {
       int max = 0;
       for (int i = 0; i < N; i++) {
           for (int j = 0; j < M; j++) {
               if (ways[i][j] > max) {
                   max = ways[i][j];
               }
           }
       }
       return max + 1;
   }

};

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    int n;
    int m;
    int k;
    std::cin >> n;
    std::cin >> m;

    Matrix my_matrix(n, m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> k;
            my_matrix.matrix[i][j] = k;
        }
    }

    int answer;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
                my_matrix.DFS(i, j);
        }
    }

    answer = my_matrix.find_answer(n, m);
    std::cout << answer;
    return 0;
}