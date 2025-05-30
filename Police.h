#ifndef POLICE_H
#define POLICE_H

#include "User.h"
#include "CrimeReport.h"
#include <vector>
//Subclass Police from User
class Police : public User {
    string badgeNumber, department, rank;
    vector<CrimeReport*> assignedReports;

public:
    //Constructor
    Police(int id, string name, string email, string pass, string badge, string dept, string rank);
    //Destructor
    ~Police() override;
//Methods for login, logout and display info in the subclass with overriding
    bool login(string email, string password) override;
    void logout() override;
    string displayInfo() const override;

    string assignReport(CrimeReport* report);
    string assignReport(vector<CrimeReport*> reports);
};

#endif
