def mergesort(my_list):
    if len(my_list) <= 1:
        return my_list

    mid_index = int(len(my_list) / 2)

    left = mergesort(my_list[0:mid_index])
    right = mergesort(my_list[mid_index:])

    return merge(left, right)


def merge(l1, l2):
    i = j = 0
    res = []
    while i < len(l1) and j < len(l2):
        if l1[i] < l2[j]:
            res.append(l1[i])
            i += 1
        else:
            res.append(l2[j])
            j += 1


    while i < len(l1):
        res.append(l1[i])
        i += 1

    while j < len(l2):
        res.append(l2[j])
        j += 1

    return res


if __name__ == '__main__':
    l1 = [5, 1, 6, 2, 9, 7, 8]
    l2 = [0, 0, 5, 6, 9, 8, -8, -7, -1000]
    print(mergesort(l1))
    print(mergesort(l2))
