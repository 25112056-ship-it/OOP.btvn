#include <iostream>
using namespace std;

int main() {

    // Câu 1
    int seconds;
    seconds = 42 * 60 + 42;
    cout << "Seconds = " << seconds << endl;

    // Câu 2
    double mile;
    mile = 10 / 1.61;
    cout << "Miles = " << mile << endl;

    // Câu 3
    double time, speed;

    time = 42 * 60 + 42;

    speed = mile / (time / 3600);

    cout << "Speed = " << speed << endl;

    return 0;
}