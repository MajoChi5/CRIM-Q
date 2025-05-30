#include "Administrator.h"
// Constructor same as the User class but with an additional parameter for the admin level this is the same for the other classes that inherit from the User class
Administrator::Administrator(int id, string name, string email, string pass, string level)
    : User(id, name, email, pass), adminLevel(level) {}

Administrator::~Administrator() {}

bool Administrator::login(string email, string password) {
    if (validateCredentials(email, password)) {
        isLoggedIn = true;
        return true;
    }
    return false;
}

void Administrator::logout() {
    isLoggedIn = false;
}

string Administrator::displayInfo() const {
    return "Admin: " + name + " | Level: " + adminLevel;
}

void Administrator::addUser(User* user) {
    managedUsers.push_back(user);
}
