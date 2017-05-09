// Project MPI [duck managed]
// Class Pion (src/classes/Pion/Pion.test.cpp)
#ifndef PION_CLASS_CPP
    #define PION_TEST_CPP

    //Pion class unit test

    #include <iostream>
    #include "Pion.class.hpp"
    #include "../../config/UnitTests.hpp"

    int main(int argc, char const *argv[])
    {
        unsigned int err = 0;
        Pion a;

        /*
        unit tests here
        use macro SHOULD_BE_TRUE(expression) and SHOULD_BE_FALSE(expression)
        to increment err when errors
        */
        
        if(err) {
            cout << 'Test failed with ' << err << ' errors.' << endl;
            return -1;
        }

        cout << 'Test executed successfully' << endl;
        return 0;
    }

    #endif
