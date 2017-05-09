// Project MPI [duck managed]
// Class Bouton (src/classes/Bouton/Bouton.test.cpp)
#ifndef BOUTON_CLASS_CPP
    #define BOUTON_TEST_CPP

    //Bouton class unit test

    #include <iostream>
    #include "Bouton.class.hpp"
    #include "../../config/UnitTests.hpp"

    int main(int argc, char const *argv[])
    {
        unsigned int err = 0;
        Bouton a;

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
