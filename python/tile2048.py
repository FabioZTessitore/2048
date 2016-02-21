# tile2048.py

# una tessera del gioco 2048

from tile import Tile

class Tile2048(Tile):
    def __init__(self, value):
        Tile.__init__(self, value)
        self.can_grow = True

    def doubleMe(self):
        self.value *= 2
        self.can_grow = False

    def resetCanGrow(self):
        self.can_grow = True

    def canGrow(self):
        return self.can_grow

    def __str__(self):
        return Tile.__str__(self) + \
                "\ncan_grow: " + str(self.can_grow)

if __name__=='__main__':
    t = Tile2048(42)
    print(t)

    print ("raddioppio")
    t.doubleMe()
    print(t)

    print("can grow?")
    print(t.canGrow())

    print("reset can_grow")
    t.resetCanGrow()
    print(t)
