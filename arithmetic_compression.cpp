#include <iostream>
int m;
struct Segment {
    double left;
    double right;
};

void defineSegments(char letters[m], double probability[m]) {
    Segment[m] segment;
    double l = 0;
    for i = 0 to m - 1 {
        segment[letters[i]].left = l;
        segment[letters[i]].right = l + probability[i];
        l = segment[letters[i]].right;
    }
    return segment
}
double arithmeticCoding(letters: char[m], probability: double[m], s: char[n]) {
    Segment[m] segment = defineSegments(letters, probability)
    double left = 0
    double right = 1
    for i = 0 to n - 1 {
        char symb = s[i]
        double newRight = left + (right - left) * segment[symb].right
        double newLeft = left + (right - left) * segment[symb].left
        left = newLeft
        right = newRight
    }
    return (left + right) / 2
}

int main() {
    return 0;
}