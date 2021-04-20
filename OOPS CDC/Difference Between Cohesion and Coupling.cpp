What is the difference between cohesion and coupling?

How can coupling and cohesion lead to either good or poor software design?

What are some examples that outline the difference between the two, and their impact on overall code quality?
  
  
  
  
  Cohesion refers to what the class (or module) can do. Low cohesion would mean that the class does a great variety of actions - it is broad, unfocused on what it should do. High cohesion means that the class is focused on what it should be doing, i.e. only methods relating to the intention of the class.

Example of Low Cohesion:

-------------------
| Staff           |
-------------------
| checkEmail()    |
| sendEmail()     |
| emailValidate() |
| PrintLetter()   |
-------------------
Example of High Cohesion:

----------------------------
| Staff                   |
----------------------------
| -salary                 |
| -emailAddr              |
----------------------------
| setSalary(newSalary)    |
| getSalary()             |
| setEmailAddr(newEmail)  |
| getEmailAddr()          |
----------------------------
As for coupling, it refers to how related or dependent two classes/modules are toward each other. For low coupled classes, changing something major in one class should not affect the other. High coupling would make it difficult to change and maintain your code; since classes are closely knit together, making a change could require an entire system revamp.

Good software design has high cohesion and low coupling




Cohesion

Cohesion is the indication of the relationship within module.
Cohesion shows the module’s relative functional strength.
Cohesion is a degree (quality) to which a component / module focuses on the single thing.
While designing you should strive for high cohesion i.e. a cohesive component/ module focus on a single task (i.e., single-mindedness) with little interaction with other modules of the system.
Cohesion is the kind of natural extension of data hiding for example, class having all members visible with a package having default visibility. Cohesion is Intra – Module Concept



