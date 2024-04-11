#include <iostream>
#include <vector>
#include <random>
#include <string>
#include <limits>
#include <fstream>


using namespace std;


class Generator {
private:
    mt19937 gen;


    // Zmodyfikowana funkcja csvLogger zapisująca dane w nowych wierszach
    template <typename T>
    void csvLogger(const vector<T>& data, const string& filename) {
        ofstream file("data/" + filename); // Utwórz plik w katalogu "data"
        if (file.is_open()) {
            for (const auto& val : data) {
                file << val << "\n"; // Zapisz każdy element wektora do nowego wiersza w pliku
            }
            file.close();
        } else {
            cerr << "Nie można otworzyć pliku: " << filename << endl;
        }
    }


public:
    Generator() : gen(random_device()()) {}

//    vector<int> generateIntData(int n) {
//        uniform_int_distribution<int> dist(numeric_limits<int>::min(), numeric_limits<int>::max());
//        vector<int> data(n);
//        for (int& val : data) {
//            val = dist(gen);
//        }
//        csvLogger(data, "intData.csv"); // Wywołaj funkcję csvLogger
//        return data;
//    }
//    vector<int> generateIntData(int n) {
//        uniform_int_distribution<int> dist(numeric_limits<int>::min(), numeric_limits<int>::max());
//        vector<int> data(n);
//        for (int& val : data) {
//            val = dist(gen);
//        }
//        csvLogger(data, "intData.csv"); // Wywołaj funkcję csvLogger
//        csvReader("intData.csv");
//    }

//
//    vector<float> generateFloatData(int n) {
//        uniform_real_distribution<float> dist(numeric_limits<float>::lowest(), numeric_limits<float>::max());
//        vector<float> data(n);
//        for (float& val : data) {
//            val = dist(gen);
//        }
//        csvLogger(data, "floatData.csv"); // Wywołaj funkcję csvLogger
//        return data;
//    }
//
//    vector<double> generateDoubleData(int n) {
//        uniform_real_distribution<double> dist(numeric_limits<double>::lowest(), numeric_limits<double>::max());
//        vector<double> data(n);
//        for (double& val : data) {
//            val = dist(gen);
//        }
//        csvLogger(data, "doubleData.csv"); // Wywołaj funkcję csvLogger
//        return data;
//    }
//
//    vector<char> generateCharData(int n) {
//        uniform_int_distribution<> dist(32, 126); // Drukowalne znaki ASCII
//        vector<char> data(n);
//        for (char& val : data) {
//            val = static_cast<char>(dist(gen));
//        }
//        csvLogger(data, "charData.csv"); // Wywołaj funkcję csvLogger
//        return data;
//    }
//
//    vector<string> generateStringData(int n) {
//        uniform_int_distribution<> dist(97, 122); // Małe litery a-z
//        vector<string> data(n);
//        for (string& val : data) {
//            val.resize(6);
//            for (char& ch : val) {
//                ch = static_cast<char>(dist(gen));
//            }
//        }
//        csvLogger(data, "stringData.csv"); // Wywołaj funkcję csvLogger
//        return data;
//    }
};
