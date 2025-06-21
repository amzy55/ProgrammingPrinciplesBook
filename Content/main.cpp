#include <iostream>
#include "extra/extra.h"
#include "chapter2/exercises2.h"
#include "chapter3/exercises3.h"
#include "chapter4/exercises4.h"
#include "chapter5/exercises5.h"
#include "chapter6/exercises6.h"

int main()
try {
    exercises6::calculator02buggy::call_calculator();
    keep_window_open("~0");
}
catch (exception& e) {
    cerr << e.what() << endl;
    keep_window_open("~1");
    return 1;
}
catch (...) {
    cerr << "exception \n";
    keep_window_open("~2");
    return 2;
}