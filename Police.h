#ifndef POLICE_H
#define POLICE_H

#include "User.h"
#include <vector>
using std::vector;

class Crime; // the same as in User.h

// Police extends from  User
class Police : public User {
private:
    vector<Crime*> assignedCrimes; // Pointers to assigned crimes yeii pointers 

public:
    Police(const string& name, const string& email);
    void assignCrime(Crime* crime);          // Assign a report
    void followUpCrime(Crime* crime);        // Overwrite follow-up 
    void updateCrimeStatus(Crime* crime, const string& newStatus);
    const vector<Crime*>& getAssignedCrimes() const;
};

#endif // POLICE_H
