# tile.py

# una generica tessera di gioco

class Tile:
    def __init__(self, value):
        self.value = value

    def set(self, value):
        self.value = value

    def get(self):
        return self.value

    def __str__(self):
        return str(self.value)

    def __repr__(self):
        return str(self.value)

if __name__=='__main__':
    t = Tile(42)
    print(t)
