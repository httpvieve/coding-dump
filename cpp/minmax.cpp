#include <iostream>

using namespace std;

int main(){
        int num_temp, counter = 1;
        cout << "enter num: \n >>";
        cin >> num_temp;
        int min = num_temp, max = num_temp;
        while (!(counter == 10)){
                cout << "enter num: \n >>";
                cin >> num_temp;
                if (num_temp < min)
                        min = num_temp;
                else if (num_temp > max)
                        max = num_temp;
                counter ++;
        }
        cout << "max : " << max << "\nmin : " << min;
return 0;
}