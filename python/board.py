# board.py

# A generic board
#
# A board is a square of positions.
# Every position can be empty or occupied by a Tile

from tile import Tile

class Board:
    def __init__(self, size):
        if type(size)!=int or size<=0:
            raise ValueError('Board.__init__: size must be a positive integer')

        self.size = size
        numberOfPositions = size * size

        # start with empty positions
        self.positions = [None] * numberOfPositions

        # list of empty positions
        self.updateEmptyPositions()

    def insertTile(self, index, tile):
        if self.positions[index]:
            raise ValueError('Board.insert: position not empty')

        self.positions[index] = tile
        self.updateEmptyPositions()

    def removeTile(self, index):
        self.positions[index] = None
        self.updateEmptyPositions()

    def getTile(self, index):
        return self.positions[index]

    def updateEmptyPositions(self):
        self.emptyPositions = [index for index in range(self.size**2) if self.positions[index]==None]

    def someEmptyPosition(self):
        return len(self.emptyPositions)>0

    def positionIsEmpty(self, index):
        return self.positions[index] == None

    def moveTile(self, indexFrom, indexTo):
        if self.positionIsEmpty(indexTo):
            self.insertTile(indexTo, self.getTile(indexFrom))
            self.removeTile(indexFrom)

    def __str__(self):
        emptyPositionsLen = len(self.emptyPositions)

        s = "Board Size: " + str(self.size)
        s += "\nNumber of Empty Positions: " + str(emptyPositionsLen)
        s += "\nAny Empty Position? "
        if self.someEmptyPosition():
            s += "yes"
        else:
            s += "no"
        s += "\nEmpty Positions Indices: " + str(self.emptyPositions)
        s += "\nDump positions:\n"
        s += str(self.positions)

        return s


if __name__=='__main__':
    size = 3

    print("Creating an empty Board")
    game_board = Board(size)
    print(game_board)

    print("\nCreating a Board")
    game_board = Board(size)
    for index in range(size*size):
        tile = Tile(index+1)
        game_board.insertTile(index, tile)
    print(game_board)

    print("\nCreating a Board with a Tile at position 0")
    game_board = Board(size)
    tile = Tile(42)
    game_board.insertTile(0, tile)
    print("Move the tile to position 1")
    game_board.moveTile(0, 1)
    print(game_board)
