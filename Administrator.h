#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include "User.h"
#include <vector>
//Subclass Administrator from User
class Administrator : public User {
    string adminLevel;
    vector<User*> managedUsers;

public:
    Administrator(int id, string name, string email, string pass, string level);
    ~Administrator() override;

    bool login(string email, string password) override;
    void logout() override;
    string displayInfo() const override;

    void addUser(User* user);
};

#endif
