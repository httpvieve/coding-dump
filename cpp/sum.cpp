#include <iostream>
#include <string>
using namespace std;
int main(){
        int num, total = 0;
        do {
                cin >> num;
                total += num;
        } while (num > 0);
        cout << "sum: " << total;
        // casting -> (data_type)variable >> i.e : int points, div = (double)points / 2; >> cast to a double
return 0;
}