#ifndef CRIMEREPORT_H
#define CRIMEREPORT_H

#include <string>
using namespace std;
//class CrimeReport
class CrimeReport {
private:
    int reportID;
    string title, description, location;
    bool isPublic;

public:
//Constructor
    CrimeReport(int id, string t, string d, string l, bool pub);

CrimeReport() : isPublic(false) {} // Constructor initializes isPublic
void setPublic(bool status) {
    isPublic = status;
}
bool getPublic() const {
    return isPublic;
}
//Getters
    string getDetails() const;
    int getID() const;
};

#endif
