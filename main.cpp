#include <iostream>
#include <vector>
#include <random>
#include <string>
#include <limits>
#include <fstream>
#include <chrono>


#include "SinglyLinkedList.cpp"
#include "DoubleLinkedList.cpp"
#include "DynamicArray.cpp"
#include "Generator.cpp"


void testIntSLL(Generator generator, int i, SinglyLinkedList<int> intLinkedList);

void printOperationTime(string operationName, int n, const std::chrono::high_resolution_clock::time_point &start,
                        const std::chrono::high_resolution_clock::time_point &end);

void testIntDLL(Generator generator, int i, DoubleLinkedList<int> doubleLinkedList);

void testIntDA(Generator generator, int i, DynamicArray<int> dynamicArray);

void timeCountLogger(string basicString);

void testSinglyLinkedList(Generator generator);

void testDoubleLinkedList(Generator generator);

void testDynamicArray(Generator generator);

void printOperationTime(string operationName, int numberOfElements, chrono::duration<double, nano> operationTime);

using namespace std;


int main() {
    Generator generator;


    bool programEnding = false;

    while (!programEnding) {
        int wybor;
        cout << "Wybierz opcję:" << endl;
        cout << "1. Testuj Singly Linked List" << endl;
        cout << "2. Testuj Double Linked List" << endl;
        cout << "3. Testuj Dynamic Array" << endl;
        cout << "4. Zakoncz program" << endl;
        cin >> wybor;

        switch (wybor) {
            case 1:
                testSinglyLinkedList(generator);
                break;
            case 2:
                testDoubleLinkedList(generator);
                break;
            case 3:
                testDynamicArray(generator);
                break;
            case 4:
                programEnding = true;
                break;
            default:
                cout << "Niepoprawny wybor!" << endl;
                break;
        }
    }
}

void testSinglyLinkedList(Generator generator) {
    SinglyLinkedList<int> singlyLinkedList;
    cout << "Test dla pojedynczo wiazanej listy" << endl;
    testIntSLL(generator,100,singlyLinkedList);
    testIntSLL(generator,1000,singlyLinkedList);
    testIntSLL(generator,10000,singlyLinkedList);
    testIntSLL(generator,100000,singlyLinkedList);
    testIntSLL(generator,200000,singlyLinkedList);
}

void testDoubleLinkedList(Generator generator) {
    DoubleLinkedList<int> doubleLinkedList;
    cout << "Test dla podwojnie wiazanej listy" << endl;
    testIntDLL(generator, 100, doubleLinkedList);
    testIntDLL(generator, 1000, doubleLinkedList);
    testIntDLL(generator, 10000, doubleLinkedList);
    testIntDLL(generator, 100000, doubleLinkedList);
    testIntDLL(generator, 200000, doubleLinkedList);
}

void testDynamicArray(Generator generator) {
    DynamicArray<int> dynamicArray(10);
    cout << "Test dla tablicy dynamicznej" << endl;
    testIntDA(generator, 100, dynamicArray);
    testIntDA(generator,1000,dynamicArray);
    testIntDA(generator,10000,dynamicArray);
    testIntDA(generator,100000,dynamicArray);
    testIntDA(generator,200000,dynamicArray);
}


void testIntDA(Generator generator, int numberOfElements, DynamicArray<int> dynamicArray) {

    mt19937 gen{random_device{}()};
    uniform_int_distribution<int> dist(numeric_limits<int>::min(), numeric_limits<int>::max());


    string test1_1 = "dodawania elementu na poczatek listy - od 0 do numberOfElements ";
    auto start1_1 = chrono::high_resolution_clock::now();
    for (int i = 0; i < numberOfElements; i++) {
        dynamicArray.addFirst(i);
    }
    auto end1_1 = chrono::high_resolution_clock::now();
    printOperationTime(test1_1, numberOfElements, start1_1, end1_1);

    dynamicArray.deleteAll();

    string test1_2 = "dodawania elementu na poczatek listy - dodawanie elementow wygenrowanych losowo";

    auto totalDuration1_2 = chrono::duration<double, nano>(0);

    for (int i = 0; i < numberOfElements; ++i) {
        int randomNumber = dist(gen);
        auto start1 = chrono::high_resolution_clock::now();
        dynamicArray.addFirst(randomNumber);
        auto end1 = chrono::high_resolution_clock::now();
        totalDuration1_2 += end1 - start1;
    }
    printOperationTime(test1_2, numberOfElements, totalDuration1_2);


    string test2 = "uzyskiwania elementow od poczatku dla calej listy";
    auto start2 = chrono::high_resolution_clock::now();
    for (int i = 0; i < dynamicArray.getSize(); i++) {
        dynamicArray.get(i);
    }
    auto end2 = chrono::high_resolution_clock::now();
    printOperationTime(test2, numberOfElements, start2, end2);


    string test3 = "uzyskiwania elementow od konca dla calej listy";
    auto start3 = chrono::high_resolution_clock::now();
    for (int i = dynamicArray.getSize() - 1; i > 0; i--) {
        dynamicArray.get(i);
    }
    auto end3 = chrono::high_resolution_clock::now();
    printOperationTime(test3, numberOfElements, start3, end3);


    string test4 = "uzyskiwania elementow srodkowego";
    auto start4 = chrono::high_resolution_clock::now();
    dynamicArray.get((dynamicArray.getSize() - 1) / 2);
    auto end4 = chrono::high_resolution_clock::now();
    printOperationTime(test4, numberOfElements, start4, end4);

    dynamicArray.deleteAll();

    string test5_1 = "dodawania elementu na koniec struktury -  dodawanie elementow od 0 do numberOfElements";
    auto start5_1 = chrono::high_resolution_clock::now();
    for (int i = 0; i < numberOfElements; ++i) {
        dynamicArray.addLast(i);
    }
    auto end5_1 = chrono::high_resolution_clock::now();
    printOperationTime(test5_1,numberOfElements, start5_1, end5_1);
    dynamicArray.deleteAll();


    string test5_2 = "dodawania elementu na koniec struktury - dodawanie elementow wygenrowanych losowo";
    auto totalDuration5_2 = chrono::duration<double, nano>(0);

    for (int i = 0; i < numberOfElements; ++i) {
        int randomNumber = dist(gen);
        auto start5_2 = chrono::high_resolution_clock::now();
        dynamicArray.addFirst(randomNumber);
        auto end5_2 = chrono::high_resolution_clock::now();
        totalDuration5_2 += end5_2 - start5_2;
    }
    printOperationTime(test5_2, numberOfElements, totalDuration5_2);
    dynamicArray.deleteAll();


    string test6_1 = "dodawania elementu na srodku listy - dodawanie elementow od 0 do numberOfElements";
    auto start6_1 = chrono::high_resolution_clock::now();
    for (int i = 0; i < numberOfElements; i++) {
        dynamicArray.addAtMiddle(numberOfElements);
    }
    auto end6_1 = chrono::high_resolution_clock::now();
    printOperationTime(test6_1, numberOfElements, start6_1, end6_1);
    dynamicArray.deleteAll();


    string test6_2 = "dodawania elementu na srodku listy - dodawanie elementow losowych";
    auto totalDuration6_2 = chrono::duration<double, nano>(0);
    for (int i = 0; i < numberOfElements; ++i) {
        int randomNumber = dist(gen);
        auto start6_2  = chrono::high_resolution_clock::now();
        dynamicArray.addFirst(randomNumber);
        auto end6_2  = chrono::high_resolution_clock::now();
        totalDuration6_2 += end6_2  - start6_2 ;
    }
    printOperationTime(test1_2, numberOfElements,totalDuration6_2);

    string test7 = "usuwania elementu od poczatku listy";
    auto start7 = chrono::high_resolution_clock::now();
    for (int i = 0; i < numberOfElements; ++i) {
        dynamicArray.deleteFirst();
    }
    auto end7 = chrono::high_resolution_clock::now();
    printOperationTime(test7, numberOfElements, start7, end7);

    dynamicArray.deleteAll();


    string test8 = "usuwania elementu od konca listy";
    //Wypełnianie struktury danymi
    for (int i = 0; i < numberOfElements; i++) {
        dynamicArray.addFirst(i);
    }

    auto start8 = chrono::high_resolution_clock::now();
    dynamicArray.deleteLast(dynamicArray.getSize());
    auto end8 = chrono::high_resolution_clock::now();
    printOperationTime(test8, numberOfElements, start8, end8);
    dynamicArray.deleteAll();


    string test9 = "usuwania elementow srodkowych";
    //Wypełnianie struktury danymi
    for (int i = 0; i < numberOfElements; i++) {
        dynamicArray.addFirst(i);
    }
    auto start9 = chrono::high_resolution_clock::now();
    for (int i = 0; i <numberOfElements-1; ++i) {
        dynamicArray.deleteFromMiddle();
    }
    auto end9 = chrono::high_resolution_clock::now();
    printOperationTime(test9, numberOfElements, start9, end9);
    dynamicArray.deleteAll();
}

void testIntDLL(Generator generator, int numberOfElements, DoubleLinkedList<int> intDoubleLinkedList) {

    mt19937 gen{random_device{}()};
    uniform_int_distribution<int> dist(numeric_limits<int>::min(), numeric_limits<int>::max());


    string test1_1 = "dodawania elementu na poczatek listy - od 0 do numberOfElements ";
    auto start1_1 = chrono::high_resolution_clock::now();
    for (int i = 0; i < numberOfElements; i++) {
        intDoubleLinkedList.addFirst(i);
    }
    auto end1_1 = chrono::high_resolution_clock::now();
    printOperationTime(test1_1, numberOfElements, start1_1, end1_1);

    intDoubleLinkedList.deleteAll();

    string test1_2 = "dodawania elementu na poczatek listy - dodawanie elementow wygenrowanych losowo";

    auto totalDuration1_2 = chrono::duration<double, nano>(0);

    for (int i = 0; i < numberOfElements; ++i) {
        int randomNumber = dist(gen);
        auto start1 = chrono::high_resolution_clock::now();
        intDoubleLinkedList.addFirst(randomNumber);
        auto end1 = chrono::high_resolution_clock::now();
        totalDuration1_2 += end1 - start1;
    }
    printOperationTime(test1_2, numberOfElements, totalDuration1_2);


    string test2 = "uzyskiwania elementow od poczatku dla calej listy";
    auto start2 = chrono::high_resolution_clock::now();
    for (int i = 0; i < intDoubleLinkedList.getSize(); i++) {
        intDoubleLinkedList.get(i);
    }
    auto end2 = chrono::high_resolution_clock::now();
    printOperationTime(test2, numberOfElements, start2, end2);


    string test3 = "uzyskiwania elementow od konca dla calej listy";
    auto start3 = chrono::high_resolution_clock::now();
    for (int i = intDoubleLinkedList.getSize() - 1; i > 0; i--) {
        intDoubleLinkedList.get(i);
    }
    auto end3 = chrono::high_resolution_clock::now();
    printOperationTime(test3, numberOfElements, start3, end3);


    string test4 = "uzyskiwania elementow srodkowego";
    auto start4 = chrono::high_resolution_clock::now();
    intDoubleLinkedList.get((intDoubleLinkedList.getSize() - 1) / 2);
    auto end4 = chrono::high_resolution_clock::now();
    printOperationTime(test4, numberOfElements, start4, end4);

    intDoubleLinkedList.deleteAll();

    string test5_1 = "dodawania elementu na koniec struktury -  dodawanie elementow od 0 do numberOfElements";
    auto start5_1 = chrono::high_resolution_clock::now();
    for (int i = 0; i < numberOfElements; ++i) {
        intDoubleLinkedList.addLast(i);
    }
    auto end5_1 = chrono::high_resolution_clock::now();
    printOperationTime(test5_1,numberOfElements, start5_1, end5_1);
    intDoubleLinkedList.deleteAll();


    string test5_2 = "dodawania elementu na koniec struktury - dodawanie elementow wygenrowanych losowo";
    auto totalDuration5_2 = chrono::duration<double, nano>(0);

    for (int i = 0; i < numberOfElements; ++i) {
        int randomNumber = dist(gen);
        auto start5_2 = chrono::high_resolution_clock::now();
        intDoubleLinkedList.addFirst(randomNumber);
        auto end5_2 = chrono::high_resolution_clock::now();
        totalDuration5_2 += end5_2 - start5_2;
    }
    printOperationTime(test5_2, numberOfElements, totalDuration5_2);
    intDoubleLinkedList.deleteAll();


    string test6_1 = "dodawania elementu na srodku listy - dodawanie elementow od 0 do numberOfElements";
    auto start6_1 = chrono::high_resolution_clock::now();
    for (int i = 0; i < numberOfElements; i++) {
        intDoubleLinkedList.addAtMiddle(numberOfElements);
    }
    auto end6_1 = chrono::high_resolution_clock::now();
    printOperationTime(test6_1, numberOfElements, start6_1, end6_1);
    intDoubleLinkedList.deleteAll();


    string test6_2 = "dodawania elementu na srodku listy - dodawanie elementow losowych";
    auto totalDuration6_2 = chrono::duration<double, nano>(0);
    for (int i = 0; i < numberOfElements; ++i) {
        int randomNumber = dist(gen);
        auto start6_2  = chrono::high_resolution_clock::now();
        intDoubleLinkedList.addFirst(randomNumber);
        auto end6_2  = chrono::high_resolution_clock::now();
        totalDuration6_2 += end6_2  - start6_2 ;
    }
    printOperationTime(test1_2, numberOfElements,totalDuration6_2);

    string test7 = "usuwania elementu od poczatku listy";
    auto start7 = chrono::high_resolution_clock::now();
    for (int i = 0; i < numberOfElements; ++i) {
        intDoubleLinkedList.deleteFirst();
    }
    auto end7 = chrono::high_resolution_clock::now();
    printOperationTime(test7, numberOfElements, start7, end7);

    intDoubleLinkedList.deleteAll();


    string test8 = "usuwania elementu od konca listy";
    //Wypełnianie struktury danymi
    for (int i = 0; i < numberOfElements; i++) {
        intDoubleLinkedList.addFirst(i);
    }

    auto start8 = chrono::high_resolution_clock::now();
    for (int i = 0; i < intDoubleLinkedList.getSize()-1; ++i) {
        intDoubleLinkedList.deleteLast();
    }
    auto end8 = chrono::high_resolution_clock::now();
    printOperationTime(test8, numberOfElements, start8, end8);
    intDoubleLinkedList.deleteAll();


    string test9 = "usuwania elementow srodkowych";
    //Wypełnianie struktury danymi
    for (int i = 0; i < numberOfElements; i++) {
        intDoubleLinkedList.addFirst(i);
    }
    auto start9 = chrono::high_resolution_clock::now();
    for (int i = 0; i < intDoubleLinkedList.getSize(); ++i) {
        intDoubleLinkedList.deleteFromMiddle();
    }
    auto end9 = chrono::high_resolution_clock::now();
    printOperationTime(test9, numberOfElements, start9, end9);
    intDoubleLinkedList.deleteAll();
}

void testIntSLL(Generator generator, int numberOfElements, SinglyLinkedList<int> intSignleLinkedList) {


    mt19937 gen{random_device{}()};
    uniform_int_distribution<int> dist(numeric_limits<int>::min(), numeric_limits<int>::max());


    string test1_1 = "dodawania elementu na poczatek listy - od 0 do numberOfElements ";
    auto start1_1 = chrono::high_resolution_clock::now();
    for (int i = 0; i < numberOfElements; i++) {
        intSignleLinkedList.addFirst(i);
    }
    auto end1_1 = chrono::high_resolution_clock::now();
    printOperationTime(test1_1, numberOfElements, start1_1, end1_1);

    intSignleLinkedList.deleteAll();

    string test1_2 = "dodawania elementu na poczatek listy - dodawanie elementow wygenrowanych losowo";

    auto totalDuration1_2 = chrono::duration<double, nano>(0);

    for (int i = 0; i < numberOfElements; ++i) {
        int randomNumber = dist(gen);
        auto start1 = chrono::high_resolution_clock::now();
        intSignleLinkedList.addFirst(randomNumber);
        auto end1 = chrono::high_resolution_clock::now();
        totalDuration1_2 += end1 - start1;
    }
    printOperationTime(test1_2, numberOfElements, totalDuration1_2);


    string test2 = "uzyskiwania elementow od poczatku dla calej listy";
    auto start2 = chrono::high_resolution_clock::now();
    for (int i = 0; i < intSignleLinkedList.getSize(); i++) {
        intSignleLinkedList.get(i);
    }
    auto end2 = chrono::high_resolution_clock::now();
    printOperationTime(test2, numberOfElements, start2, end2);


    string test3 = "uzyskiwania elementow od konca dla calej listy";
    auto start3 = chrono::high_resolution_clock::now();
    for (int i = intSignleLinkedList.getSize() - 1; i > 0; i--) {
        intSignleLinkedList.get(i);
    }
    auto end3 = chrono::high_resolution_clock::now();
    printOperationTime(test3, numberOfElements, start3, end3);


    string test4 = "uzyskiwania elementow srodkowego";
    auto start4 = chrono::high_resolution_clock::now();
    intSignleLinkedList.get((intSignleLinkedList.getSize() - 1) / 2);
    auto end4 = chrono::high_resolution_clock::now();
    printOperationTime(test4, numberOfElements, start4, end4);

    intSignleLinkedList.deleteAll();

    string test5_1 = "dodawania elementu na koniec struktury -  dodawanie elementow od 0 do numberOfElements";
    auto start5_1 = chrono::high_resolution_clock::now();
    for (int i = 0; i < numberOfElements; ++i) {
        intSignleLinkedList.addLast(i);
    }
    auto end5_1 = chrono::high_resolution_clock::now();
    printOperationTime(test5_1,numberOfElements, start5_1, end5_1);
    intSignleLinkedList.deleteAll();


    string test5_2 = "dodawania elementu na koniec struktury - dodawanie elementow wygenrowanych losowo";
    auto totalDuration5_2 = chrono::duration<double, nano>(0);

    for (int i = 0; i < numberOfElements; ++i) {
        int randomNumber = dist(gen);
        auto start5_2 = chrono::high_resolution_clock::now();
        intSignleLinkedList.addFirst(randomNumber);
        auto end5_2 = chrono::high_resolution_clock::now();
        totalDuration5_2 += end5_2 - start5_2;
    }
    printOperationTime(test5_2, numberOfElements, totalDuration5_2);
    intSignleLinkedList.deleteAll();


    string test6_1 = "dodawania elementu na srodku listy - dodawanie elementow od 0 do numberOfElements";
    auto start6_1 = chrono::high_resolution_clock::now();
    for (int i = 0; i < numberOfElements; i++) {
        intSignleLinkedList.addAtMiddle(numberOfElements);
    }
    auto end6_1 = chrono::high_resolution_clock::now();
    printOperationTime(test6_1, numberOfElements, start6_1, end6_1);
    intSignleLinkedList.deleteAll();


    string test6_2 = "dodawania elementu na srodku listy - dodawanie elementow losowych";
    auto totalDuration6_2 = chrono::duration<double, nano>(0);
    for (int i = 0; i < numberOfElements; ++i) {
        int randomNumber = dist(gen);
        auto start6_2  = chrono::high_resolution_clock::now();
        intSignleLinkedList.addFirst(randomNumber);
        auto end6_2  = chrono::high_resolution_clock::now();
        totalDuration6_2 += end6_2  - start6_2 ;
    }
    printOperationTime(test1_2, numberOfElements,totalDuration6_2);

    string test7 = "usuwania elementu od poczatku listy";
    auto start7 = chrono::high_resolution_clock::now();
    for (int i = 0; i < numberOfElements; ++i) {
        intSignleLinkedList.deleteFirst();
    }
    auto end7 = chrono::high_resolution_clock::now();
    printOperationTime(test7, numberOfElements, start7, end7);

    intSignleLinkedList.deleteAll();


    string test8 = "usuwania elementu od konca listy";
    //Wypełnianie struktury danymi
    for (int i = 0; i < numberOfElements; i++) {
        intSignleLinkedList.addFirst(i);
    }

    auto start8 = chrono::high_resolution_clock::now();
    for (int i = 0; i < intSignleLinkedList.getSize()-1; ++i) {
        intSignleLinkedList.deleteLast();
    }
    auto end8 = chrono::high_resolution_clock::now();
    printOperationTime(test8, numberOfElements, start8, end8);
    intSignleLinkedList.deleteAll();


    string test9 = "usuwania elementow srodkowych";
    //Wypełnianie struktury danymi
    for (int i = 0; i < numberOfElements; i++) {
        intSignleLinkedList.addFirst(i);
    }
    auto start9 = chrono::high_resolution_clock::now();
    for (int i = 0; i < intSignleLinkedList.getSize(); ++i) {
        intSignleLinkedList.deleteFromMiddle();
    }
    auto end9 = chrono::high_resolution_clock::now();
    printOperationTime(test9, numberOfElements, start9, end9);
    intSignleLinkedList.deleteAll();

}


void printOperationTime(string operationName, int n, const chrono::high_resolution_clock::time_point &start,
                        const chrono::high_resolution_clock::time_point &end) {
    chrono::duration<double, nano> elapsed = end - start;
    string result = "Operacja: " + operationName + " wykonano na elemenatach " + to_string(n) + " w czasie: " +
                    to_string(elapsed.count()) + " nano ";
    cout << result << endl;
    timeCountLogger(result);
}


void
printOperationTime(string operationName, int numberOfElements, const chrono::duration<double, nano> operationTime) {
    string result =
            "Operacja: " + operationName + " wykonano na elemenatach " + to_string(numberOfElements) + " w czasie: " +
            to_string(operationTime.count()) + " nano ";
    cout << result << endl;
    timeCountLogger(result);
}

void timeCountLogger(string text) {
    string filePath = "measurement.csv";
    ifstream fileTest(filePath);
    bool exists = fileTest.good();
    fileTest.close();

    ofstream file(filePath, ios::app);
    if (file.is_open()) {
        file << text << endl;
        file.close();
    } else {
        cerr << "Nie udało się otworzyć pliku 'measurement.csv' do zapisu." << std::endl;
    }
}
