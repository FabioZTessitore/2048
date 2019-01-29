# tile.py

# A generic game tile
# 
# A tile has only a value

class Tile:
    def __init__(self, initialValue):
        self.value = initialValue

    #def set(self, newValue):
    #    self.value = newValue

    def get(self):
        return self.value

    def __str__(self):
        return str(self.value)

    def __repr__(self):
        return "Tile("+ str(self.value) + ")"

if __name__=='__main__':
    print("Creating a Tile with value 42")

    t = Tile(42)

    print("Tile string repr:")
    print(t)
