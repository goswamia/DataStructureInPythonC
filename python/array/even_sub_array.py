#!/usr/bin/env python
import math
import itertools

def check_number():
    a = [1, 2, 2, 3, 4, 1]
    count_eve = 0
    count_odd = 0
    for i in range(0, len(a), 1):
        if a[i]%2 == 0:
            count_eve = count_eve +1
        else:
            count_odd = count_odd + 1
    f = math.factorial
    print math.factorial(count_eve) + f(count_odd)/f(count_odd-1)


def main():
    """determine sub of even number"""
    a = [1, 2, 2, 3, 4, 1]
    count = 0
    for i in range(0, len(a), 1):
        if a[i]%2==0:
            count = count+1
        for j in range(i+1, len(a), 1):
            if (a[i]+a[j])%2 == 0:
                count = count+1
    print count
    check_number()
if __name__ == "__main__":
    main()
