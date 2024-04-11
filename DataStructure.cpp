#include <stdexcept>

class DataStructure {
public:
    // Destruktor
    virtual ~DataStructure() {}

    // Metody wspólne
    virtual void addLast(int element) = 0;
    virtual void addFirst(int element) = 0;
    virtual void addAtIndex(int element, int index) = 0; // W DynamicArray wymaga zmiany logiki
    virtual bool contains(int element) = 0;
    virtual int get(int index) = 0; // W DynamicArray rzuca wyjątek out_of_range
    virtual int getSize() const = 0;
    virtual void deleteFirst() = 0;
    virtual void deleteLast() = 0;
    virtual void deleteAll() = 0;

};
