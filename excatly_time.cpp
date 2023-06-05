#include <iostream>

int main() {
    std::string A;
    std::string B;
    std::string C;
    int timeA;
    int timeB;
    int timeC;
    int exact;
    int hh = 0;
    int mm = 0;
    int ss = 0;
    std::string hh1, mm1, ss1 = "";
    std::string ans = "";
    std::cin >> A >> B >> C;


    for (int i = 0; i < A.size(); i++) {
        if (i < 2) {
            hh1 += A[i];
        }
        if (i < 5 and i > 2) {
            mm1 += A[i];
        }
        if (i < 8 and i > 5) {
            ss1 += A[i];
        }
    }
    timeA = std::stoi(hh1) * 3600 + std::stoi(mm1) * 60 + std::stoi(ss1);


    hh1 = "";
    mm1 = "";
    ss1 = "";
    for (int i = 0; i < B.size(); i++) {
        if (i < 2) {
            hh1 += B[i];
        }
        if (i < 5 and i > 2) {
            mm1 += B[i];
        }
        if (i < 8 and i > 5) {
            ss1 += B[i];
        }
    }
    timeB = std::stoi(hh1) * 3600 + std::stoi(mm1) * 60 + std::stoi(ss1);

    hh1 = "";
    mm1 = "";
    ss1 = "";

    for (int i = 0; i < C.size(); i++) {
        if (i < 2) {
            hh1 += C[i];
        }
        if (i < 5 and i > 2) {
            mm1 += C[i];
        }
        if (i < 8 and i > 5) {
            ss1 += C[i];
        }
    }
    timeC = std::stoi(hh1) * 3600 + std::stoi(mm1) * 60 + std::stoi(ss1);


    if (timeC - timeA  < 0) {
        exact = (24 * 3600 - timeA + timeC) / 2 ;
    } else {
        exact = (timeC - timeA) / 2;
    }

    if (abs(timeC - timeA) % 2 != 0) {
        exact += 1;
    }
    exact += timeB;

    if (exact >= 3600) {
        hh = exact / 3600;
        exact %= 3600;
        if (hh > 23) {
            hh -= 24;
        }
    }
    if (exact >= 60) {
        mm = exact / 60;
        exact %= 60;
    }
    if (exact > 0) {
        ss = exact;
    }

    if (hh < 10) {
        if (hh != 0) {
            ans += std::to_string(0) + std::to_string(hh) + ':';
        } else {
            ans += "00:";
        }
    } else {
        ans += std::to_string(hh) + ':';
    }

    if (mm < 10) {
        if (mm != 0) {
            ans += std::to_string(0) + std::to_string(mm) + ':';
        } else {
            ans += "00:";
        }
    } else {
        ans += std::to_string(mm) + ':';
    }

    if (ss < 10) {
        if (ss != 0) {
            ans += std::to_string(0) + std::to_string(ss);
        } else {
            ans += "00";
        }
    } else {
        ans += std::to_string(ss);
    }
    std::cout << ans;
    return 0;
}