#include <iostream>
#include <cmath>
#include <vector>
#include <ctime>
#include <thread>
#include <chrono>
using namespace std;

vector<int> randVector(int N){
    srand(time(NULL));
    vector<int> arr;
    for (int i = 0; i < N; i++){
        arr.push_back(rand()%100);
    }
    srand(time(NULL));
    return arr;
}

template <typename T>
void printVec(vector<T> a){
    for (int i = 0; i < a.size(); i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

template <typename Y> // int или double, другое не надо пж
vector<Y> choiceSort(vector<Y> a){
    for (int i = 0; i < a.size()-1; i++) {
        int f = i;
        for (int j = i + 1; j < a.size(); j++) {
            if (a[j] < a[f]) {
                f = j;
            }
        }
        int t = a[i];
        a[i] = a[f];
        a[f] = t;
    }
    return a;
}

int main() {
    int n;
    cout << "Введите длину масиива: ";
    cin >> n;
    vector<int> arr = randVector(n);
    printVec(arr);
    vector<int> newarr = choiceSort(arr);
    printVec(newarr);
    return 0;
}
