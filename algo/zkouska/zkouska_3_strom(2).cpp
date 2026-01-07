// Je dána definice uzlu binárního stromu:
// struct Uzel {
//   int hodnota;
//   Uzel *levy, *pravy;
// };
// Implementujte podprogram , který určí počet uzlů stromu, v nichž se nacházejí hodnota začíná velkým písmenem.


#include <iostream>

struct Uzel {
    std::string text;
    Uzel *levy, *pravy;
};

// recursion-based search
int pocetUzlu(Uzel* koren) {
    if(koren==nullptr) {return 0;}

    if(koren->text[0] >= 'A' && koren->text[0] <= 'Z') {
        return pocetUzlu(koren->pravy) + pocetUzlu(koren->levy) + 1;
    } else {
        return pocetUzlu(koren->pravy) + pocetUzlu(koren->levy);
    }
}