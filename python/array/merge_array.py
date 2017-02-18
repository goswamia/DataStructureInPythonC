#!/usr/bin/env python

def movetoend(m):
    m_size = len(m)-1
    j = m_size
    for m_data in range(m_size, -1, -1):
        if int(m[m_data]) != -1:
            m[j] = m[m_data]
            j = j-1
            m[m_data] = -1

def mergearray(m, n):
    l = len(n)
    k = 0
    for i in range(0, len(m), 1):
        if l< len(m) and m[l] < n[k]:
            m[i] = m[l]
            l = l+1
        elif k < len(n):
            m[i] = n[k]
            k = k+1

def main():
    m = [2, -1, 7, -1, -1, 10, -1]
    n = [5, 8, 12, 14]
    movetoend(m)
    mergearray(m,n)
    print m

if __name__ == "__main__":
    main()
