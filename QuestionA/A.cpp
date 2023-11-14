#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int isGraphic(vector<int> &degrees, int num)
{
    if (num == 0)
    {
        cout << "YES";
        return 1;
    }

    int flag = 1;
    for (int i = 0; i < num; i++)
    {
        if (degrees[i] > num - 1)
        {
            cout << "NO";
            return -1;
        }
        if (degrees[i] < 0)
        {
            cout << "NO";
            return -1;
        }
        if (degrees[i] > 0)
        {
            flag = 0;
        }
    }

    if (flag == 1)
    {
        cout << "YES";
        return 1;
    }

    if (flag == 0)
    {
        int head = degrees[0];
        degrees.erase(degrees.begin());
        for (int i = 0; i < head; i++)
        {
            degrees[i]--;
        }
        sort(degrees.begin(), degrees.end(), greater<int>());
        return isGraphic(degrees, num - 1);
    }

    return 0;
}

int main()
{
    int num;
    vector<int> degrees;
    cin >> num;
    int input_value;
    for (int i = 0; i < num; i++)
    {
        cin >> input_value;
        degrees.emplace_back(input_value);
    }
    isGraphic(degrees, num);
    return 0;
}
