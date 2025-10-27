/*
CIS 280X
Assignment 81
Villarruel, Erick
*/

#include <iostream>
#include "MyException.h" //Including the custom created MyException class header file

int main()
{
    //Begin a try block to test whether it throws an exception
    try {
        throw MyException("Error! Invalid Input."); //Throws an object of type MyException with a custom error message of invalid input
    }
    //Catch block that handles exception of type MyException
    catch(const MyException& e) 
    {
        std :: cout << "Caught MyException: " << e.what() << std :: endl; //Output the error message from the caught MyException using the overriden what() method
    }
    //Catch block that handles any other std :: exception types that type MyException would not catch
    catch (const std :: exception& f)
    {
        std :: cout << "Caught std :: exception: " << f.what() << std :: endl; //Output an error message for any other error caught
    }
}
