#include <iostream>
#include <string>


using namespace std;

bool isPalindrome(string input){
    if (input.length() < 2){
        return true;
    } else {
        bool comparation = (input[0] == input[input.length() - 1]);
        string inputReduced = input.erase(input.length() - 1, 1).erase(0, 1);
        return (comparation) and isPalindrome(inputReduced);
    }
}

int main(){
    string text;
    cin >> text;
    cout << isPalindrome(text);
    return 0;
}