#include <iostream>
#include <vector>
#include <list>

using namespace std;

int removeElement(vector<int>& nums, int val)
{

    nums.erase(remove(nums.begin(), nums.end(), val), nums.end());
    return nums.size();
}

int main(int argc, const char *argv[])
{
    vector<int> test;
    int delVal = 0;

    for (int i = 1; i < argc; ++i)
    {
        cout << argv[i] << endl;
        test.push_back(atoi(argv[i]));
    }

    cout << "enter val you want to remove: ";
    cin >> delVal;

    cout << "before remove" << endl;
    for(vector<int>::iterator it = test.begin(); it != test.end(); ++it)
    {
        cout << (*it) << " ";
    }
    cout << endl;

    removeElement(test, delVal);

    cout << "after remove" << endl;
    for(vector<int>::iterator it = test.begin(); it != test.end(); ++it)
    {
        cout << (*it) << " ";
    }
    cout << endl;

    return 0;
}
