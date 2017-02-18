#!/usr/bin/env python

def main():
    a = [1, 3, 3, 2, 3]
    max_index = 0
    count = 1
    for i in range(0, len(a), 1):
        if a[max_index] == a[i]:
            count = count+1
        else:
            count = count-1

        if count==0:
            max_index = i
            count = 1

    if a[max_index] > len(a)/2:
        print "Elemenet is %s" %(a[max_index])


if __name__ == "__main__":
    main()
