#include <stdexcept> //stdexcept header that contains std :: runtime_error

//Defining a custom exception class named AuthenticationError that inherits from std :: runtime_error
class AuthenticationError : public std :: runtime_error {
    public:
        //Constructor that takes a string message and initialize std :: runtime_error with msg
        AuthenticationError(const std :: string& msg) 
            : std :: runtime_error(msg) {}

};

//Function that validates the username and password, passing in constant string references of username and password
void validateCredentials(const std :: string& username, const std :: string& password)
{
    //Defining the valid and correct user credentials
    const std :: string validUsername{"user"};
    const std :: string validPassword{"password"};

    //Checking to see if the credentials provided by the user input, is correct
    if(username != validUsername || password != validPassword)
    {
        throw AuthenticationError("Invalid Username or Password."); //If invalid, throws a object type AuthenticationError error message of invalid username or password
    }


}