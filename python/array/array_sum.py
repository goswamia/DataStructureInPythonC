#!/usr/bin/env python

def get_sum(a, num_sum):
    max_array = [0]*10000
    for i in range(0, len(a), 1):
        t_sum = num_sum-a[i]
        if t_sum>= 0 and max_array[t_sum]==1:
            print "Number is %s %s" %(a[i], t_sum)
        max_array[a[i]] = 1

def main():
    a = [1, 4, 45, 10, 6, 8]
    get_sum(a, 16)

if __name__ == "__main__":
    main()
