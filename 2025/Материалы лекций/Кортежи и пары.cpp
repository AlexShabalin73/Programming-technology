#include <iostream>
#include <vector>
#include <tuple> // Кортеж
#include <utility>
#include <string>
#include <map>
#include <set>

//Кортежи и пары

using namespace std;

struct Date {
    int year;
    string month;
    int day;
};
/*
bool operator <(const Date& lhs, const Date& rhs) {
    if (lhs.year != rhs.year) {
        return lhs.year < rhs.year;
    }
    if (lhs.month != rhs.month) {
        return lhs.month < rhs.month;
    }
    return lhs.day < rhs.day;
}
*/
/*
bool operator <(const Date& lhs, const Date& rhs) {
    return vector<int>{lhs.year, lhs.month, lhs.day} <
        vector<int>{rhs.year, rhs.month, rhs.day};
}*/

// Но тип vector слишком мощный, не совсем логично использовать именно его. 
// Нужно всего лишь объединит каким-то образом три элемента одной структуры и три элемента другой структуры. В контексте котором описали выше, vector работатет только для однотипных данных
// Как объединить различные типы в один массив? 

bool operator <(const Date& lhs, const Date& rhs) {
    auto lhs_key = tie(lhs.year, lhs.month, lhs.day);
    auto rhs_key = tie(lhs.year, lhs.month, lhs.day);
    // То есть они имеют тип tuple<const int&, const string&, const int&>. Tuple – это кортеж,
    // т.е.структура из ссылок на нужные нам данные(возможно, разнотипные).
    return lhs_key < rhs_key;
}

/*
int main()
{
    tuple<int, string, bool> t(7, "C++", true);
    //auto t1 = tie(7, "C++", true); // tie создает кортеж из ссылок на объекты (которые хранятся в каких-то переменных)
    auto t1 = make_tuple(7, "C", true);
    cout << get<1>(t1) << endl;
    pair <int, string> p(7, "C++");
    cout << p.first << " " << p.second << endl;
}
// pair - пара частный случай кортежа, и отличие от кортежа в том что к полям можно обратиться через first и second
/*
в C++ 17 разрешается не указывать шаблонные параметры tuple в < ... >, т. е.
кортеж можно создавать так:
tuple t(7, "C++", true);
*/

// Возврат нескольких значений из функции - еще одна область применения кортежей и пар. 
class Cities { // класс городов и стран
public:
    tuple <bool, string> FindCountry(const string& city) const {
        if (city_to_country.count(city) == 1) {
            return { true, city_to_country.at(city) };
        } // city_to_country[city] выдало бы ошибку, потому что могло нарушить const словаря
        else if (ambigious_cities.count(city) == 1) {
            return { false, "Ambigious" };
        }
        else {
            return { false, "No exists" };
        }
    }

private:
    map <string, string> city_to_country; // по названию города храним название страны
    set <string> ambigious_cities; // множество городов, принадлежащих нескольким странам
};

int main() {
    Cities cities;
    bool success;
    string message;
    tie(success, message) = cities.FindCountry("Volgograd");
    cout << success << " " << message << endl;

    map <string, pair<double, double>> cities1;
    for (const auto& item : cities1) {
        cout << item.second.first << endl; // очень сложно читаемый код
    }
}
/* если вы хотите вернуть несколько значений из функции или из метода, используйте
кортеж.А если вы хотите сохранить этот кортеж в какой - то набор переменных, используйте
structured bindings или функцию tie.

Заключение: кортежи позволяют упростить написание оператора < или вернуть несколько зна-
чений из функции. Пары – это частный случай кортежей, у которых понятные названия полей,
к которым удобно обращаться
*/
