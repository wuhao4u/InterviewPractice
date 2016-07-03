def removeElement(nums, val):
    """
    :type nums: List[int]
    :type val: int
    :rtype: int
    """
    m_set = set(nums)
    return len(m_set)

test = [3,3]
print(removeElement(test, 3)) 