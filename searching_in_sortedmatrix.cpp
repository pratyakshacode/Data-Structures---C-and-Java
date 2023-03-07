#include <iostream>
using namespace std;

int main()
{
    int m, n;
    cout << "Enter no of elements: ";
    cin >> m >> n;
    int arr[m][n];

    cout << "Enter the elements into the array: " << endl;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];

    // searching ina anew way when the array has sorted column and rows

    int r = 0;
    int c = n - 1;
    int target;
    cout << "Enter element to search: ";
    cin >> target;
    bool found = false;
    while (r < m && c >= 0)
    {
        if (arr[r][c] == target)
        {
            cout << r + 1 << " " << c + 1;
            found = true;
            break;
        }
        else if (arr[r][m] > target)
        {
            c--;
        }
        else
        {
            r++;
        }
    }

    if (!found)
    {
        cout << "Elements is not present";
    }

    return 0;
}