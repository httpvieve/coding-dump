#include <iostream>
#include <string>
using namespace std;
int main(){
        double gwa;
        char final_grade;
        
        do {
                cout << "Input GWA: ";
                cin >> gwa;
        } while (!(gwa > 0 && gwa <= 100));

        if (gwa > 0 && gwa <= 100){
                if (gwa <= 60)
                        final_grade = 'F';
                else if (gwa > 60 && gwa < 69)
                        final_grade = 'E';
                else if (gwa > 67 && gwa < 77)
                        final_grade = 'D';
                else if (gwa > 75 && gwa < 85)
                        final_grade = 'C';
                else if (gwa > 83 && gwa < 93)
                        final_grade = 'B';
                else 
                        final_grade = 'A';
                cout << "Final grade: " << final_grade;
        }
return 0;
}