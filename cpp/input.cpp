#include <iostream>
#include <string>
using namespace std;
int main(){
        string name, ans;
        cout << "henlo, what's your name?" << endl;
        //cin >> name; -> only accepts one string element before the first whitespace
        getline(cin, name); // accepts all string elements including whitespaces

        cout << "do you know wendy's?" << endl;
        cin >> ans;
        cout << ans + "? LOLOLOL XD wendy's nutz hit ur forehead!"  << endl;
        cout << "loser who just got pranked: " << name;

        int age;
        cout << "\nhow old r u ?\n";
        cin >> age;
        cout << "u r " << age << " LMAO";
return 0;
}