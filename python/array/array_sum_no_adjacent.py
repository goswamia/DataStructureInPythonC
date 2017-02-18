#!/usr/bin/env python

def sum_1(a, i):
    if i==0:
        return a[i]
    elif i==1:
        return max(a[0], a[1])
    else:
        return max(sum_1(a, i-2)+ a[i], sum_1(a, i-1))

def main():
    a = [5, 5, 10, 100, 10, 5]
    print sum_1(a, len(a)-1)

if __name__ == "__main__":
    main()
