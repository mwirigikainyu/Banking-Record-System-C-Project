#include <iostream>
#include <fstream>
#include <random>
#include <string>
#include <sstream>
#include <vector>
#include "users.cpp"
using namespace std;

// Use the file handling mechanism in C++ to develop a simple console application.
// TODO: Operations: New account, deposit & withdraw amount, balance inquiry, loan request, close account, exit

void signUp(string message);
bool authentication(int option, string n, string p, string e);

void signUp(string message)
{
    string username, password, email;
    int first_option;
    if (!message.empty())
    {
        cout << message << endl;
    }
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
        if (authentication(first_option, username, password, email))
        {
            system("clear");
            cout << "Successfully logged in. \nWelcome " << username << "!" << endl;
        }
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
        authentication(first_option, username, password, email);
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
        vector<User> users;
        string clientDetails;
        User user;
        while (getline(loginFile, clientDetails))
        {
            vector<string> details;
            stringstream stream_details(clientDetails);
            while (stream_details.good())
            {
                string substr;
                getline(stream_details, substr, ',');
                details.push_back(substr);
            }
            user.setName(details.at(0));
            user.setPassword(details.at(1));
            user.setEmail(details.at(2));
            users.push_back(user);
        }

        loginFile.close();

        bool userFound = false;

        for (User user : users)
        {
            if (user.getName() == n)
            {
                userFound = true;
                if (user.getPassword() == p)
                {
                    exists = true;
                }
                else
                {
                    signUp("Wrong password");
                }
            }
        }

        if (!userFound)
        {
            signUp("User not found");
        }
    }
    else if (option == 2)
    {
        try
        {
            ofstream loginFile(db, ios::app);
            loginFile << n << "," << p << "," << e << endl;
            loginFile.close();
            signUp("");
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
    signUp("");
}