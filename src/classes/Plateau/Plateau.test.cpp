// Project MPI [duck managed]
// Class Plateau (src/classes/Plateau/Plateau.test.cpp)
#ifndef PLATEAU_CLASS_CPP
    #define PLATEAU_TEST_CPP

    //Plateau class unit test

    #include <iostream>
    #include "Plateau.class.h"
    #include "../../config/UnitTests.h"

    int main(int argc, char const *argv[])
    {
        unsigned int err = 0;
        Plateau a;

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
