/*
2.Composition
*/
#include <iostream>

#include "Monster.h"
#include "Position2D.h"

using namespace std;

int main() {
    Monster mon1("Goblin", Position2D(100, 10));

    // while(1){
    {
        mon1.moveTo(Position2D(1, 1));

        cout << mon1 << endl;
    }
}