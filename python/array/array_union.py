#!/usr/bin/env python

def main():
    b = [1, 3, 4, 5, 7]
    a = [2, 3, 5, 6]
    i = 0
    j= 0
    while i<len(a) and j<len(b):
        if a[i] < b[j]:
            print a[i]
            i = i+1
        elif b[j] < a[i]:
            print b[j]
            j = j+1
        else:
            print a[i]
            i = i+1
            j= j+1
    while i<len(a):
        print a[i]
        i = i+1
    while j<len(b):
        print b[j]
        j = j+1

if __name__ == "__main__":
    main()
