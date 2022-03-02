#include<iostream>

using namespace std;
int main(){
        int temp;
        cout << "input temperature (C): ";
        cin >> temp;
                if (temp > 30)
                        cout << "AAAAAA! It's HOT outside!";
                else if (temp <= 0)
                        cout << "It is COLD outside *brrrrrrr*";
                else    
                        cout << "It is WARM outside:D";
return 0;
}