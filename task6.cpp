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
vector<Y> gnomeSort(vector<Y> a){
    int f = 0;
    while (f < a.size()) {
        if (f == 0 || a[f] >= a[f - 1]) {
            f++; 
        }
        else {
            int t = a[f];
            a[f] = a[f - 1];
            a[f - 1] = t;
            f--; 
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
    vector<int> newarr = gnomeSort(arr);
    printVec(newarr);
    return 0;
}