#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

struct Node {
    int element;
    Node* next;
    Node* prev;
    Node(int str) {
        element = str;
        next = nullptr;
        prev = nullptr;
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
        return (first == nullptr and last == nullptr);
    }

    void insert_back(int str) {
        Node* p = new Node(str);
        if (is_empty()) {
            first = p;
            last = p;
            return;
        }
        p->prev = last;
        last->next = p;
        last = p;
    }

    void insert_front(int str) {
        Node* p = new Node(str);
        if (is_empty()) {
            first = p;
            last = p;
            return;
        }
        p->next = first;
        first->prev = p;
        first = p;

    }


    int remove_back() {
        Node *p = last;
        int number = last->element;
        last = p->prev;
        if (last == nullptr) {
           first = nullptr;
        } else {
            last->next = nullptr;
        }
        delete p;
        return number;
    }

    int remove_front() {
        int res = first->element;
        Node *temp;
        temp = first;
        first = first->next;
        if (first == nullptr) {
            last = nullptr;
        } else {
            first->prev = nullptr;
        }
        delete temp;
        return res;
    }


    int first_element() {
        return first->element;
    }

    int last_element() {
        return last->element;
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

        if (p == "push_back") {
            int number;
            s >> number;
            mylist.insert_back(number);
            out.push_back("ok");
            size++;
        } else if (p == "push_front") {
            int number;
            s >> number;
            mylist.insert_front(number);
            out.push_back("ok");
            size++;
        } else if (p == "pop_front") {
            if (!mylist.is_empty()) {
                out.push_back(std::to_string(mylist.remove_front()));
                size--;
            } else {
                out.push_back("error");
            }
        } else if (p == "pop_back") {
            if (!mylist.is_empty()) {
                out.push_back(std::to_string(mylist.remove_back()));
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
        } else if (p == "back") {
            if (!mylist.is_empty()) {
                out.push_back(std::to_string(mylist.last_element()));
            } else {
                out.push_back("error");
            }
        } else if (p == "size") {
            out.push_back(std::to_string(size));
        } else if (p == "clear") {
            size = 0;
            while ( !mylist.is_empty()) {
                std::to_string(mylist.remove_front());
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

