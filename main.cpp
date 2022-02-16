#include <iostream>
#include <fstream>
#include <random>
#include <string>
#include <vector>
#include "users.cpp"
using namespace std;

// Use the file handling mechanism in C++ to develop a simple console application.
// TODO: Operations: New account, deposit & withdraw amount, balance inquiry, loan request, close account, exit

void signUp();
bool authentication(int option, string n, string p, string e);



void signUp()
{
    string username, password, email;
    int first_option;
    cout << "Welcome to Premier Bank, Please login/sign up to continue.\n1.Login\n2.SignUp\n0.EXIT" << endl;
    cin >> first_option;
    if (first_option == 1)
    {
        system("clear");
        cout << "Username: ";
        cin.ignore();
        getline(cin, username);
        cout << "Password: ";
        getline(cin, password);
        cout << authentication(first_option, username, password, email) <<endl;
    }
    else if (first_option == 2)
    {
        cout << "Choose a new Username: " << endl;
        cin.ignore();
        getline(cin, username);
        cout << "Choose a new Password: " << endl;
        getline(cin, password);
        cout << "What is your Email: " << endl;
        getline(cin, email);
        cout << authentication(first_option, username, password, email)<<endl;
    }
    else
    {
        cout << "Thank you for visiting Premier Bank." << endl;
    }
}

bool authentication(int option, string n, string p, string e)
{
    string db = "users.txt";
    bool exists = false;
    if (option == 1)
    {
        ifstream loginFile(db, ios::in);
        string username, password, email;
        vector<User> users;
        User user;
        while (loginFile)
        {
            loginFile >> username >> password >> email;
            user.setName(username);
            user.setPassword(password);
            user.setEmail(email);
            users.push_back(user);
        }
        loginFile.close();

        for (User user : users)
        {
            if (user.getName() == n)
            {
                if (user.getPassword() == p)
                {
                    exists = true;
                }
            }
        }
    }
    else if (option == 2)
    {
        try
        {
            ofstream loginFile(db, ios::trunc);
            loginFile << n << " " << p << " " << e << endl;
            loginFile.close();
            signUp();
        }
        catch (exception const &e)
        {
            cout << e.what();
        }
    }
    return exists;
}

int main()
{
    signUp();
}