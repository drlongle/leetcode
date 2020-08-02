class MyHashSet:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.valid = [False] * 1000001
        

    def add(self, key: int) -> None:
        self.valid[key] = True

    def remove(self, key: int) -> None:
        self.valid[key] = False        

    def contains(self, key: int) -> bool:
        """
        Returns true if this set contains the specified element
        """
        return self.valid[key]
        


# Your MyHashSet object will be instantiated and called as such:
# obj = MyHashSet()
# obj.add(key)
# obj.remove(key)
# param_3 = obj.contains(key)
