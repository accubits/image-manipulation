// /* example.c */
// #include <stdio.h>

// #ifdef start
//     extern "C" start();
//     {
// 	}
// #endif
//         void function_in_C(); /* insert correct prototype */
//         /* add other C function prototypes here if needed */


// int main(int argc, char *argv[]) {
// function_in_C();
// }

#include <iostream>

using namespace std;

extern "C" int _start();

int main(int argc, char *argv[]) {
std::cout<<""<<_start();
}
