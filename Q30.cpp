#include <bits/stdc++.h>
using namespace std;
 
// A function to find factorial of a given number
unsigned long int factorial(unsigned int n)
{
    unsigned long int res = 1;
 
    // Calculate value of [1*(2)*---*(n-k+1)] / [k*(k-1)*---*1]
    for (int i = 1; i <= n; ++i){
        res *= i;
    }
    return res;
}
 
unsigned long int binomialCoeff(unsigned int n, unsigned int k)
{
    unsigned long int res = 1;
    // Since C(n, k) = C(n, n-k)
    if (k > n - k)
        k = n - k;
 
    // Calculate value of [n*(n-1)*---*(n-k+1)] / [k*(k-1)*---*1]
    for (int i = 0; i < k; ++i){
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}
 
// A Binomial coefficient based function to find nth catalan number in O(n) time
unsigned long int catalan(unsigned int n)
{
    // Calculate value of 2nCn
    unsigned long int c = binomialCoeff(2*n, n);
 
    // return 2nCn/(n+1)
    return c/(n+1);
}
 
// A function to count number of BST with n nodes using catalan
unsigned long int countBST(unsigned int n)
{
    // find nth catalan number
    unsigned long int count = catalan(n);
 
    // return nth catalan number
    return count;
}

int main()
{
    int count1;
    int n = 5;
    // find count of BST with n nodes
        count1 = countBST(n);
     
    // print count of BST and binary trees with n nodes
    cout<<"Count of BST with "<< n << " nodes is "<< count1 << endl;
 
    return 0;
}