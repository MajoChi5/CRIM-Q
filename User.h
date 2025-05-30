#ifndef USER_H
#define USER_H

#include <string>
using namespace std;
//Superclass User
class User {
protected:
    int id;
    string name;
    string email;
    string password;
    bool isLoggedIn;

public:
//Constructor
    User(int id, string name, string email, string password)
        : id(id), name(name), email(email), password(password), isLoggedIn(false) {}
//Methods for login, logout and display info there are pure virtual methods 
    virtual ~User() {}

    virtual bool login(string email, string password) = 0;
    virtual void logout() = 0;
    virtual string displayInfo() const = 0;
//Method to validate credentials
    bool validateCredentials(string email, string password) const {
        return this->email == email && this->password == password;
    }
//Getters
    int getUserID() const { return id; }
    string getUserName() const { return name; }
    string getUserEmail() const { return email; }
    bool getLoginStatus() const { return isLoggedIn; }
//Setters are not needed as the user info is set in the constructor and cannot be changed :) 
};

#endif
