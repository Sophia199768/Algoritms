#include <iostream>

class RGBToHex {
public:
    static std::string rgb(int r, int g, int b) {
        std::string answer;
        std::string str;
        int help;
        int value;

        for (int i = 0; i < 3; i++) {
            switch (i) {
                case 0:
                    value = r;
                    break;
                case 1:
                    value = g;
                    break;
                case 2:
                    value = b;
                    break;
            }

            answer = "";

            if (value >= 255) {
                str += "FF";
            }
            else if (value <= 0) {
                str += "00";
            } else {
                while (value != 0) {
                    help = value % 16;
                    if (help > 9) {
                        answer += char(help - 10 + 'A');
                    } else {
                        answer += std::to_string(help);
                    }
                    value /= 16;
                }
                if (answer.size() == 1) {
                    answer += "0";
                }

                std::reverse(answer.begin(), answer.end());
                str += answer;
            }
        }
        return str;
    }
};


int main() {
    RGBToHex my_train;
    std::string answer;

    answer = my_train.rgb(1, 2, 3);

    std::cout << answer;
    return 0;
}