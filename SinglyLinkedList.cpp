#include <iostream>
#include "DataStructure.cpp"
using namespace std;

using namespace std;

template<typename T>
class SinglyLinkedList {
private:
    struct Node {
        T value;
        Node *next;

        Node(T val, Node *nxt = nullptr) : value(val), next(nxt) {}
    };

    Node *head;
    Node *tail;
    int size;



public:
    SinglyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

    ~SinglyLinkedList() {
        deleteAll();
    }

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

    void deleteFromMiddle() {
        if (size == 0) return;

        int middle = (size - 1) / 2;
        Node* current = head;

        if (size == 1) {
            deleteFirst();
            return;
        }

        for (int i = 0; i < middle - 1; i++) { // Znajdź węzeł przed środkiem
            current = current->next;
        }

        Node* toDelete = current->next;
        current->next = toDelete->next;
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

        for (int i = 0; i < middle - 1; i++) { // Znajdź węzeł przed środkiem
            current = current->next;
        }

        newNode->next = current->next;
        current->next = newNode;

        size++;
    }


    void addFirst(const T &value) {
        Node *newNode = new Node(value, head);
        head = newNode;
        if (size == 0) {
            tail = head;
        }
        size++;
    }

    void addLast(const T &value) {
        Node *newNode = new Node(value);
        if (size == 0) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
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
        Node *current = head;
        while (current->next != tail) {
            current = current->next;
        }
        delete tail;
        tail = current;
        tail->next = nullptr;
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
            cout << current->value << " -> ";
            current = current->next;
        }
        cout << "NULL\n";
    }
};
