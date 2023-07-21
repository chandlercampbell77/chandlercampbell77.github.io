class Jar:
    def __init__(self, capacity=12):
        if type(capacity) is not int:
            raise ValueError("Capacity must be an integer")
        if capacity < 1:
            raise ValueError("Capacity must be at least 1")
        self._capacity = capacity
        self._n = 0

    def __str__(self):
        cookies = "🍪" * self._n
        return cookies

    def deposit(self, n):
        if self._n + n > self._capacity:
            raise ValueError("Too many cookies in the jar!")
        else:
            self._n += n

    def withdraw(self, n):
        if self._n - n < 0:
            raise ValueError("Not enough cookies in the jar!")
        else:
            self._n -= n


    @property
    def capacity(self):
        return self._capacity

    @property
    def size(self):
        return self._n

def main():
    jar = Jar()
    jar.deposit(10)
    print(str(jar))
    jar.withdraw(5)
    print(str(jar))

main()