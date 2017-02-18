#!/usr/bin/env python

def main():
    a = [10, 3, 5, 6, 2]
    sumi = 1
    for i in range(0, len(a), 1):
        sumi *= a[i]
    for i in range(0, len(a), 1):
        print sumi/a[i]


if __name__ == "__main__":
    main()
