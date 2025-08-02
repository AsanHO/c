/*
3.move_constructors_assignment.cpp
*/
#include "../10.relations/5.dependency_study/Timer.h"
#include "AutoPtrV2.h"
#include "ResourceV2.h"

using namespace std;
AutoPtrV2<ResourceV2> generatedResouce() {
    AutoPtrV2<ResourceV2> res = new ResourceV2(100000000);
    return res;
}

int main() {
    using namespace std;
    streambuf* oring_buf = cout.rdbuf();
    // cout.rdbuf(Null); //disconnect cout from buffer

    Timer timer;

    {
        AutoPtrV2<ResourceV2> main_res;
        main_res = generatedResouce();
        /*
        deep copy
        0.523579
        shallow copy
        0.000038882
        */
    }
    cout.rdbuf(oring_buf);
    timer.elapsed();
}