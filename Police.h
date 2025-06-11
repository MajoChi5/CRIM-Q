#ifndef POLICE_H
#define POLICE_H

#include "User.h"
#include <vector>
using std::vector;

class Crime; // forward declaration

// Police extends User: can be assigned and follow-up crimes
class Police : public User {
private:
    vector<Crime*> assignedCrimes; // Pointers to assigned crimes

public:
    Police(const string& name, const string& email);
    void assignCrime(Crime* crime);          // Assign a report
    void followUpCrime(Crime* crime);        // Overwrite follow-up behavior
    void updateCrimeStatus(Crime* crime, const string& newStatus);
    const vector<Crime*>& getAssignedCrimes() const;
};

#endif // POLICE_H
