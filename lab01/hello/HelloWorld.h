#ifndef _HELLOWORLD_H_
#define _HELLOWORLD_H_

#include <systemc>

SC_MODULE(HelloWorld) {

  SC_CTOR (HelloWorld) {
    std::cout << "HelloWorld is constructed" << std::endl;
    // Create a method process in constructor
    SC_METHOD( say_hello ); // A new line. Do NOT delete the original declaration (void say_hello();).
    void say_hello();
    }

  void say_hello();
};

#endif