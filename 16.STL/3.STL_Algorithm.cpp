/*
3.STL_Algorithms.cpp
*/
#include <algorithm>
#include <iostream>
#include <list>
#include <vector>

using namespace std;

int main() {
    // vector<int> container;
    list<int> container;

    for (int i = 0; i < 10; ++i) {
        container.push_back(i);
    }

    auto itr = min_element(container.begin(), container.end());
    cout << *itr << endl;
    itr = max_element(container.begin(), container.end());
    cout << *itr << endl;
    cout << endl;

    itr = find(container.begin(), container.end(), 3);
    // 물론 자료구조에 비교 연산이 구현되어 있어야한다.
    container.insert(itr, 128);
    for (auto &e : container) {
        cout << e << " ";
    }
    cout << endl;

    // sort(container.begin(), container.end());
    container.sort();
    for (auto &e : container) {
        cout << e << " ";
    }
    cout << endl;

    // reverse(container.begin(), container.end());
    container.reverse();
    for (auto &e : container) {
        cout << e << " ";
    }
    cout << endl;
}
// 자료구조에서 리스트와 벡터의 차이에 대해 한번 더 알아보자!!