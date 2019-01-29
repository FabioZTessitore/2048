# board2048.py

# A Board for 2048 game

from tile2048 import Tile2048
from board import Board
import random

class Board2048(Board):
    def __init__(self, size):
        Board.__init__(self, size)

    def addRandomTile(self):
        index = random.choice(self.emptyPositions)
        # 10% -> 4
        # 90% -> 2
        tile = Tile2048(4 if random.randrange(100)<10 else 2)
        self.insertTile(index, tile)

    def rotate(self):
        q = []
        for i in range(self.size):
            q.append([])

        for col in range(self.size):
            for row in range(self.size-1, -1, -1):
                cellIndex = self.size*row + col
                q[col].append(self.getTile(cellIndex))

        self.positions = []
        for item in q:
            self.positions += item

    def unlockAllTiles(self):
        for tile in self.positions:
            if tile:
                tile.unlock()

    def tileUp(self):
        moved = 0

        for col in range(self.size):
            for row in range(self.size):
                r = row

                cell_source = row*self.size + col

                if self.getTile(cell_source) != None:
                    cell_target = self.size * (r-1) + col;

                    while r>0 and self.getTile(cell_target)==None:
                        self.moveTile(cell_source, cell_target)
                        r -= 1
                        cell_source = cell_target
                        cell_target = self.size*(r-1)+col
                        moved = 1

                    if r>0 and self.getTile(cell_target).get() and \
                            self.getTile(cell_target).get()==self.getTile(cell_source).get() and \
                            not self.getTile(cell_target).isLocked():
                                self.getTile(cell_target).double()
                                self.removeTile(cell_source)
                                moved = 1

        self.unlockAllTiles()
        self.updateEmptyPositions()

        return moved

    def tileLeft(self):
        self.rotate()
        moved = self.tileUp()
        self.rotate()
        self.rotate()
        self.rotate()

        self.unlockAllTiles()
        self.updateEmptyPositions()

        return moved

    def tileRight(self):
        self.rotate()
        self.rotate()
        self.rotate()
        moved = self.tileUp()
        self.rotate()

        self.unlockAllTiles()
        self.updateEmptyPositions()

        return moved

    def tileDown(self):
        self.rotate()
        self.rotate()
        moved = self.tileUp()
        self.rotate()
        self.rotate()

        self.unlockAllTiles()
        self.updateEmptyPositions()

        return moved

if __name__=='__main__':
    size = 3

    print("Creating a Board with a random Tile")
    game_board = Board2048(size)
    game_board.addRandomTile()
    print(game_board)

    print("\nCreating a Board")
    game_board = Board2048(size)
    for index in range(size*size):
        game_board.addRandomTile()
    print(game_board)
    print("\nRotating the Board")
    game_board.rotate()
    print(game_board)
