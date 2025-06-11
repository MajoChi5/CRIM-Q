#include <iostream>
#include <vector>
#include "System.h"
#include "User.h"
#include "Police.h"
#include "Crime.h"

using namespace std;

int main() {
    System crimq;

    // Create users using dynamic allocation (pointers)
    User* citizen = new User("Juan Perez", "juan@email.com");
    Police* officer1 = new Police("Jose Perez", "jperez@police.qro");
    Police* officer2 = new Police("Maria Lopez", "mlopez@police.qro");
    Police* officer3 = new Police("Carlos Ruiz", "cruiz@police.qro");

    // Register users in the system
    crimq.addUser(citizen);
    crimq.addUser(officer1);
    crimq.addUser(officer2);
    crimq.addUser(officer3);

    // Create Crime instances
    Crime* c1 = new Crime("Assault", "Centro", "2025-12-05");
    Crime* c2 = new Crime("Vandalism", "Parque Sur", "2025-12-06");
    Crime* c3 = new Crime("Cyberbullying", "Querétaro", "2025-12-07");

    // Citizen reports crimes
    citizen->reportCrime(c1);
    citizen->reportCrime(c2);
    citizen->reportCrime(c3);

    // System records crimes
    crimq.addCrime(c1);
    crimq.addCrime(c2);
    crimq.addCrime(c3);

    // Assign and follow-up (polymorphism via virtual)
    crimq.assignToPolice(officer1, c1);
    crimq.assignToPolice(officer2, c2);
    crimq.assignToPolice(officer3, c3);

    officer1->followUpCrime(c1);
    officer2->followUpCrime(c2);
    officer3->followUpCrime(c3);

    // Update statuses (overloading via setStatus)
    officer1->updateCrimeStatus(c1, "Solved");
    officer2->updateCrimeStatus(c2, "Stand by");
    // officer3 remains "Follow up"

    // Print formatted output (only in main)
    vector<Police*> officers = { officer1, officer2, officer3 };
    for (Police* off : officers) {
        for (Crime* crime : off->getAssignedCrimes()) {
            cout << "Crime: " << crime->getType() << endl;
            cout << "Upload: " << crime->getDateReported() << endl;
            cout << "Officer: " << off->getName() << endl;
            cout << "Status: " << crime->getStatus() << endl;
            cout << "-----------------------------" << endl;
        }
    }

    return 0;
}