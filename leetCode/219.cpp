#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool containsNearbyDuplicate_slow(int* nums, int numsSize, int k) {
    for (int i = 0; i < numsSize; ++i)
    {
        for (int j = 1; j < numsSize; ++j)
        {
            if(i == j) continue;
            if(nums[j] == nums[i] && abs(i - j) <= k) {
                printf("found it: %d\n", nums[j]);
                return true;
            }
        }
    }

    return false;
}

bool containsNearbyDuplicate(vector<int>& nums, int k) {
    if(nums.size() <= 1) return false;
    if(k <= 0) return false;

    for(vector<int>::iterator it; it != nums.end(); it++) {
        vector<int>::iterator occurance = find(nums.begin(), nums.end(), *it);
        cout << "WAT" << endl;
        while(occurance != nums.end()) {
            if(occurance != it) {
                cout << "distance: " << abs(occurance - it) << endl;
                return true;
            }
            else {
                occurance = find(occurance, nums.end(), *it);
            }
        }
    }
    return false;
}


int main(int argc, char const *argv[]) {
    vector<int> test;
    test.push_back(0);
    test.push_back(2);
    test.push_back(4);
    test.push_back(6);
    test.push_back(0);
    test.push_back(5);

    // test.push_back(-1);
    // test.push_back(-1);
    cout << containsNearbyDuplicate(test, 1) << endl;
    return 0;
}