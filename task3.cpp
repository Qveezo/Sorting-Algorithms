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
vector<Y> insertionSort(vector<Y> a){
    for (int i = 1; i < a.size(); i++) {
        int k = a[i];  
        int j = i - 1;
        while (j >= 0 && a[j] > k) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = k;
    }
    return a;
}

int main() {
    int n;
    cout << "Введите длину масиива: ";
    cin >> n;
    vector<int> arr = randVector(n);
    printVec(arr);
    vector<int> newarr = insertionSort(arr);
    printVec(newarr);
    return 0;
}
