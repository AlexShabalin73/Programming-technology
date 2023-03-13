#include <iostream>
#include <list>
#include <algorithm>

class HashTable {
private:
    static const int tableSize = 10;
    std::list<std::pair<int, std::string>> table[tableSize];

public:
    HashTable() {}

    // функция для вычисления хэша
    int hashFunction(int key) {
        return key % tableSize;
    }

    // функция для добавления значения в таблицу
    void insertValue(int key, std::string value) {
        int index = hashFunction(key);
        table[index].push_back(std::make_pair(key, value));
    }

    // функция для поиска значения по ключу
    std::string searchValue(int key) {
        int index = hashFunction(key);
        for (auto& it : table[index]) {
            if (it.first == key) {
                return it.second;
            }
        }
        return "";
    }

    // функция для удаления значения из таблицы
    void deleteValue(int key) {
        int index = hashFunction(key);
        for (auto& it : table[index]) {
            if (it.first == key) {
                table[index].remove(it);
                return;
            }
        }
    }

    // функция для вывода значений хэш-таблицы
    void displayTable() {
        for (int i = 0; i < tableSize; i++) {
            std::cout << "Bucket " << i << ": ";
            for (auto& it : table[i]) {
                std::cout << "[" << it.first << ", " << it.second << "]";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    HashTable hashTable;

    // добавление значений в таблицу
    hashTable.insertValue(1, "value1");
    hashTable.insertValue(2, "value2");
    hashTable.insertValue(11, "value3");
    hashTable.insertValue(4, "value4");

    hashTable.displayTable();
    return 0;
}
