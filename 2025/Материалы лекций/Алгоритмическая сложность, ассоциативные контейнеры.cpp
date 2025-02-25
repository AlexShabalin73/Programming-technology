#include <iostream>
#include <map>
#include <unordered_map>
#include <set>

// Ассоциативные контейнеры - тип контейнеров, которые организуют данные в виде пары <Ключ> - <Значение>. Словарь. 

/*
    Нотация O (Big O) используется в информатике для описания асимптотической сложности алгоритмов, то есть того, как изменяется время выполнения или использование памяти в зависимости от размера входных данных.
    O(1) — Константная сложность. Время выполнения не зависит от размера входных данных. Доступ к элементу массива int x = arr[2];
    O(log n) — Логарифмическая сложность. Обычно связано с алгоритмами деления данных пополам. Эффективно для больших данных: поиск в отсортированном массиве из миллиона элементов выполняется примерно за 20 шагов.
    O(n) — Линейная сложность - время выполнения программы линейно зависит от количества входных данных. for (int i=0; i < n; i++) { cout << a[i]; }; Простой перебор данных.
    O(n * log n) — Линейно-логарифмическая сложность; Эффективные алгоримты сортировки массивов;
    O(n*2) — Квадратичная сложность. Время выполнения пропорционально квадрату размера входных данных.
    void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; ++i) {
        for (int j = 0; j < n-i-1; ++j) {
            if (arr[j] > arr[j+1]) {
                std::swap(arr[j], arr[j+1]);
                }
            }
        }
    }
    Медленно работает на больших данных, избегайте при больших объемах.
    O(2^n) — Экспоненциальная сложность. Время выполнения удваивается с добавлением каждой новой единицы данных.
    int fibonacci(int n) {
        if (n <= 1) return n;
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
    O(n!) — Факториальная сложность
 */

using namespace std;

void PrintMap(const map<int, string>& m) {
    cout << "Size = " << m.size() << endl;
    for (auto item : m) {
        cout << item.first << ": " << item.second << endl;
    }
}

// Построение обратного словаря
map <string, int> BuildReverseMap(const map <int, string>& m) {
    map <string, int> result;
    for (auto item : m) {
        result[item.second] = item.first;
    }
    return result;
}
void PrintReversedMap(const map<string, int>& m) {
    cout << "Size = " << m.size() << endl;
    for (auto item : m) {
        cout << item.first << ": " << item.second << endl;
    }
}

void PrintSet(const set<string>& s) {
    cout << "Size = " << s.size() << endl;
    for (auto x : s) {
        cout << x << endl;
    }
}


int main()
{
    map <int, string> events;
    events[1950] = "Bjarne Stroustrup birth";
    events[1941] = "Dennis Ritchie's birth";
    events[1970] = "Unix epoch start";
    PrintMap(events);
    /* Ключи уникальны и отсортированы в порядке возрастания (по умолчанию с использованием operator<)
    Почему сортирует? Внутри map реализован как красно-черное дерево поиска - сложность поиска элемента O(log(n)) 
    */
    multimap <int, string> grades;
    grades.insert({ 5, "Ivanov" });
    grades.insert({ 4, "Petrov" });
    grades.insert({ 4, "Filipov" });
    for (const auto& [grade, name] : grades) {
        cout << grade << ": " << name << endl;
    }
    /*  Позволяет хранить несколько значений с одинаковыми ключами.
        Ключи отсортированы в порядке возрастания.
        Подходит для случаев, когда одному ключу может соответствовать несколько значений.
    */
    unordered_map <string, int> phoneBook;
    phoneBook["Alice"] == 12345;
    phoneBook.insert({ "Charlie", 54321 });
    cout << " Alices' number: " << phoneBook["Alice"] << endl;
    if (phoneBook.find("David") == phoneBook.end()) { // Если элемент не найден то find вернет итератор на конец контейнера
        cout << "Not found";
    }
    for (const auto& [name, number] : phoneBook) {
        cout << name << ": " << number << endl;
    }
    // Внутренняя структура - Хэш-таблицы (неупорядоченная). Сложность поиска элемента О(1). Неупорядоченные элементы. Более требовательное решение к хранению, нужно больше памяти.
    
    vector <string> words = { "one", "two", "one", "three"}; // Задача подсчета количества элементов последовательности
    map <string, int> counters;

    /* Избыточно
    for (const string& word : words) {
        if (counters.count(word) == 0) {
            counters[word] = 1;
        }
        else {
            ++counters[word];
        }
    }
    */
    // Элемент словаря создается на лету, при первом обращении к нему он сразу инициализируется значением по умолчанию
    for (const string& word : words) {
        ++counters[word];
    }

    // Группировка слов по первой букве
    map <char, vector<string>> grouped_words;
    for (const string& word : words) {
        grouped_words[word[0]].push_back(word);
    }

    for (const auto& item : grouped_words) {
        cout << item.first << " = ";
        for (const string& word : item.second) {
            cout << word << " ";
        }
        cout << endl;
    }

    // Контейнер - set. Множество. Хранит только уникальные ключи (без значений). Элементы хранятся в отсортированном порядке. Поддерживает быстрый поиск и удаление. multiset - также есть по аналогии c multimap
    set <string> is_famous_person;
    is_famous_person.insert("Stroustrup");
    is_famous_person.insert("Ritchie");
    is_famous_person.insert("Stroustrup");
    PrintSet(is_famous_person);
    is_famous_person.erase("Stroustrup");
    set <string> month_names = { "January", "March", "February", "March" };
    set <string> other_month_names = { "March", "January", "February" };

    cout << (month_names == other_month_names) << endl;
    
    // Проверка принадлежности элемента множеству
    cout << month_names.count("January") << endl;

    // Создание множества по вектору
    vector<string> v = { "a", "b", "a" };
    set <string> s(begin(v), end(v));


}


