#include <iostream>
#include <string>
using namespace std;
int main(){
        /*
        string group_name;
        cout << "Enter idol group name\n >> ";
        getline(cin, group_name);

        // string_name.length() : returns length of a sting -> number of characters
        int length = group_name.length();
        cout << length;
        */

        string first_name, last_name, user_name = first_name + "_" + last_name; 
        string school_email = user_name.append("@dlsu.edu.ph");
        
        cout << "First name: ";
        getline(cin, first_name);
        cout << "Last name: ";
        getline(cin, last_name);

        //char first_init = first_name.at(0), last_init = last_name.at(0);
        //cout << "Your initials are: " << first_init << last_init;

        cout << "Nickname : " + first_name.substr(4, 8);

        cout << "\nUsername : " + first_name.insert(0,"@");
        

return 0;
}