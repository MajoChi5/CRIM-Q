#ifndef REPORTABLE_H
#define REPORTABLE_H

#include <string>
using std::string;

// The superclass that inherit to Crime and also the abstract class for the system to be able to use polymorphism
class Reportable {
protected:
    string description;    // Description or type of report
    string dateReported;   // When report was submitted
    string status;         // "Pending", "Follow up", "Stand by", "Solved"

public:
    // Constructor 
    Reportable(const string& desc, const string& date)
        : description(desc), dateReported(date), status("Pending") {}

    // Pure virtual for specialized follow-up
    virtual void followUp() = 0;

    // Virtual method for status default returns status attribute
    virtual string getStatus() const { return status; }

    // Getters
    virtual string getType() const { return description; }
    virtual string getDateReported() const { return dateReported; }

    //Setters
    void setStatus(const string& newStatus) { status = newStatus; }

    virtual ~Reportable() {}  // Virtual destructor for memory 
};

#endif // REPORTABLE_H
