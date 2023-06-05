#include <iostream>
#include <vector>

std::vector<std::string> answer;
int big_rotate = 2;

struct Node {
    std::string key;
    int index;
    int height;
    Node *left;
    Node *right;

    Node(std::string value) {
        key = value;
        left = nullptr;
        right = nullptr;
        height = 1;
        index = 1;
    }
};

struct Library {

    void new_height(Node *n) {
        long left;
        long right;
        (n->left == nullptr ? left = 0 : left = n->left->height);
        (n->right == nullptr ? right = 0 : right = n->right->height);
        n->height = std::max(right, left) + 1;

        (n->left == nullptr ? left = 0 : left = n->left->index);
        (n->right == nullptr ? right = 0 : right = n->right->index);
        n->index = left + right + 1;
        return;
    }

    Node *left(Node *a) {
        Node *b = a->right;
        a->right = b->left;
        b->left = a;
        new_height(a);
        new_height(b);
        return b;
    }

    Node *right(Node *a) {
        Node *b = a->left;
        a->left = b->right;
        b->right = a;
        new_height(a);
        new_height(b);
        return b;
    }

    Node *big_left_rotate(Node *node) {
        node->right = right(node->right);
        return left(node);
    }

    Node *big_right_rotate(Node *node) {
        node->left = left(node->left);
        return right(node);
    }

    long balance_(Node *a) {
        if (a != nullptr) {
            long right;
            long left;
            (a->right != nullptr) ? right = a->right->height : right = 0;
            (a->left != nullptr) ? left = a->left->height : left = 0;
            return right - left;
        } else {
            return 0;
        }
    }

    Node *insert(Node *root, std::string key) {
        if (root == nullptr) {
            return new Node(key);
        }

        key <= root->key ? root->left = insert(root->left, key) : 0;
        key > root->key ? root->right = insert(root->right, key) : 0;

        new_height(root);
        if (balance_(root) == big_rotate) {
            if (balance_(root->right) == -1) {
                return big_left_rotate(root);
            } else {
                return left(root);
            }
        }

        if (balance_(root) == -big_rotate) {
            if (balance_(root->left) == 1) {
                return big_right_rotate(root);
            } else {
                return right(root);
            }
        }
        return root;
    }

    std::string name(Node* root, int my_index, int k) {
        if (root != nullptr) {
            if (root->left != nullptr) {
                if (root->left->index + k == my_index) {
                    return root->key;
                } else if (root->left->index + k < my_index) {
                    k += root->left->index + 1;
                    return name(root->right, my_index, k);
                } else {
                    return name(root->left, my_index, k);
                }
            } else {
                if (k == my_index) {
                    return root->key;
                } else if (k < my_index) {
                    k += 1;
                    return name(root->right, my_index, k);
                } else {
                    return name(root->left, my_index, k);
                }
            }
        }
    }
};

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    int N;
    std::cin >> N;
    Library my_library;
    Node *root = nullptr;

    int k;
    std::string value = "";

    for (int i = 0; i < N; i++) {
        std::cin >> value;
        if (value[0] >= 'a' and value[0] <= 'z') {
            root = my_library.insert(root, value);
        } else {
            k = std::stoi(value) - 1;
            std::string surname = my_library.name(root, k, 0);
            answer.push_back(surname);
        }
        value = "";
    }

    for (int i = 0; i < answer.size(); i++) {
        std::cout << answer[i] << '\n';
    }

    return 0;
}