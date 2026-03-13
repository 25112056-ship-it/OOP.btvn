#include <iostream>
#include <ctime>

using namespace std;

int main() {

    // lấy thời gian hiện tại (seconds từ 1/1/1970)
    time_t now = time(0);

    cout << "Seconds since epoch: " << now << endl;

    // đổi sang ngày
    int days = now / (24 * 3600);

    // phần còn lại trong ngày
    int remain = now % (24 * 3600);

    int hours = remain / 3600;
    remain = remain % 3600;

    int minutes = remain / 60;
    int seconds = remain % 60;

    cout << "Days since 1970: " << days << endl;

    cout << "Time: "
         << hours << ":"
         << minutes << ":"
         << seconds << endl;

    return 0;
}