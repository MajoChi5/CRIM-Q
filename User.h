#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
using std::string;
using std::vector;

class Crime; //The Crime declaration is made in User.h to declare vector<Crime*> reports; without needing to include the Crime.h file


class User {
protected:
    string name;
    string email;
    vector<Crime*> reports; // Reports submitted by user

public:
    User(const string& name, const string& email);
    void reportCrime(Crime* crime);    // Submit a crime report
    const vector<Crime*>& getReports() const;
    string getName() const;
    virtual ~User();   // Clean up reported crimes so it is a destructor 
};

#endif // USER_H
