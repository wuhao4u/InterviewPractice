#include <iostream>
#include <vector>

using namespace std;

void moveZeroes(vector<int>& nums)
{
    for (int i = 0; i < nums.size(); ++i)
    {
        if(nums[i] == 0)
        {
            if(i == 0)
            {
                cout << "here" << endl;
                nums.erase(nums.begin());
            }
            else
            {
                nums.erase(nums.begin() + i);                
            }
            nums.push_back(0);
        }
    }
}


void moveZeroesIter(vector<int>& nums)
{
    int zCount = 0;
    vector<int>::iterator it;// = nums.begin();

    while(it != nums.end()) {
        it = find(nums.begin(), nums.end(), 0);
        if(it != nums.end())
        {
            nums.erase(it);
            zCount++;
        }
    }

    for (int i = 0; i < zCount; ++i)
    {
        nums.push_back(0);
    }
}

void vPrinter(vector<int>& nums)
{
    for (std::vector<int>::iterator i = nums.begin(); i != nums.end(); ++i)
    {
        cout << (*i) << endl;
    }
}

int main()
{
  int myints[] = {16,0,2, 0, 77,29};
  vector<int> first (myints, myints + sizeof(myints) / sizeof(int) );
  moveZeroesIter(first);
    cout << "first: " << endl;
  vPrinter(first);

  int myints1[] = {0,0,1, 0};
  vector<int> second (myints1, myints1 + sizeof(myints1) / sizeof(int) );
  moveZeroesIter(second);
    cout << "second: " << endl;
  vPrinter(second);

  int myints2[] = {16,0,2,77,29};
  vector<int> third (myints2, myints2 + sizeof(myints2) / sizeof(int) );
  moveZeroesIter(third);
    cout << "third: " << endl;
  vPrinter(third);

}