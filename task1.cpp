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
vector<Y> bubbleSort(vector<Y> a){
    int count=1, b = 0;
    while (count != 0){
        count = 0;
        for (int i = 0; i < a.size()-1; i++){
            if (a[i] > a[i+1]){
                b = a[i+1];
                a[i+1] = a[i];
                a[i] = b;
                count++;
            }
        }
    }
    return a;
}

int main(){
    int n;
    cout << "Введите длину масиива: ";
    cin >> n;
    vector<int> myVec = randVector(n);
    printVec(myVec);
    vector<int> newVec = bubbleSort(myVec);
    printVec(newVec);
    return 0;
}