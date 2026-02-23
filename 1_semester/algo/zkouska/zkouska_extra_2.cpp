// Zadání: Četnost cifer v textovém souboru 📑
// Napište program v C++, který:
// Otevře textový soubor (název souboru může být pevně dán v kódu, např. "data.txt").
// Přečte celý obsah souboru znak po znaku.
// Spočítá, kolikrát se v souboru vyskytuje každá z cifer 0 až 9.

#include <iostream>
#include <fstream>

int main() {
    int digits[10] = {};

    std::ifstream file("data.txt");
    char ch;

    if (!file.is_open()) {
        std::cerr << "Could not be opened\n";
        return 1;
    }

    while (file.get(ch)) {
        if (ch >= '0' && ch <= '9') {
            digits[ch - '0']++;
        }
    }

    std::cout << "Following digits in data.txt:\n";

    for (int i = 0; i < 10; i++) {
        std::cout << i << " :" << digits[i] << "\n";
    }

    file.close();
    return 0;
}