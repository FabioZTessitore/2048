# app.py

# il gioco 2048 nella versione python-tkinter

from tkinter import *
from tkinter import ttk
from tkinter import font

from board2048 import Board2048

class BoardSizeDialog(Toplevel):
    def __init__(self, parent, boardSize):
        self.parent = parent

        Toplevel.__init__(self, parent)
        self.protocol("WM_DELETE_WINDOW", parent.destroy)
        self.title('2048 - Dimensione della Board')
        mainframe = ttk.Frame(self, padding="10")
        mainframe.grid()

        ttk.Label(mainframe, text="Dimensione della Board:").grid(row=0, column=0)
        boardSizeSpin = Spinbox(mainframe, from_=2, to=15, textvariable=boardSize)
        boardSizeSpin.grid(row=1, column=0)
        ttk.Button(mainframe, text="Inizia a giocare", command=self.onStart).grid(sticky=(E, W))

        for child in mainframe.winfo_children():
            child.grid_configure(padx=5, pady=5)

    def onStart(self):
        self.parent.deiconify()
        self.parent.configure()
        self.destroy()


class App(Tk):
    def __init__(self):
        Tk.__init__(self)
        self.title("2048")
        self.mainframe = ttk.Frame(self, padding=10)
        self.mainframe.grid(row=0, column=0, sticky=(N, S, E, W))
        self.withdraw()

        self.boardSize = StringVar()
        BoardSizeDialog(self, self.boardSize)

        self.mainloop()

    def configure(self):
        boardSize = int(self.boardSize.get())
        self.board = Board2048(boardSize)
        self.board.addTile()
        self.board.addTile()
        self.tileLabels = []
        for row in range(boardSize):
            for col in range(boardSize):
                cellIndex = self.board.size * row + col
                tile = self.board.get(cellIndex)
                labelContent = StringVar()
                if tile:
                    labelContent.set(tile.get())
                else:
                    labelContent.set('')
                appFont = font.Font(family='Helvetica', size=16)
                label = ttk.Label(self.mainframe, textvariable=labelContent, width=10, font=appFont, anchor="center")
                label.grid(row=row, column=col, padx=5, pady=5, sticky=(N, S, E, W))
                self.tileLabels.append(labelContent)

        self.bind('<Key>', self.keyEventHandler)

    def keyEventHandler(self, event):
        moved = 0
        key = event.keycode
        if key==113:  # left
            moved = self.board.tileLeft()
        elif key==111:  # up
            moved = self.board.tileUp()
        elif key==114:
            moved = self.board.tileRight()
        elif key==116:
            moved = self.board.tileDown()

        if moved:
            self.board.addTile()
            self.updateLabelText()

    def updateLabelText(self):
        for index, label in enumerate(self.tileLabels):
            tile = self.board.get(index)
            if tile:
                label.set(tile.get())
            else:
                label.set('')


app = App()
