#!/usr/bin/env python

def main():
    a = [1, 2, 90, 10, 110]
    max_num = a[1]-a[0]
    min_num = a[0]
    for i in range(0, len(a), 1):
        if a[i]-min_num>max_num:
            max_num = a[i]-min_num
        if a[i] < min_num:
            min_num = a[i]
    print max_num

if __name__ == "__main__":
    main()
