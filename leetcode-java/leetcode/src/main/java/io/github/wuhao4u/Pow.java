package io.github.wuhao4u;

public class Pow {
    public double myPow(double x, int n) {
        if (x == 0) {
            return 0;
        } else if (x == 1) {
            return 1;
        }

        if (n == 0) {
            return 1;
        } else if (n == 1) {
            return x;
        }

        double res = 0;
        if (n < 0) {
            res = powHelper(x, Math.abs(n), x);
            return 1 / res;
        } else {
            res = powHelper(x, n, x);
            return res;
        }
    }

    private double powHelper(double base, int n, double curr) {
        if (n == 1) {
            return curr;
        }

        if (curr <= Double.MAX_VALUE * -1) {
            return curr;
        }

        if (curr >= Double.MAX_VALUE) {
            return curr;
        }

        return powHelper(base, n - 1, curr * base);
    }

    public double myPowSol1(double x, int n) {
        long N = n;
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }
        double ans = 1;
        for (long i = 0; i < N; i++)
            ans = ans * x;
        return ans;
    }



    private double fastPow(double x, long n) {
        if (n == 0) {
            return 1.0;
        }
        double half = fastPow(x, n / 2);
        if (n % 2 == 0) {
            return half * half;
        } else {
            return half * half * x;
        }
    }

    public double myPow2(double x, int n) {
        long N = n;
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }

        return fastPow(x, N);
    }
    public static void main(String[] args) {
//        boolean b = false;
//        double x = Double.MIN_VALUE;
        Pow solution = new Pow();
        System.out.println(solution.myPow(-2, 2));
        System.out.println(solution.myPow(0.00001, 2147483647));
    }
}
