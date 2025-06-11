#ifndef CRIME_H
#define CRIME_H

#include "Reportable.h"
#include <string>
using std::string;

// Inheritance: Crime extends Reportable
class Crime : public Reportable {
protected:
    string location;       // Specific to Crime: where it occurred
    string dateFollowUp;   // When follow-up action was taken

public:
    // Constructor uses base for common attributes
    Crime(const string& desc, const string& loc, const string& date);

    // Overriding abstract method from Reportable
    void followUp() override;

    // Override base getStatus()
    virtual string getStatus() const override;

    // Overload: optionally return follow-up date
    string getStatus(bool showDate) const;

    // Operator Overloading: compare Crime descriptions
    bool operator==(const Crime& other) const;

    virtual ~Crime();
};

#endif // CRIME_H
