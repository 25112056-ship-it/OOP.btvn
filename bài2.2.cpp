#include <iostream>
using namespace std;

int main() {

    // 1. Volume of sphere r = 5
    double pi = 3.14159;
    double r = 5;
    double V;

    V = 4.0/3 * pi * r*r*r;
    cout << "Volume = " << V << endl;


    // 2. Book price
    double price = 24.95;
    double discount = 0.4;
    double ship1 = 3;
    double ship2 = 0.75;

    double cost_book;
    double total;

    cost_book = price * (1 - discount);

    total = 60 * cost_book + ship1 + 59 * ship2;

    cout << "Total cost = " << total << endl;


    // 3. Running time

    int start = 6*60 + 52; // minutes

    int easy = 8*60 + 15;
    int tempo = 7*60 + 12;

    int total_time;

    total_time = easy + 3*tempo + easy;

    int finish = start*60 + total_time;

    int hour = finish / 3600;
    int minute = (finish % 3600) / 60;

    cout << "Finish time = " << hour << ":" << minute << endl;

    return 0;
}