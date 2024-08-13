#include <iostream>
#include <fstream>
#include "Executive.h"

int main(int argc, char** argv)
{
    if(argc < 2) {
        std::cout << "\nERROR: Filename needs to be passed";
    }
    else{
        Executive exec(argv[1]);
        exec.run();
    }

}
