#include <iostream>
using namespace std;

// line 2x2
void line2() {
    cout << "+ - - - + - - - +" << endl;
}

// row 2x2
void row2() {
    cout << "|       |       |" << endl;
}

// line 4x4
void line4() {
    cout << "+ - - - + - - - + - - - + - - - +" << endl;
}

// row 4x4
void row4() {
    cout << "|       |       |       |       |" << endl;
}

int main() {

    // ===== grid 2x2 =====
    line2();
    row2();
    row2();
    row2();
    line2();
    row2();
    row2();
    row2();
    line2();

    cout << endl;

    // ===== grid 4x4 =====
    line4();
    for(int i=0;i<4;i++) row4();

    line4();
    for(int i=0;i<4;i++) row4();

    line4();
    for(int i=0;i<4;i++) row4();

    line4();
    for(int i=0;i<4;i++) row4();

    line4();

    return 0;
}