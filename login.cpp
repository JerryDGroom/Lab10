/*
*******************************************************************
Laboratory 10
Hash Table Lab || Group Project                           login.cpp

Programming Exercise 1: program that reads in user name/login pairs
and performs authentication of user names until EOF is encountered.

Jerry Groom
Lane Colwell
Pacis Bana

5/3/2015
*******************************************************************
*/

#include <string>
#include <iostream>
#include <fstream>
#include "HashTable.cpp"

using namespace std;

int tableSize = 8; //<---------------------- set a reasonable tableSize Here (based on the number of passwords you are going to store)

struct Password
{
    void setKey ( string newKey )
    {
        username = newKey;
    }
    string getKey () const
    {
        return username;
    }
    static unsigned int hash(const string& str)
    {
        int val = 0;

        // implement a hash function  <------------------------------------------------------------------------------------- do this
        // NOTE: don't spend too much time choosing the function -- you can use anything that reasonably
        // distributes the keys in the hash table (except don't use the function used in the test10.cpp file)
        for (int i=0; i<str.length(); i++)
            val += str[i];
        return val;
    }
    string username,
           password;

};

int main()
{
    HashTable<Password, string> passwords(tableSize); // <---------- fill in the blanks
    Password tempPass;
    string name,      // user-supplied name
           pass;      // user-supplied password
    bool userFound;   // is user in table?

    ifstream passFile( "password.dat" );

    if ( !passFile )
    {
        cout << "Unable to open 'password.dat'!" << endl;
        return 1;
    }

    while ( passFile >> tempPass.username >> tempPass.password )
    {
        passwords.insert(tempPass); // <----------- fill in the correct method call
    }

    passwords.showStructure();

    cout << "Login: ";
    while ( cin >> name )
    {
        userFound = passwords.retrieve(name,tempPass);                // <------ fill in the rest of this line

        cout << "Password: ";
        cin >> pass;

        if ( ! userFound || pass != tempPass.password )
            cout << "Authentication failure" << endl;
        else
            cout << "Authentication successful" << endl;

        cout << "Login: ";
    }

    cout << endl;

    return 0;
}

