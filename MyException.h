#include <stdexcept> //stdexcept header that contains std :: exception
#include <string>

//Defining a custom exception class named MyException that inherits from std :: exception
class MyException : public std :: exception {
    public:
        //Constructor accepts a C-style string as the error message and initializes the std :: string member variable errorMessage
        MyException(const char* msg) : errorMessage(msg){}

        //Overriding the virtual what() method from std :: exception
        //noexcept means this function guarantees not to throw exceptions
        //override ensures this function overrides a base class version 
        const char* what() const noexcept override //Overriding the what function 
        {
            //Returns the C-style string representation of the error message
            //.c_str() method is required because std :: exception : what() must return const char*, and to avoid a dangling pointer
            return errorMessage.c_str();
        }
    
    private:
        std :: string errorMessage; //Storing the error message using std :: string
};