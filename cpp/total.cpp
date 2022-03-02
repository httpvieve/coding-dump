#include <iostream>
#include <string>

using namespace std;

int main(){
        string item_name;
        double item_price, total_amount;
        int item_quantity;

        cout << "What item do you want to purchase? \n >> ";
        getline(cin, item_name);
        cout << "Input item price: $";
        cin >> item_price;
        cout << "How many do you want to purchase? \n >> ";
        cin >> item_quantity;

        total_amount = item_price * item_quantity;

        cout << "You purchased " << item_quantity << " " + item_name + "(s).\nTotal amount: $" << total_amount;
return 0;
}