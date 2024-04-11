#include <iostream>
#include <stdexcept>


using namespace std;

template<typename T>
class DynamicArray {
private:
    T *array;
    int capacity;
    int size;

    void resize(int newCapacity) {
        T *newArray = new T[newCapacity];
        for (int i = 0; i < size; i++) {
            newArray[i] = array[i];
        }
        delete[] array;
        array = newArray;
        capacity = newCapacity;
    }

public:
    DynamicArray(int initialCapacity = 10) : capacity(initialCapacity), size(0) {
        array = new T[capacity];
    }

    ~DynamicArray() {
        delete[] array;
    }

    bool contains(const T &element) {
        for (int i = 0; i < size; i++) {
            if (array[i] == element) {
                return true;
            }
        }
        return false;
    }

    void deleteAll() {
        size = 0;
    }

    void deleteFirst(int numberOfElements) {
        if (size == 0 || numberOfElements <= 0) return; // Jeśli tablica jest pusta lub nie ma co usuwać

        if (numberOfElements >= size) {
            size = 0; // Jeśli liczba do usunięcia jest równa lub większa niż rozmiar, usuń wszystko
        } else {
            for (int i = 0; i < size - numberOfElements; i++) {
                array[i] = array[i + numberOfElements]; // Przesuń pozostałe elementy do przodu
            }
            size -= numberOfElements; // Zmniejsz rozmiar tablicy
        }
    }
    void deleteFirst() {
        if (size == 0) return;
        for (int i = 0; i < size - 1; i++) {
            array[i] = array[i + 1];
        }
        size--;
    }

    void deleteLast(int numberOfElements) {
        if (numberOfElements <= 0) return; // Brak działania, jeśli podano nieprawidłową liczbę elementów
        if (numberOfElements >= size) {
            size = 0; // Usuwamy wszystkie elementy, jeśli liczba jest równa lub większa niż aktualny rozmiar
        } else {
            size -= numberOfElements; // Zmniejszamy rozmiar o podaną liczbę elementów
        }
    }

    T get(int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of range");
        }
        return array[index];
    }

    int getSize() const {
        return size;
    }

    int getCapacity() const {
        return capacity;
    }

    void addLast(const T &element) {
        if (size == capacity) {
            resize(capacity * 2);
        }
        array[size++] = element;
    }

    void addFirst(T element) {
        if (size == capacity) {
            resize(capacity * 2);
        }
        for (int i = size; i > 0; i--) {
            array[i] = array[i - 1];
        }
        array[0] = element;
        size++;
    }


    void addAtMiddle(const T &element) {
        if (size == capacity) {
            resize(capacity * 2);
        }
        int middle = size / 2;
        for (int i = size; i > middle; i--) {
            array[i] = array[i - 1];
        }
        array[middle] = element;
        size++;
    }

    void deleteFromMiddle(int numberOfElements) {
        if (size == 0 || numberOfElements <= 0) return; // Brak elementów do usunięcia

        // Obliczanie indeksu początkowego i końcowego do usunięcia
        int start = (size - 1) / 2 - numberOfElements / 2;
        int end = start + numberOfElements;

        // Ograniczenie zakresu, aby nie wyjść poza rozmiar tablicy
        start = max(start, 0);
        end = min(end, size);

        // Usuwanie elementów, przesuwając pozostałe elementy do przodu
        int j = start;
        for (int i = end; i < size; i++, j++) {
            array[j] = array[i];
        }

        // Zaktualizowanie rozmiaru tablicy
        size = j;
    }

    void deleteFromMiddle() {
        if (size == 0) return;
        int middle = (size - 1) / 2;
        for (int i = middle; i < size - 1; i++) {
            array[i] = array[i + 1];
        }
        size--;
    }

    void print() const {
        for (int i = 0; i < size; i++) {
            std::cout << array[i];
            if (i < size - 1) {
                std::cout << " "; // Add a space between elements, but not after the last element
            }
        }
        std::cout << std::endl; // New line after printing all elements
    }
};
