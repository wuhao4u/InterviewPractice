def containsNearbyDuplicate(nums, k):
    """
    :type nums: List[int]
    :type k: int
    :rtype: bool
    """
    pos_dict = {}

    for index, item in enumerate(nums):
        if item not in pos_dict:
            pos_dict[item] = index
        else:
            if abs(pos_dict[item] - index) <= k:
                return True
            else:
                pos_dict[item] = index
    return False

test = [0,1,2,3,4,5,0]
print(containsNearbyDuplicate(test, 6))