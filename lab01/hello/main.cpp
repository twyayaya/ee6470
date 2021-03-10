#include "HelloWorld.h"

int sc_main (int argc, char* argv[]) {
    HelloWorld hello("hello");
    // Print the hello world
    sc_core::sc_start();
    return(0);
}
