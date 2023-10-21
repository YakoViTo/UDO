#include <iostream>
int main() {
    
    int L, H;
    char c = '#';
    do {
        std::cin >> L >> H;
    } while (L > 30 && L <= 0 && H > 30 && H <= 0);
    std::string T;
    std::getline(std::cin, T);
    for (int i = 0, k = i; i < H; ++i) {
        int j = 0;
        k = i;
        if (i != H / 2)
            k = (i % 2) ? 1 : L - 1;
        for (; j < k; j++)
            std::cout << c;
        for (; j < L; j++)
            std::cout << ' ';
        std::cout << std::endl;
    }
    return 0;
}
