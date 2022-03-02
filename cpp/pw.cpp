#include <iostream>
#include <string>
using namespace std;
int main(){
        string password, name;
        bool is_valid;
        char ans;
        int pin, pin_SUCCESS = 1234;

        cout << "Enter username: ";
                getline(cin, name);
        cout << "Enter password: ";
                getline(cin, password);
        int length = password.length();
        if (length < 9) 
                do {
                        cout << "Your password is too short.\n";
                        cout << "Enter password: ";
                        getline(cin, password);
                } while (length < 9); 
                
        else if (length > 30)
                do {
                        cout << "Your password is too long.\n";
                        cout << "Enter password: ";
                        getline(cin, password);
                } while (length > 30);
        else    
                is_valid = true;
                cout << "...Saving password...\nSUCCESS!\n";
        if (is_valid){
                do {
                        cout << "[A] Password manager\n[X] Exit";
                        cin >> ans;
                } while(!(ans == 'x'||ans == 'X' || ans == 'a'||ans == 'A'));

                switch(ans){
                case 'a':
                case 'A':
                        cout << "User : " + name + "\nPassword : ";
                        for (int i = 0; i < length; i++){
                                cout << "*";
                        }
                        cout << "\nEnter your security pin to view. \n >> ";
                        cin >> pin;
                        while (!(pin == pin_SUCCESS || pin == 0)){
                                cout << "Incorrect PIN!\nEnter your security pin to view. \nEnter [0] to exit.\n >> ";
                                cin >> pin;
                        }
                        if (pin == pin_SUCCESS)
                                cout << "User : " + name + "\nPassword : " + password;
                        else if (pin == 0)
                                return EXIT_SUCCESS;
                break;
                case 'x':
                case 'X':
                        return EXIT_SUCCESS;
                break;
                }

        }
return 0;
}