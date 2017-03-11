#!/usr/bin/env python

class sample(object):
    def __init__(self, x=0, y=0):
        self.x = x
        self.y = y

    #def __repr__(self):
    #    return "The value is x = %s y %s" %(self.getX(), self.getY())

    def __str__(self):
        return "The value is x = %s y %s" %(self.getX(), self.getY())

    def getX(self):
        return self.x

    def getY(self):
        return self.y

    @classmethod
    def set_data(cls, data):
        return cls(data[0], data[1])


def main():
    print "Sample constructor"
    s = sample()
    print s
    data =(10, 20)
    s2 = sample.set_data(data)
    print s2
if __name__ == "__main__":
    main()
