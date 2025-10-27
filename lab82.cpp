/*
CIS 280X
Assignment 82
Villarruel, Erick
*/

#include <iostream>
#include "AuthenticationError.h" //Including the custom created AuthenticationError header file

int main()
{
    //Declaring variables for username and password, as well as the set amount of login attempts they have of 2
    std :: string username;
    std :: string password;
    int attempts{2};

    //Looping as long as the user has remaining login attempts
    while(attempts > 0)
    {
        //Entering the try block
        try {
            //Taking and storing the users entry for username and password
            std :: cout << "Enter username: ";
            std :: cin >> username;
            std :: cout << "Enter password: ";
            std :: cin >> password;

            //Calling the validation function to check if credential are correct
            //If they are correct, no exception was thrown, outputs Login Successful, and breaks out of the loop
            validateCredentials(username, password);
            std :: cout << "Login Successful!" << std :: endl;
            break;
        }
        //Catch Block for the AuthenticationError error
        catch(const AuthenticationError& e) 
        {
            attempts--; //If an error is caught, reduce the number of remaining attempts
            std :: cout << "Error: " << e.what() << std :: endl; //Displays the error message from the exception

            //If no attempts remain, break out of the loop
            if(attempts == 0)
            {
                break;
            }

            //If attempts remain, display the amount of attempts remaining
            if(attempts < 2)
            {
                std :: cout << "You have: " << attempts << " attempt(s) remaining." << std :: endl;
            }
        }
    }

    //Once no attempts remain after attempting to login after 2 attempts, display the message to contact the system administrator to reset their password
    if(attempts == 0)
    {
        std :: cout << "Too many attempts. Please contact the system administrator to reset your password." << std :: endl;
    }

    return 0;
}