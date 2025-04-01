#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <utility>

// Ввдение в шаблоны

using namespace std;

template <typename T> // ключевоек слово для объялвения типа Т
T Sqr(T x) {
    return x * x;
}
//Тип T компилятор выведет сам, чтобы типы поддерживали умножение.
template <typename First, typename Second>
pair <First, Second> operator * (const pair<First, Second>& p1, const pair<First, Second>& p2) {
    First f = p1.first * p2.first;
    Second s = p1.second * p2.second;
    return { f, s };
}

template <typename T>
ostream& operator<< (ostream& out, const vector<T>& vi) {
    for (const auto& i : vi) {
        out << i << " ";
    }
    return out;
}

int main()
{
    cout << Sqr(2.5) << endl;
    cout << Sqr(5) << endl;
    auto p = make_pair(2.5, 3);
    auto res = Sqr(p);
    cout << res.first << " " << res.second << endl;

    vector <double> vi = { 1, 2.5, 3 };
    cout << vi << endl;
}
/*
Подведём итоги :
1. Шаблонные функции объявляются так : template <typename T> T Foo(T var) { ... };
2. Вместо слова typename можно использовать слово class, т.к.в данном контексте они
эквивалентны;
3. Шаблонный тип может автоматом выводиться из контекста вызова функции;
4. После объявления ипользуется, как и любой другой тип;
5. Выведение шаблонного типа может происходить либо автоматически, на основе аргументов, либо с помощью явного указания в угловых скобках(std::max<double>(2, 3.5));
6. Цель шаблонных функций : сделать код короче(избавившись от дублирования) и универсальнее.
*/
