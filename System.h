#ifndef SYSTEM_H
#define SYSTEM_H

#include <vector>
using std::vector;

class User;
class Crime;
class Police;

// Orchestrates users and crime records
class System {
private:
    vector<User*> users;
    vector<Crime*> crimes;

public:
    void addUser(User* user);
    void addCrime(Crime* crime);
    void assignToPolice(Police* officer, Crime* crime);
    const vector<User*>& getUsers() const;
    const vector<Crime*>& getCrimes() const;
    ~System();
};

#endif // SYSTEM_H
