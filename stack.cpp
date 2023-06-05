#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

struct Node {
    int element;
    Node* next;
    Node(int str) {
        element = str;
        next = nullptr;
    }
};

struct list {
    Node* first;
    Node* last;

    list() {
        first = nullptr;
        last = nullptr;
    }

    bool is_empty() const {
        return (first == nullptr);
    }

    void insert(int str) {
        Node* p = new Node(str);
        if (is_empty()) {
            first = p;
            last = p;
            return;
        }
        last->next = p;
        last = p;
    }

    int remove() {
        Node* p = first;
        int number = first->element;
        first = p->next;
        delete p;
        return number;
    }

    int first_element() {
        Node* p = first;
        return first->element;
    }


};

int main() {
    std::string str;
    int size = 0;
    std::vector<std::string> out;
    list mylist;


    while (std::getline(std::cin, str)) {
        if (str.empty()) {
            break;
        }
        std::stringstream s(str);
        std::string p;
        s >> p;

        if (p == "push") {
            int number;
            s >> number;
            mylist.insert(number);
            out.push_back("ok");
            size++;
        } else if (p == "pop") {
            if (!mylist.is_empty()) {
                out.push_back(std::to_string(mylist.remove()));
                size--;
            } else {
                out.push_back("error");
            }
        } else if (p == "front") {
            if (!mylist.is_empty()) {
                out.push_back(std::to_string(mylist.first_element()));
            } else {
                out.push_back("error");
            }
        } else if (p == "size") {
            out.push_back(std::to_string(size));
        } else if (p == "clear") {
            size = 0;
            while ( !mylist.is_empty()) {
                std::to_string(mylist.remove());
            }
            out.push_back("ok");
        } else if (p == "exit") {
            out.push_back("bye");
            break;
        }
    }

    for(int i = 0; i < out.size(); i++) {
        std::cout << out[i] << "\n";
    }
    return 0;
}
