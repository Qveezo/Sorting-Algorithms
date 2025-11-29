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
vector<Y> shellSort(vector<Y> a){
    for (int i = a.size()/2; i > 0; i /= 2) {
        for (int g = i; g < a.size(); g++) {
            int t = a[g];
            int j;
            for (j = g; (j >= i) && (a[j - i] > t); j -= i) {
                a[j] = a[j - i];
            }
            a[j] = t;
        }
    }
    return a;
}

int main() {
    int n;
    cout << "Введите длину масиива: ";
    cin >> n;
    vector<int> arr = randVector(n);
    printVec(arr);
    vector<int> newarr = shellSort(arr);
    printVec(newarr);
    return 0;
}