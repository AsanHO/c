/*
2.Composition
*/
#include <iostream>

#include "Monster.h"

using namespace std;

int main() {
    Monster mon1("Goblin", 10, 20);

    // while(1){
    {
        mon1.moveTo(1, 1);

        cout << mon1 << endl;
    }
}