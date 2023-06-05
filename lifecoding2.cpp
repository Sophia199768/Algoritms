#include <iostream>
#include <vector>

std::vector<int> array;

struct My_str {

    int index = 0;
    int size;

    My_str(int N) {
        size = N;
    }

    std::string compare(int first, int second) {
        std::string world;

        for (int i = 0; i < size; i++) {
            array[first] > array[second] ?  world = "YES" : world = "";

            if (world != "") {
                return world;
            }

            array[first] < array[second] ?  world = "NO" : world = "";

            if (world != "") {
                return world;
            }

            first++;
            second++;
            if (first > size) {
                first = 0;
            }
            if (second > size) {
                second = 0;
            }
        }

        return "YES";
    }

};

int main() {

    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    int N;
    std::cin >> N;
    My_str my_str(N);

    int value;

   for (int i = 0; i < N; i++) {
       std::cin >> value;
       array.push_back(value);
   }

   for (int i = 0; i < N; i++) {
       my_str.compare(my_str.index, i) == "YES" ? my_str.index = i : 0;
   }

   for (int i = my_str.index; i < N; i++) {
       std::cout << array[i] << " ";
   }

   for (int i = 0; i < my_str.index; i++) {
       std::cout << array[i] << " ";
   }

    return 0;
}