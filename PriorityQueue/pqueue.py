class PQ:
    """
      >>> pq = new()
      >>> pq.size()
      0
    """
    def __init__(self):
        self.data = []

    def __eq__(self, other):
        return self.data == other.data

    def size(self):
        return len(self.data)
    
    def isEmpty(self):
        return self.size() == 0
            

def printPQ(pq):
    return(pq.data)


def new():
    """
      >>> pq = new()
      >>> isinstance(pq, PQ)
      True
    """
    return PQ()


def insert(val, pq):
    """
      >>> pq = new()
      >>> pq.size()
      0
      >>> insert(7, pq)
      >>> pq.size()
      1
      >>> insert(4, pq)
      >>> printPQ(pq)
      [4, 7]
      >>> insert(5, pq)
      >>> printPQ(pq)
      [4, 5, 7]
      >>> insert(2, pq)
      >>> printPQ(pq)
      [2, 4, 5, 7]

    """

    pos = -1
    pq.data.append(val)
    
    if pq.size() != 1:

        while pq.data[0] != pq.data[pos]:
            if pq.data[pos] < pq.data[pos - 1]:
                pq.data[pos], pq.data[pos - 1] = pq.data[pos - 1], pq.data[pos]
                pos -= 1
            else:
                break



def min(pq):
    """
      >>> pq = new()
      >>> insert(7, pq)
      >>> insert(4, pq)
      >>> insert(5, pq)
      >>> insert(2, pq)
      >>> min(pq)
      2
      

    """
    return pq.data[0]


def dm(pq):
    """
      >>> original = new()
      >>> pq = new()
      >>> pq == original
      True
      >>> insert(7, pq)
      >>> pq == original
      False
      >>> dm(pq)
      >>> pq == original
      True

    """

    pq.data.pop()


def priority(val):
    """
    """


if __name__ == "__main__":
    import doctest
    doctest.testmod()


