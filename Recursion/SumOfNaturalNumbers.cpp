#include <iostream>
#include <string>

using namespace std;

int sum(int number){
    if (number <= 1){
        return number;
    }

    return number + sum(number-1);
}

int main(){
    int number = 0;
    cin >> number;
    cout << sum(number);
    return 0;
}