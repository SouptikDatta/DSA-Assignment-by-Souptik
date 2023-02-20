// C++ code to implement the josephus circle problem
 
#include <iostream>
using namespace std;
 
// Recursive function to implement the Josephus circle problem
int josephus(int N, int m)
{
    //invalid inputs
    if (N == 0 || m == 0)
        return 0;

    //base case
    if (N == 1)
        return 1;

    else
        /*The position returned by josephus(n - 1, k)
            is adjusted because the recursive call
            josephus(n - 1, k) considers the
            original position k % n + 1 as position 1. */
        
        return (josephus(N - 1, m) + m - 1) % N + 1;
}
 
// Driver code
int main()
{
    int N;
    cout << "Enter the total number of people : ";
    cin >> N ;

    int m;
    cout << "Enter the position of the person you want to eliminate : ";
    cin >> m ;

    cout << "The chosen place is " << josephus(N, m);
    return 0;
}