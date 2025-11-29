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
        arr.push_back(rand()%1000);
    }
    srand(time(NULL));
    return arr;
}

template <typename T>
void printVec(vector<T> a){
    for (int i = 0; i < 10; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

template <typename A> // int или double, другое не надо пж
vector<A> bubbleSort(vector<A> a){
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

template <typename B> // int или double, другое не надо пж
vector<B> coctailSort(vector<B> a){
    int b = 0;
    int r = a.size()-1, l = 0;
    while ((r - l != 0 && a.size()%2 == 1) || (r - l != -1 && a.size()%2 == 0)){
        for (int i = 0; i < r; i++){
            if (a[i] > a[i+1]){
                b = a[i+1];
                a[i+1] = a[i];
                a[i] = b;
            }
        }
        r--;
        for (int i = r-1; i > l; i--){
            if (a[i] < a[i-1]){
                b = a[i-1];
                a[i-1] = a[i];
                a[i] = b;
            }
        }
        l++;
    }
    return a;
}

template <typename C> // int или double, другое не надо пж
vector<C> insertionSort(vector<C> a){
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

template <typename D> // int или double, другое не надо пж
vector<D> choiceSort(vector<D> a){
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

template <typename E> // int или double, другое не надо пж
vector<E> shellSort(vector<E> a){
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

template <typename F> // int или double, другое не надо пж
vector<F> gnomeSort(vector<F> a){
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
    cout << "Вектор: ";
    printVec(arr);


    auto start = chrono::high_resolution_clock::now();
    vector<int> newarr1 = bubbleSort(arr);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> t1 = end - start;
    cout << "Bubble Sort (" << t1.count() << " ms): ";
    printVec(newarr1);


    start = chrono::high_resolution_clock::now();
    vector<int> newarr2 = coctailSort(arr);
    end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> t2 = end - start;
    cout << "Coctail Sort (" << t2.count() << " ms): ";
    printVec(newarr2);


    start = chrono::high_resolution_clock::now();
    vector<int> newarr3 = insertionSort(arr);
    end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> t3 = end - start;
    cout << "Insertion Sort (" << t3.count() << " ms): ";
    printVec(newarr3);


    start = chrono::high_resolution_clock::now();
    vector<int> newarr4 = choiceSort(arr);
    end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> t4 = end - start;
    cout << "Choice Sort (" << t4.count() << " ms): ";
    printVec(newarr4);


    start = chrono::high_resolution_clock::now();
    vector<int> newarr5 = shellSort(arr);
    end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> t5 = end - start;
    cout << "Shell Sort (" << t5.count() << " ms): ";
    printVec(newarr5);


    start = chrono::high_resolution_clock::now();
    vector<int> newarr6 = gnomeSort(arr);
    end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> t6 = end - start;
    cout << "Gnome Sort (" << t6.count() << " ms): ";
    printVec(newarr6);
    return 0;
}
