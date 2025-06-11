#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
using std::string;
using std::vector;

class Crime; // forward declaration

// Base for Citizen and Police (holds user identity and reports)
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
    virtual ~User();   // Clean up reported crimes
};

#endif // USER_H
