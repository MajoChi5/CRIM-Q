#ifndef CITIZEN_H
#define CITIZEN_H

#include "User.h"
#include "CrimeReport.h"
#include <vector>
//Subclass Citizen for User
class Citizen : public User {
    string address, phone;
    vector<CrimeReport*> myReports;

public:
    //Constructor
    Citizen(int id, string name, string email, string pass, string addr, string phone);
    //Destructor
    ~Citizen() override;
    //Methods for login, logout and display info in the subclass with overriding
    bool login(string email, string password) override;
    void logout() override;
    string displayInfo() const override;
    //Methods for reporting crimes with different parameters so its overloading and polymorphism :)
    CrimeReport* reportCrime(string t, string d, string l, bool pub);
    CrimeReport* reportCrime(string t, string l);
};

#endif
