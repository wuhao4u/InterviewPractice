#include <vector>

using namespace std;

// return the position of the 1st occurance of the target
int binarySearch(vector<int> &A, int target) {
    if (A.size() == 0) {
        return -1;
    }

    int start = 0;
    int end = A.size() - 1;
    int mid;

    // this is a template, some questions require us to find tricky middle position
    // start + 1 < end will avoid infinite loop
    while(start + 1 < end) {
        // why not use (start + end) / 2
        // cause (start + end) may overflow for very large integer
        mid = start + (end - start) / 2;

        if (A[mid] == target) {
            end = mid;
        } else if (A[mid] < target) {
            start = mid;
        } else if (A[mid] > target){
            // we could just use else here, instead of else if
            end = mid;
        }
    }

    if (A[start] == target) {
        return start;
    }

    if (A[end] == target) {
        return end;
    }

    return -1;
}