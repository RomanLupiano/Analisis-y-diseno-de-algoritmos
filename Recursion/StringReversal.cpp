#include <iostream>
#include <string>

using namespace std;

string reverseString(string input){
    if(input == ""){
        return "";
    } else {
        return reverseString(input.erase(0, 1)) + input.at(0);
    }
}

int main(){
    string text;
    cin >> text;
    cout << reverseString(text);
    return 0;
}