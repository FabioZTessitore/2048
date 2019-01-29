# tile2048.py

# A Tile for 2048 game
#
# A Tile2048 is a Tile (has a value)
# and store the flag 'can_grow'.
# When the flag is False, the Tile is
# locked and cannot be modified

from tile import Tile

class Tile2048(Tile):
    def __init__(self, initialValue):
        Tile.__init__(self, initialValue)
        self.can_grow = True

    def double(self):
        self.value *= 2
        self.lock()

    def lock(self):
        self.can_grow = False

    def unlock(self):
        self.can_grow = True

    def isLocked(self):
        return self.can_grow == False

    def __str__(self):
        return Tile.__str__(self) + \
                "\nlocked: " + str(self.isLocked())

if __name__=='__main__':
    print("Creating a Tile with value 42")

    t = Tile2048(42)

    print("Tile string repr:")
    print(t)

    print ("\nDoubling ...")
    t.double()
    print(t)

    print("\nIs Locked?")
    print(t.isLocked())

    print("\nUnlock")
    t.unlock()
    print(t)
