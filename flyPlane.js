//input array
var arr = [2, 1, 2, 3, 1];

//Time Complexity: O(n)
//Space Complexity: O(n) (only for the input array)

function outputResult(arr, n) {
    //Checking if the first element is $gt:0 else returning -1
    if (arr[0] == 0)
        return -1;
    //checking if the sum $gt:number of elements 
    var sum = 0;
    for (let i = 0; i < n; i++) {
        sum += arr[i];
    }
    // else returning -1
    if (sum < n - 1)
        return -1;
    //initializing result and currentPlane
    var result = 0;
    var currentPlane = -1;
    // looping through the array
    for (let i = 0; i < n; i++) {
        //initializing temp as temporary variable for storing array values to make it easy for checking
        var temp = arr[i];
        //if currentPlane has 0 fuel left and nearest airport does not have any fuel so its not possible to reach 
        //last airport so returning -1
        if (currentPlane == 0 && temp == 0) {
            return -1;
        }
        //checking if nearest airport has greater source of fuel than the current plane if yes then changing plane
        //and incrementing the result by 1
        if (temp > currentPlane) {
            currentPlane = temp;
            result++;
        }
        //decrementing the currentPlane's fuel by 1 everytime we go to the next airport
        currentPlane--;
        //checking if the currentPlane has the capacity to take me to the last airport or if the currentPlane + airport I am currently can take me to the last airport if yes then returning result +1 
        //result + 1 because I want to add the last plane also
        if (temp >= n - 1 || i + temp >= n - 1) {
            return result + 1;
        }
    }
    //if not possible then returning -1
    return -1;
}

//Outputting the result
console.log(outputResult(arr, arr.length));