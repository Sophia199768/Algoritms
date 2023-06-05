#include <iostream>

int first_points = 0;
int second_points = 0;
int third_points = 0;

struct Hash {

    Hash() {
        table = (std::pair<std::string, std::pair<int, int>>**)calloc( 1799999, sizeof(std::pair<std::string, std::pair<int, int>>*));
    }

    unsigned int hash1(std::string name) const {
        unsigned int x = 1;
        for (int i = 0; i < name.size(); i++) {
            x += ((2971 * x + name[i]) % 2971215073);
        }
        return x % 1000000;
    }


    unsigned int hash2(std::string key) const {
        unsigned int hash = 1;
        for (int i = 0; i < key.size(); i++) {
            hash += ((2971 * hash + key[i]) % 2971215073);
        }
        return (hash % 1799998) + 1;
    }

    void insert(std::string name, int x) {
        int key1 = hash1(name);

        if (table[key1] == nullptr) {

            std::pair<std::string, std::pair<int, int>>* cond = new std::pair<std::string, std::pair<int, int>>;
            cond->first = name;
            cond->second.first = x;
            cond->second.second = 3;
            table[key1] = cond;

        } else {

            int key2 = hash2(name);
            std::pair<std::string, std::pair<int, int>>* cond1;
            std::pair<std::string, std::pair<int, int>>* cond2;
            cond2 = table[key2];

            while (cond2 != nullptr) {
                cond1 = table[hash2(cond2->first)];
                table[hash2(cond2->first)] = cond2;
                std::swap(cond1, cond2);
            }

            table[hash2(name)] = new std::pair<std::string, std::pair<int, int>>;
            table[hash2(name)]->first = name;
            table[hash2(name)]->second.first = x;
            table[hash2(name)]->second.second = 3;
        }
    }

    void New_(std::string key, int x) {
        int index = hash1(key);
        if (table[index] != nullptr and table[index]->first == key) {
            table[index]->second.first = (table[index]->second.first * 10) + x;
            table[index]->second.second -= 2;
            return;
        }
        if (table[index] != nullptr and table[index]->first == key) {
            index = hash2(key);
            table[index]->second.first = (table[index]->second.first * 10) + x;
            table[index]->second.second -= 2;
            return;
        }
    }

    void minus_one(std::string key) {
        int index = hash1(key);
        if (table[index] != nullptr and table[index]->first == key) {
            table[index]->second.second -= 1;
            return;
        }
        if (table[index] != nullptr and table[index]->first == key) {
            index = hash2(key);
            table[index]->second.second -= 1;
            return;
        }
    }

    int points(std::string key) {
        int x = hash1(key);
        if (table[x] != nullptr and table[x]->first == key) {
            return table[x]->second.second;
        }
        x = hash2(key);
        if (table[x] != nullptr and table[x]->first == key) {
            return table[x]->second.second;
        }
    }

    bool search(std::string key) {
        int x = hash1(key);

        if (table[x] != nullptr and table[x]->first == key) {
            return true;
        }

        x = hash2(key);
        if (table[x] != nullptr and table[x]->first == key) {
            return true;
        }

        return false;
    }

    void points() {
        for (int i = 0; i < 1799999; i++) {
            if (table[i] == nullptr) {
                continue;
            }
            if (table[i]->second.first <= 3) {
                if (table[i]->second.first == 1) {
                    first_points += table[i]->second.second;
                } else if (table[i]->second.first == 2) {
                    second_points += table[i]->second.second;
                }
            } else if (table[i]->second.first <= 100) {
                if (table[i]->second.first % 10 == 1) {
                    first_points += table[i]->second.second;
                } else if (table[i]->second.first % 10 == 2) {
                    second_points += table[i]->second.second;
                } else if (table[i]->second.first % 10 == 3) {
                    third_points += table[i]->second.second;
                }

                if (table[i]->second.first / 10 == 1) {
                    first_points += table[i]->second.second;
                } else if (table[i]->second.first / 10 == 2) {
                    second_points += table[i]->second.second;
                }
            }
        }
    }

    std::pair<std::string, std::pair<int, int>> **table;
};

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    int N;
    std::cin >> N;

    std::string task_name;
    Hash my_hash;

    for (int i = 0; i < N; i++) {
        std::cin >> task_name;
        if (!my_hash.search(task_name)) {
            my_hash.insert(task_name, 1);
        }
    }

    for (int i = 0; i < N; i++) {
        std::cin >> task_name;
        if (my_hash.search(task_name)) {
            my_hash.New_(task_name, 2);
        } else {
            my_hash.insert(task_name, 2);
        }
    }

    for (int i = 0; i < N; i++) {
        std::cin >> task_name;
        if (my_hash.search(task_name)) {
            if (my_hash.points(task_name) == 3) {
                my_hash.New_(task_name, 3);
            } else if (my_hash.points(task_name) == 1) {
                my_hash.minus_one(task_name);
            }
        } else {
            third_points += 3;
        }
    }
    my_hash.points();

    std::cout << first_points << " ";
    std::cout << second_points << " ";
    std::cout << third_points;
    return 0;
}