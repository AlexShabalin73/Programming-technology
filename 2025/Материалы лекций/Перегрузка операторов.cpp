#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;
// Конструктор по умолчанию
struct Duration {
    int hour;
    int min;

    Duration(int h = 0, int m = 0) {
        int total = h * 60 + m;
        hour = total / 60;
        min = total % 60;
    }
};

//  Перегрузка операторов вывода в поток
ostream& operator<<(ostream& stream, const Duration& duration) {
    stream << setfill('0');
    stream << setw(2) << duration.hour << ":" << setw(2) << duration.min;
    return stream;
}

// Перегрузка оператора ввода в поток
istream& operator>>(istream& stream, Duration& duration) {
    stream >> duration.hour;
    stream.ignore(1);
    stream >> duration.min;
    return stream;
}


/* было
Duration ReadDuration(istream& stream) {
    int h = 0;
    int m = 0;
    stream >> h;
    stream.ignore(1);
    stream >> m;
    return Duration{ h, m };
}

void PrintDuration(ostream& stream, const Duration& duration) {
    stream << setfill('0');
    stream << setw(2) << duration.hour << ":" << setw(2) << duration.min;
}
*/

// Перегрузка арифметических операций
Duration operator+(const Duration & lhs, const Duration & rhs) {
    return Duration(lhs.hour + rhs.hour, lhs.min + rhs.min);
}

//Перегрузка операторов сравнения
void PrintVector(const vector<Duration>& durs) {
    for (const auto& d : durs) {
        cout << d << ' ';
    }
    cout << endl;
}

// Определим функцию компаратор и она пойдет третьим аргументов в sort
bool CompareDuration(const Duration& lhs, const Duration& rhs) {
    if (lhs.hour == rhs.hour) {
        return lhs.min < rhs.min;
    }
    return lhs.hour < rhs.hour;
}
// Перегрузка оператора Меньше.
bool operator<(const Duration& lhs, const Duration& rhs) {
    if (lhs.hour == rhs.hour) {
        return lhs.min < rhs.min;
    }
    return lhs.hour < rhs.hour;
}



int main()
{
    stringstream dur_ss("03:50");
    Duration dur1;
    dur_ss >> dur1;

    Duration dur2 = { 2, 45 };
    Duration dur3 = dur1 + dur2;
    vector <Duration> v{ dur1, dur2, dur3 };
    sort(begin(v), end(v));
    PrintVector(v);

    //cout << "hello" << " world";
    // operator<< - первым аргументов принимает поток, а вторым строку для вывода
    //operator<<(operator<<(cout, "hello", " world");
}

