# board.py

# una generica scacchiera

from tile import Tile

class Board:
    def __init__(self, size):
        if type(size)!=int or size<=0:
            raise ValueError('Board.__init__: size must be a positive integer')

        self.size = size
        self.cells = []
        self.freePos = []

        for cellIndex in range(size*size):
            self.cells.append(None)
            self.freePos.append(cellIndex)

    def set(self, cellIndex, tile):
        if self.cells[cellIndex] and tile:
            raise ValueError('Board.set: tentativo di impostare una Tile su posizione non libera')

        self.cells[cellIndex] = tile
        self.updateFreePos()

    def get(self, cellIndex):
        return self.cells[cellIndex]

    def updateFreePos(self):
        self.freePos = []
        for cellIndex in range(self.size*self.size):
            if self.cells[cellIndex]==None:
                self.freePos.append(cellIndex)

    def someEmptyCell(self):
        return len(self.freePos)>0

    def moveTile(self, cell_src, cell_dst):
        if self.cells[cell_dst]!=None:
            raise ValueError('Board.moveTile: tentativo di accedere ad una cella non vuota')

        self.set(cell_dst, self.get(cell_src))
        self.set(cell_src, None)

        self.updateFreePos()

    def __str__(self):
        freepos_length = len(self.freePos)

        s = "Dimensione Board: " + str(self.size)
        s += "\nNumero di celle libere (mediante freePos): " + str(freepos_length)
        s += "\nCi sono celle libere? "
        if self.someEmptyCell():
            s += "si"
        else:
            s += "no"
        s += "\nIndici celle libere:\n"
        s += str(self.freePos)
        s += "\nDump celle:\n"
        s += str(self.cells)

        return s


if __name__=='__main__':
    size = 4
    game_board = Board(size)
    for index in range(size*size):
        t = Tile(index+1)
        game_board.set(index, t)
    print(game_board)
    del game_board

    game_board = Board(size)
    t = Tile(42)
    game_board.set(0, t)
    print(game_board)
    print("move a tile")
    game_board.moveTile(0, 1)
    print(game_board)
