#ifndef CRIME_H
#define CRIME_H

#include "Reportable.h"
#include <string>
using std::string;

// Crime is a subclass that extends Reportable
class Crime : public Reportable {
protected:
    string location;       // Where occurred the crime
    string dateFollowUp;   // When follow-up action start or not 
public:
    // Constructor 
    Crime(const string& desc, const string& loc, const string& date);

    // Overriding the virtual method from Reportable
    void followUp() override;

    // Override base getStatus()
    virtual string getStatus() const override;

    // Overload to return follow-up date
    string getStatus(bool showDate) const;

    // Operator Overloading this is used to compare Crime descriptions (idea stole from a partner)
    bool operator==(const Crime& other) const;

    virtual ~Crime();
};

#endif // CRIME_H
