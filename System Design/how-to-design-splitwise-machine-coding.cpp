

How to design Splitwise? - Machine Coding Round Questions


Create an expense sharing application.


An expense sharing application is where you can add your expenses and split it among different people. The app keeps balances between people as in who owes 
how much to whom.



https://workat.tech/machine-coding/article/how-to-design-splitwise-machine-coding-ayvnfo1tfst6



Example

You live with 3 other friends.

You: User1 (id: u1)

Flatmates: User2 (u2), User3 (u3), User4 (u4)

---

This month's electricity bill was Rs. 1000.

Now you can just go to the app and add that you paid 1000,

select all the 4 people and then select split equally.

Input: u1 1000 4 u1 u2 u3 u4 EQUAL

For this transaction, everyone owes 250 to User1.

The app should update the balances in each of the profiles accordingly. User2 owes User1: 250 (0+250)

User3 owes User1: 250 (0+250)

User4 owes User1: 250 (0+250)



Requirements

User: Each user should have a userId, name, email, mobile number.



Expense: Could either be EQUAL, EXACT or PERCENT

Users can add any amount, select any type of expense and split with any of the available users.

The percent and amount provided could have decimals upto two decimal places.

In case of percent, you need to verify if the total sum of percentage shares is 100 or not.

In case of exact, you need to verify if the total sum of shares is equal to the total amount or not.

The application should have a capability to show expenses for a single user as well as balances for everyone.

When asked to show balances, the application should show balances of a user with all the users where there is a non-zero balance.

The amount should be rounded off to two decimal places. Say if User1 paid 100 and amount is split equally among 3 people. Assign 33.34 to first person and 33.33 
to others.




Input

You can create a few users in your main method. No need to take it as input.

There will be 3 types of input:

Expense in the format: EXPENSE <user-id-of-person-who-paid> <no-of-users> <space-separated-list-of-users> <EQUAL/EXACT/PERCENT> <space-separated-values-in-case-of-non-equal>

Show balances for all: SHOW

Show balances for a single user: SHOW <user-id>



Output

When asked to show balance for a single user. Show all the balances that user is part of:

Format: <user-id-of-x> owes <user-id-of-y>: <amount>

If there are no balances for the input, print No balances

In cases where the user for which balance was asked for, owes money, they’ll be x. They’ll be y otherwise.




Optional Requirements

- A way to add an expense name while adding the expense. Can also add notes, images, etc.

- Option to split by share. Ex: ‘User4 pays and everyone splits equally. You pay for 2 people.’ could be added as: u4 1200 4 u1 u2 u3 u4 SHARE 2 1 1 1

- A way to show the passbook for a user. The entries should show all the transactions a user was part of. You can print in any format you like.

- There can be an option to simplify expenses. When simplify expenses is turned on (is true), the balances should get simplified. Ex: ‘User1 owes 250 to User2 
and User2 owes 200 to User3’ should simplify to ‘User1 owes 50 to User2 and 200 to User3’.

There could be different ways to design a solution for this. I’ll mention how I would have approached it during an actual interview.

Let’s dissect the problem statement to determine how to design a good solution for it.

The gist of the problem statement is that we need to create an expense sharing application. The application will have multiple users, an option to add 
expenses (EQUAL, EXACT or PERCENT) and an option to show balances (All or a specific user).

Here I’ve decided that I’ll keep a Driver class to take input from the user and a ExpenseManager class to orchestrate the application.

In the interview, I’ll not focus on solving with the optional requirements but will try to keep my design such that if I’ve time, I can do minimal changes
to add them. Let’s look at each of those requirements one-by-one and see which ones I would want to ignore to keep my design clean. The problem is supposed to 
be solved in 2 hours and so I do not want to get stuck in something that is time-consuming but optional.

For optional requirement #1, I am anyway keeping an Expense model class so adding attributes should be easy.
For optional requirement #2, to keep my code extensible, I’ll anyway be having different types of splits so adding another should be easy.
For optional requirement #3, I’ll keep an expense list in the ExpenseManager.
For optional requirement #4, I’ll have to take extra care of not messing up the logic and so ignoring this optional requirement for now. Let’s see if my design 
can accommodate that without much change.



Then, I’ll note down the entities (models) that will be involved in the design.

User
Split (EqualSplit, ExactSplit, PercentSplit)
ExpenseMetadata (For Optional requirement #1)
Expense (EqualExpense, ExactExpense, PercentExpense)
ExpenseType (enum to differentiate between different expense types)


package com.workattech.splitwise.models;

public class User {
    private String id;
    private String name;
    private String email;
    private String phone;

    public User(String id, String name, String email, String phone) {
        this.id = id;
        this.name = name;
        this.email = email;
        this.phone = phone;
    }

    public String getId() {
        return id;
    }

    public void setId(String id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public String getPhone() {
        return phone;
    }

    public void setPhone(String phone) {
        this.phone = phone;
    }
}



public abstract class Split {
    private User user;
    double amount;

    public Split(User user) {
        this.user = user;
    }

    public User getUser() {
        return user;
    }

    public void setUser(User user) {
        this.user = user;
    }

    public double getAmount() {
        return amount;
    }

    public void setAmount(double amount) {
        this.amount = amount;
    }
}






Yet to complete


























