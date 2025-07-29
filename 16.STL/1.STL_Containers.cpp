/*
1.STL_Containers.cpp
크게
- 1.Containers
- 2.Iterators
- 3.Algorithms
- 4.Functions 로 나뉜다.

컨테이너는 크게
- 1.sequence_container
- 2.associative_container
- 3.container_adapters 로 나뉜다.
*/
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;
void sequence_container() {
    {
        vector<int> vec;
        for (int i = 0; i < 10; ++i) vec.push_back(i);
        for (auto& e : vec) cout << e << " ";
        cout << endl;
    }

    {
        deque<int> deq;
        for (int i = 0; i < 10; i++) {
            deq.push_back(i);
            deq.push_front(i);
        }

        for (auto& e : deq) cout << e << " ";
        cout << endl;
    }
}
int associative_container() {
    {
        set<string> str_set;
        str_set.insert("Hello");
        str_set.insert("World");
        str_set.insert("Hello");

        cout << str_set.size() << endl;

        for (auto& e : str_set) cout << e << " ";
        cout << endl;
    }
    {
        std::multiset<string> str_set;
        str_set.insert("Hello");
        str_set.insert("World");
        str_set.insert("Hello");

        cout << str_set.size() << endl;

        for (auto& e : str_set) cout << e << " ";
        cout << endl;
    }
    {
        map<char, int> map;
        map['a'] = 10;
        map['b'] = 20;
        map['c'] = 50;

        cout << map['a'] << endl;

        map['a'] = 100;

        cout << map['a'] << endl;

        for (auto& e : map) cout << e.first << " " << e.second << " ";
        // 키가 정렬된 순서로 출력된다.
        cout << endl;
    }
    {
        std::multimap<char, int> map;
        map.insert(std::pair('a', 10));
        map.insert(std::pair('b', 10));
        map.insert(std::pair('c', 10));
        map.insert(std::pair('a', 100));

        cout << map.count('a') << endl;

        for (auto& e : map) cout << e.first << " " << e.second << " ";
        cout << endl;
    }
}
void constainer_adapters() {
    {
        stack<int> stack;
    }
    {
        queue<int> queue;
    }
    {
        priority_queue<int> queue;

        for (const int n : {1, 45, 3, 4, 6, 2, 7, 8, 5, 9}) {
            queue.push(n);
        }
        for (int i = 0; i < 10; ++i) {
            cout << queue.top() << endl;
            queue.pop();
        }
    }
}
int main() {
    sequence_container();
    associative_container();
    constainer_adapters();
    return 0;
}