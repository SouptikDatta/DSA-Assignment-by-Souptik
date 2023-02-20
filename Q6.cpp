// C++ code to implement which displays all pairs of given array of n numbers whose sum is S

#include <bits/stdc++.h>
using namespace std;
 
// Function to find a pair in an array with a given sum using sorting
void findPair(int nums[], int n, int S)
{
    // sort the array in ascending order
    sort(nums, nums + n);
 
    // maintain two indices pointing to endpoints of the array
    int low = 0;
    int high = n - 1;
 
    // reduce the search space `nums[low…high]` at each iteration of the loop
 
    // loop till the search space is exhausted
    while (low < high)
    {
        // sum found
        if (nums[low] + nums[high] == S)
        {
            cout << "Pair found (" << nums[low] << ", " << nums[high] << ")\n";
        }
        if (nums[low] + nums[high] < S) {
            // increment `low` index if the total is less than the desired sum;
            low++;
        }
        else {
        // decrement `high` index if the total is more than the desired sum
            high--;
        }
    }
}
 
int main()
{
    int nums[] = { 8, 7, 2, 5, 3, 1 };
    int S = 10;
 
    int n = sizeof(nums)/sizeof(nums[0]);
 
    findPair(nums, 6, S);
 
}