#include <iostream>
#include <vector>
#include <algorithm>

/*
Лямбда-выражение (lambda expression) — это анонимная функция, определяемая прямо в месте, где она требуется, и возвращающая функцию-объект (closure), который можно вызвать позднее.
Лямбды появились в C++11 и стали мощным инструментом для передачи логики в алгоритмы STL, создания колбэков, и написания коротких функций на лету.

общий синтаксис:
[capture](parameters) -> return_type {
    // тело функции
}
[capture] (список захвата) – важная часть, определяет, какие внешние переменные из окружающего контекста доступны внутри лямбды, и как они захватываются: по значению или по ссылке
[&] – захват всех используемых внешних переменных по ссылке. То есть лямбда хранит ссылку на оригинал.
[=] – захват всех используемых внешних переменных по значению (копируется значение при создании лямбды). Внутри они как константы (по умолчанию) – изменение копий не влияет на оригинал.
(parameters) – список параметров, как у обычной функции. Можно указывать типы явно, либо с C++14 можно использовать auto в параметрах (generic lambda). Если параметров нет, пишут просто ().
-> return_type – возвращаемый тип. Можно опустить, и тогда компилятор попытается вывести тип из return в теле.




using namespace std;


int main()
{
    vector <int> data = { 5, 2, 8, 1, 3 };
    sort(begin(data), end(data), [](int a, int b) {
        return a < b;
     })
    // найдем первый элемент больше 5
    auto it = find_if(begin(data), end(data), [](int x) {
        return x > 5;
    })
    if (it != data.end()) {
        cout << "First element > 5 = " << *it << endl;
    }
    else {
        cout << "Not found! " << endl;
    }
    for_each(data.begin(), data.end(), [](int n) {
        cout << n << " ";
        })

    vector <int> nums = { 10, 20, 30, 40 };
    int thresold = 25;
    int counAbove = count_if(begin(nums), end(nums), [thresold](int x) {
        return x > thresold;
        })
    int value = 1;
    auto lam = [value]() mutable {
        value += 5;
        cout << "Inside lamblda, value = " << value << endl; // 6
     }
    lam();
    cout << "Outside lambda, original value = " << value << endl; //1
}

*/

/* 
    Введение в структуры и классы.
*/

void PrintLecture(const string& title, int duration, const string& author) {
    cout << "Title" << title << "duration:" << duration << "author: " << author;
}
void PrintCourse(const vector<string>& titles, const vector<int>& durations, const vector<string>& authors) {
    int i = 0;
    while (i < titles.size()) {
        PrintLecture(titles[i], durations[i], authors[i]);
    }
}
/*
Основные недостатки такого подхода:
1. Хочется работать с объектами (лекциями), а не отдельно с каждой из составляющих характеристик (название, продолжительность,
имя лектора). Другими словами, в коде неправильно выражается намерение: вместо того, чтобы передать в качестве параметра лекцию,
передается название, продолжительность и имя автора.
2. При добавлении или удалении характеристики нужно менять заголовки функций, а также все их вызовы.
3. Отсутствует единый список характеристик. Не существует единого места, где указаны все характеристики объекта
*/

struct Lecture {
    string title;
    int duration;
    string author;
};

void PrintLecure(const Lecture& lecture) {
    cout << "Title: " << lecture.title <<
        << ", duration " << lecture.duration <<
        << ", author " << lecture.author << endl;
}

void PrintCourse(const vector<Lecture>& lectures) {
    for (Lecture lecture : lectures) {
        PrintLecture(lecture);
    }
}
/* Особо отметим, что хоть и был определен пользовательский тип дан-
ных, можно создавать контейнеры, элементы которого будут иметь такой
тип. Более того, итерирование в данном случае уже можно производить
с помощью цикла range-based for, а не while.
*/

// Вложенные структуры

struct LectureTitle {
    string specialization;
    string course;
    string week;
};

struct DetailedLecture {
    LectureTitle title;
    int duration;
};
/* Вариант ДО
struct Route {
private:
    string sourse;
    string destination;
    int length;
};
// Можно случайно изменить значение length для отдельного конкретного маршрута
// Можно обновить один из пунктов и забыть обновить длину маршрута
*/

struct Route {
public:
    string GetSource() { return source };
    string GetDestination() { return destination };
    int GetLength() { return length };
private:
    string sourse;
    string destination;
    int length;
};

int ComputeDistance(const string& source, const string& destination) {
    return 150;
}

// Отличия методов от функций:
// • Методы вызваются в контексте конкретного объекта.
// • Методы имеют доступ к приватным полям(и приватным методам) объекта.К ним можно обращаться просто по названию поля.
// На самом деле, структура с добавленными приватной, публичной секциями и методами — это формально уже не структура, а класс.
// Структура(struct) — набор публичных полей.Используется, если не нужно контролировать консистентность.Типичный пример структуры: точка на координатной плоскости. В процессе расчетов ее значения могут легко меняться и не всегда нужно контролировать их.
// Класс (class) скрывает данные и предоставляет определенный интерфейс доступа к ним. Используется, если поля связаны друг с другом и эту связь нужно контролировать.Пример класса — класс Route, описанный выше
// Структуры (struct) и классы (class) – ключевые языковые средства для объединения данных и функций. В C++ struct и class фактически являются почти синонимами: основное техническое различие состоит в том, что члены структуры по умолчанию имеют публичный доступ, а члены класса – приватный
// структуры традиционно применяют для простых “пассивных” объектов данных (например, группировка нескольких полей без инкапсуляции), а классы – для более сложных объектов с инкапсуляцией логики.
// Инкапсуляция – скрытие реализации.

class Route {
public:
    string GetSource() { return source };
    string GetDestination() { return destination };
    int GetLength() { return length };
private:
    string sourse;
    string destination;
    int length;
};

using namespace std;
int main() {
    Lecture lecture1;
    lecture1.title = "OOP";
    lecture1.duration = 80;
    lecture1.author = "Ivanov I.I.";
    Lecture lecture2 = { "OOP", 70; "Petrov P.P." };
    PrintLecture({ "OOP", 70; "Petrov P.P." });
    LectureTitle title = { "C++", "Programming Technology", "OOP" };
    DetailedLecture lecture1 = { title, 5400 };
    DetailedLecture lecture2 = { {"C++", "Informatika", "OOP"}, 5400 };
    cout << lecture2.title.specialization << endl;

    Route route;
    route.source = "Moscow"; // Без поля Private раньше компилировалось, теперь после добавления Private не будет. 
    cout << route.length; // тактоже будет нельзя, Private запрещает любой доступ к полям

    route.GetSource() = "Moscow"; // Бесполезно, поле не изменится
    cout << route.GetLength(); // Так теперь можно: доступ на чтение
    int destination_name_length = route.GetDestination().length();


}