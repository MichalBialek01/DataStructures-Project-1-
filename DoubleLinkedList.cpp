#include <iostream>
#include <stdexcept>

using namespace std;

template<typename T>
class DoubleLinkedList {
private:
    struct Node {
        T value;
        Node *next;
        Node *prev;

        Node(T val, Node *nxt = nullptr, Node *prv = nullptr) : value(val), next(nxt), prev(prv) {}
    };

    Node *head;
    Node *tail;
    int size;

public:


    void deleteAll() {
        Node *current = head;
        while (current != nullptr) {
            Node *next = current->next;
            delete current;
            current = next;
        }
        head = tail = nullptr;
        size = 0;
    }

    DoubleLinkedList() : head(nullptr), tail(nullptr), size(0) {}

    ~DoubleLinkedList() {
        deleteAll();
    }

    void deleteFromMiddle() {
        if (size == 0) return;

        int middle = (size - 1) / 2;
        Node* current = head;

        if (size == 1) {
            deleteFirst();
            return;
        }

        for (int i = 0; i < middle; i++) { // Znajdź węzeł środkowy
            current = current->next;
        }

        Node* toDelete = current;
        if (toDelete->prev) {
            toDelete->prev->next = toDelete->next;
        }
        if (toDelete->next) {
            toDelete->next->prev = toDelete->prev;
        }

        delete toDelete;
        size--;

        if (size == 1) {
            tail = head;
        } else if (size == 0) {
            head = tail = nullptr;
        }
    }

    void addAtMiddle(const T& value) {
        if (size == 0) {
            addFirst(value);
            return;
        }

        int middle = size / 2; // Dla parzystej liczby elementów, dodajemy po lewej stronie środka.
        Node* newNode = new Node(value);
        Node* current = head;

        for (int i = 0; i < middle; i++) { // Znajdź węzeł przed środkiem
            current = current->next;
        }

        newNode->next = current;
        newNode->prev = current->prev;
        if (current->prev) {
            current->prev->next = newNode;
        }
        current->prev = newNode;

        if (current == head) {
            head = newNode;
        }

        size++;
    }


    void addFirst(const T &value) {
        Node *newNode = new Node(value, head);
        if (head != nullptr) {
            head->prev = newNode;
        }
        head = newNode;
        if (size == 0) {
            tail = head;
        }
        size++;
    }

    void addLast(const T &value) {
        Node *newNode = new Node(value, nullptr, tail);
        if (tail != nullptr) {
            tail->next = newNode;
        }
        tail = newNode;
        if (size == 0) {
            head = tail;
        }
        size++;
    }

    bool contains(const T &value) {
        Node *current = head;
        while (current != nullptr) {
            if (current->value == value) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void deleteFirst() {
        if (size == 0) return;
        Node *toDelete = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        delete toDelete;
        size--;
        if (size == 0) tail = nullptr;
    }

    void deleteLast() {
        if (size == 0) return;
        if (size == 1) {
            deleteFirst();
            return;
        }
        Node *toDelete = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete toDelete;
        size--;
    }

    T get(int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of range");
        }
        Node *current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        return current->value;
    }

    int getSize() const {
        return size;
    }

    // Metoda pomocnicza do wypisywania listy (dla celów demonstracyjnych)
    void print() {
        Node *current = head;
        while (current != nullptr) {
            cout << current->value << " <-> ";
            current = current->next;
        }
        cout << "NULL\n";
    }
};
