#include <iostream>
#include <string>
using namespace std;

int main(){
        int n, i, prod = 1;
        cin >> n;
        for (i = 1; i <= n; i++){
                prod *= i;
                if (i < n) {
                        cout << i << "*";
                }else if(i == n){
                        cout << i;
                }
        }
        cout << " = " << prod;
}