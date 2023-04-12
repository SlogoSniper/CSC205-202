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
    """
    pq.data.append(val)


def min(pq):
    """
      >>> pq = new()
      >>> insert(7, pq)
      >>> min(pq)
      7
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


def priority(val):
    """
    """


if __name__ == "__main__":
    import doctest
    doctest.testmod()
