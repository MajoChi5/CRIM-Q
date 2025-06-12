# CRIM-Q
CRIM-Q is supposed to be an organization and reporting system for the Querétaro state police, so the can see any tipe of crimes that the society reports, also it helps to the transparency system because the people can see if they report is already being followed up, in addition to being able to see the other complaints and the date the police began following them up, in addition to improving the organization, this will allow citizens to contribute to public safety in the state of Querétaro and later an application can be developed for faster access.
This proyect is going to work with Polimorphism, inheritance, operator overloading, overwriting, overloading and pointers because its also working with abstract classes. 

To interact with the code here are a few things you need to know first the program display a menu that is like this:
   1. Report a crime
   2. Assign a crime to an officer
   3. Follow up on a crime
   4. Show all crime statuses
   5. Exit
Then you press any opcion you would like to go with 
Report a crime: prompts for description, location, date → creates a `Crime` and stores it.
Assign crime: lists existing crimes by index, asks which one and which officer → calls `assignToPolice()`. (If you want to put more officers then you have to modify the objets created
Follow up: asks which officer, lists their assigned crimes, picks one → calls `followUpCrime()`.
Show statuses: iterates through each officer’s assigned crimes and prints “Crime, Status, Officer.”

 Take in to accunt that if you exist code the information will delate
