// Zadání: Četnost cifer v textovém souboru 📑
// Napište program v C++, který:
// Otevře textový soubor (název souboru může být pevně dán v kódu, např. "data.txt").
// Přečte celý obsah souboru znak po znaku.
// Spočítá, kolikrát se v souboru vyskytuje každá z cifer 0 až 9.

#include <iostream>
#include <fstream>

int main() {
    int digitCount = 0;

    std::ifstream file("data.txt");
    char ch;

    if (!file.is_open()) {
        std::cerr << "Error: Could not be opened." << "\n";
        return 1;
    }

    while (file.get(ch)) {
        if (ch >= '0' and ch <= '9') {
            digitCount++;
        }
    }

    std::cout << "There are " << digitCount << " digits in the file\n";

    file.close();
    return 0;
}