#include <iostream>
using namespace std;

//function to check if the string is Palindrome
int isPalindrome(string str)
{
    //the first index
    int start_index = 0;
 
    //the last index
    int last_index = str.length()-1;
 
    while(start_index < last_index && str[start_index] == str[last_index])
    {
        //increment start index and decrement last index
        start_index++;
        last_index--;
    }
 
    if(start_index < last_index)
    {
        //this means that we did not reach the center
        cout << "Not Palindrome." << endl;
        return 0;
    }
    else
    {
        //we reached the center
        cout << "Yes,Palindrome." << endl;
        return 1;
    }
}

int main()
{
    isPalindrome("ababXbaba");
    isPalindrome("ababaXaabbb");

    return 0;
}