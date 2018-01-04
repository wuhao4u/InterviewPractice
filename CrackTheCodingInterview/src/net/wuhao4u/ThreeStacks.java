package net.wuhao4u;

public class ThreeStacks {
    /*
    Q31, 3.1
    Describe how you could use a single array to implement 3 stacks
     */

    private int capacity = 27;
    private int cap1, cap2, cap3;
    private int size1, size2, size3;
    private Object[] a;

    public ThreeStacks(int initSize) {
        assert (initSize >= 3);

        a = new Object[initSize * 3];
        capacity = initSize;
        cap1 = capacity / 3;
        cap2 = capacity / 3;
        cap3 = capacity - cap1 - cap2;
    }

    // Way 1: evenly divide the array for 3 stacks
    Object pop(int stackNum) {
        switch (stackNum) {
            case 1:
                if (size1 > 0) {
                    return a[size1--];
                } else {
                    return null;
                }
            case 2:
                if (size2 > 0) {
                    return a[size2--];
                } else {
                    return null;
                }
            case 3:
                if (size3 > 0) {
                    return a[size3--];
                } else {
                    return null;
                }
            default:
                return null;
        }
    }

    void push(int stackNum, Object item) {
        switch (stackNum) {
            case 1:
                if (size1 < cap1 - 1) {
                    a[size1++] = item;
                }
                break;
            case 2:
                if (size2 < cap2 - 1) {
                    a[size2++] = item;
                }
                break;
            case 3:
                if (size3 < cap3 - 1) {
                    a[size3++] = item;
                }
                break;
            default:
                break;
        }
    }

    Object peek(int stackNum) {
        switch (stackNum) {
            case 1:
                return a[size1 - 1];
            case 2:
                return a[size2 - 1];
            case 3:
                return a[size3 - 1];
            default:
                return null;
        }
    }

    public static void main(String[] args) {

    }
}
