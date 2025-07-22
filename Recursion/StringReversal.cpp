#include <iostream>
#include <string>

using namespace std;

string reverseString(string cadena){
    if(cadena == ""){
        return "";
    } else {
        return reverseString(cadena.erase(0, 1)) + cadena.at(0);
    }
}

int main(){
    std::string aRevertir;
    std::cin >> aRevertir;
    std::cout << reverseString(aRevertir);
    return 0;
}