### C++ memory segments:

- Stack, allocated automatically by c++
- Heap, allocated by human 
- Code, all the binary codes
- Data, all the global variables

#### Code segment

Allocated right after compliment,

Two properties:
- Shared, can be run multipy times
- Read only 

#### Data segment

Allocated right after compliment,

Include:
- global variables

- static variables, all the variables decorated by the `static`

  >When a variable is declared as static, space for **it gets allocated for the lifetime of the program**. Even if the function is called multiple times, space for the static variable is allocated only once and the value of variable in the previous call gets carried through the next function call. 

- const segment
  - string const
  - global variables decorated by `const`

released automatically by the OS system after running the programme

lifetime not controlled by human

#### Stake segment

Allocated automatically when running the programme

Include:

- local variables
- formatted parameters of functions

Don't return the address of a local variable

```c++
#include<iostream>
using namespace std;

int * pointer(){
    int a = 10;
    return &a;
}

int main(){
    int *p = pointer();
    cout << *p << endl;
    cout << *p << endl;
    return 0;
}
```

Compile with g++, a warning pops out:

```shell
➜  2_core g++ 1_cpp_core.cpp
1_cpp_core.cpp:6:13: warning: address of stack memory associated with local variable 'a' returned [-Wreturn-stack-address]
    return &a;
            ^
1 warning generated.
➜  2_core ./a.out 
10
1
```

#### Heap segment

Allocated manually by `new`, and deleted by `delete`

```c++
#include<iostream>
using namespace std;

int * pointer(){
    int *p = new int(10);
    return p;
}

int main(){
    int *p = pointer();
    cout << *p << endl;
    return 0;
}
```



