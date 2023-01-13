#include <bits/stdc++.h>
using namespace std;

int flyPlane(int arr[], int n)
{
    //Checking if the first element is $gt:0 else returning -1
    if (arr[0] == 0)
        return -1;
    //checking if the sum $gt:number of elements 
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    // else returning -1
    if (sum < n - 1)
        return -1;
    //initializing result and currentPlane
    int result = 0;
    int currentPlane = -1;
    // looping through the array
    for (int i = 0; i < n; i++)// Array = [2,1,2,3,1]
    { 
        //initializing temp as temporary variable for storing array values to make it easy for checking
        int temp = arr[i];
        //if currentPlane has 0 fuel left and nearest airport does not have any fuel so its not possible to reach 
        //last airport so returning -1
        if(currentPlane==0 && temp==0){
            return -1;
        }
        //checking if nearest airport has greater source of fuel than the current plane if yes then changing plane
        //and incrementing the result by 1
        if (temp > currentPlane)
        {
            currentPlane = temp;
            result++;
        }
        //decrementing the currentPlane's fuel by 1 everytime we go to the next airport
        currentPlane--;
        //checking if the currentPlane has the capacity to take me to the last airport or if the currentPlane + airport I am currently can take me to the last airport if yes then returning result +1 
        //result + 1 because I want to add the last plane also
        if (temp >= n - 1 || i + temp >= n - 1)
        {
            return result+1;
        }
    }
    //if not possible then returning -1
    return -1;
}
//Time Complexity: O(n)
//Space Complexity: O(n) (only for the input array)
int main()
{

    int n;
    //input no. of elements
    cin >> n;
    int arr[n];
    //input array elements
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    //print the result
    cout << flyPlane(arr, n);
    return 0;
}