#include <iostream>
using namespace std;
// #include "9_temp_cls_func_files.h" 
// ERROR:
// ld: symbol(s) not found for architecture arm64
// clang: error: linker command failed with exit code 1 (use -v to see invocation)

// #include "9_temp_cls_func_files.cpp" // a fast way to address the linking ERROR, seldomly used

#include "9_temp_cls_func_files.hpp" // write the declaration and implementation in the same file, with .hpp extension

int main()
{
    Person<string,int> p("John",20);
    p.print_person();
    return 0;
}