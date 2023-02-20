#include <iostream>
#include <string>
using namespace std;

string removeAdjacentDuplicates(string s) {
    
    //return the input string as there can be no adjacent duplicates in a string of length 0 or 1.
    if (s.length() < 2) {
        return s;
    }
    
    // length of the string is greater than or equal to 2
    int i = 0;
    while (i < s.length() - 1 && s[i] == s[i+1]) {
        i++;
    }

    //if the first two characters of the string are equal,remove those two characters &
    //recursively call the function on the rest of the string
    if (i > 0) {
        s = s.substr(i+1);
        return removeAdjacentDuplicates(s);
    }

    //If not equal,recursively call the function on the rest of the string &
    //concatenate the first character of the input string with the result of the recursive call
    string rest = removeAdjacentDuplicates(s.substr(1));
    if (rest.length() > 0 && s[0] == rest[0]) {
        return rest.substr(1);
    } else {
        return s[0] + rest;
    }
}

//Driver code
int main() {
    
    string s1 = "Careermonk";
    cout << removeAdjacentDuplicates(s1) << endl;

    string s2 = "Mississippi";
    cout << removeAdjacentDuplicates(s2) << endl;

    return 0;
}