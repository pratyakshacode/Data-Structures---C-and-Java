#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n];
    cout<<"Enter the elements into the array: "<<endl;
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }

    // longest arithmetic subarray

    int cd = arr[1] - arr[0];
    int length = 2;
    int ans = 2;
    int i = 0;
    while (i < n)
    {

        if (cd == arr[i] - arr[i - 1])
        {
            length++;
        }
        else
        {
            length = 2;
        }
        ans = max(ans, length);
        i++;
    }

    cout << "The arithmetic subarray has a length of " << ans-1;

    return 0;
}