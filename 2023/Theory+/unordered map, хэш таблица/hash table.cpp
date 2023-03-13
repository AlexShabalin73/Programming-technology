#include <iostream>
#include <list>
#include <algorithm>

class HashTable {
private:
    static const int tableSize = 10;
    std::list<std::pair<int, std::string>> table[tableSize];

public:
    HashTable() {}

    // ������� ��� ���������� ����
    int hashFunction(int key) {
        return key % tableSize;
    }

    // ������� ��� ���������� �������� � �������
    void insertValue(int key, std::string value) {
        int index = hashFunction(key);
        table[index].push_back(std::make_pair(key, value));
    }

    // ������� ��� ������ �������� �� �����
    std::string searchValue(int key) {
        int index = hashFunction(key);
        for (auto& it : table[index]) {
            if (it.first == key) {
                return it.second;
            }
        }
        return "";
    }

    // ������� ��� �������� �������� �� �������
    void deleteValue(int key) {
        int index = hashFunction(key);
        for (auto& it : table[index]) {
            if (it.first == key) {
                table[index].remove(it);
                return;
            }
        }
    }

    // ������� ��� ������ �������� ���-�������
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

    // ���������� �������� � �������
    hashTable.insertValue(1, "value1");
    hashTable.insertValue(2, "value2");
    hashTable.insertValue(11, "value3");
    hashTable.insertValue(4, "value4");

    hashTable.displayTable();
    return 0;
}
