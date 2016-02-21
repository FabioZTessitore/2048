# board2048.py

# la scacchiera del gioco 2048

from tile2048 import Tile2048
from board import Board
import random

class Board2048(Board):
    def __init__(self, size):
        Board.__init__(self, size)

    def addTile(self):
        cellIndex = random.choice(self.freePos)
        tile = Tile2048(4 if random.randrange(100)<10 else 2)
        self.set(cellIndex, tile)

    def rotate(self):
        q = []
        for i in range(self.size):
            q.append([])

        for col in range(self.size):
            for row in range(self.size-1, -1, -1):
                cellIndex = self.size*row + col
                q[col].append(self.get(cellIndex))

        self.cells = []
        for item in q:
            self.cells += item

    def resetGrow(self):
        for i in range(self.size*self.size):
            tile = self.get(i)
            if tile:
                tile.resetCanGrow()

    def tileUp(self):
        moved = 0

        for col in range(self.size):
            for row in range(self.size):
                r = row

                cell_source = row*self.size + col

                if self.get(cell_source)!=None:
                    cell_target = self.size * (r-1) + col;

                    while r>0 and self.get(cell_target)==None:
                        self.moveTile(cell_source, cell_target)
                        r -= 1
                        cell_source = cell_target
                        cell_target = self.size*(r-1)+col
                        moved = 1

                    if r>0 and self.get(cell_target).get() and \
                            self.get(cell_target).get()==self.get(cell_source).get() and \
                            self.get(cell_target).canGrow():
                                self.get(cell_target).doubleMe()
                                self.set(cell_source, None)
                                moved = 1

        self.resetGrow()
        self.updateFreePos()

        return moved

    def tileLeft(self):
        self.rotate()
        moved = self.tileUp()
        self.rotate()
        self.rotate()
        self.rotate()

        self.resetGrow()
        self.updateFreePos()

        return moved

    def tileRight(self):
        self.rotate()
        self.rotate()
        self.rotate()
        moved = self.tileUp()
        self.rotate()

        self.resetGrow()
        self.updateFreePos()

        return moved

    def tileDown(self):
        self.rotate()
        self.rotate()
        moved = self.tileUp()
        self.rotate()
        self.rotate()

        self.resetGrow()
        self.updateFreePos()

        return moved

if __name__=='__main__':
    size = 4
    game_board = Board2048(size)
    game_board.addTile()
    print(game_board)
    del game_board

    game_board = Board2048(size)
    for index in range(size*size):
        t = Tile2048(index+1)
        game_board.set(index, t)
    print(game_board)
    print("rotate")
    game_board.rotate()
    print(game_board)
