#include <iostream>
#include <string>
using namespace std;

class User
{
    string name;
    string email;
    string password;
    int accountNumber;

public:
    User()
    {
        srand(time(0));
        accountNumber = rand();
    }
    string getName() { return name; }
    void setName(string n) { name = n; }
    string getEmail() { return email; }
    void setEmail(string e) { email = e; }
    string getPassword() { return password; }
    void setPassword(string p) { password = p; }
    void getAccountReport()
    {
        cout << endl
             << "**Full Report**\nName:" << name << endl;
        cout << "Email:" << email << endl;
        cout << "Account Number:" << accountNumber << endl;
    }
};