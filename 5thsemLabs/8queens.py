import tkinter as tk

class NQueensSolver:
    def __init__(self, n):
        self.n = n
        self.board = [[0 for _ in range(n)] for _ in range(n)]
    
    def is_safe(self, row, col):
        for i in range(col):
            if self.board[row][i] == 1:
                return False
        for i, j in zip(range(row, -1, -1), range(col, -1, -1)):
            if self.board[i][j] == 1:
                return False
        for i, j in zip(range(row, self.n, 1), range(col, -1, -1)):
            if self.board[i][j] == 1:
                return False
        return True
    
    def solve(self, col=0):
        if col >= self.n:
            return True
        for i in range(self.n):
            if self.is_safe(i, col):
                self.board[i][col] = 1
                if self.solve(col + 1):
                    return True
                self.board[i][col] = 0
        return False

class ChessboardGUI:
    def __init__(self, root, n):
        self.root = root
        self.n = n
        self.square_size = 50
        self.canvas = tk.Canvas(self.root, width=n * self.square_size, height=n * self.square_size)
        self.canvas.pack()
        
    def draw_chessboard(self):
        for i in range(self.n):
            for j in range(self.n):
                color = "white" if (i + j) % 2 == 0 else "black"
                self.canvas.create_rectangle(j * self.square_size, i * self.square_size,
                                             (j + 1) * self.square_size, (i + 1) * self.square_size,
                                             fill=color)
    
    def draw_queens(self, queens_positions):
        for row, col in queens_positions:
            x_center = (col + 0.5) * self.square_size
            y_center = (row + 0.5) * self.square_size
            radius = self.square_size * 0.4
            self.canvas.create_oval(x_center - radius, y_center - radius,
                                    x_center + radius, y_center + radius,
                                    fill="red")

def solve_and_display_nqueens(n):
    solver = NQueensSolver(n)
    if solver.solve():
        root = tk.Tk()
        root.title(f"{n}-Queens")
        gui = ChessboardGUI(root, n)
        gui.draw_chessboard()
        queens_positions = [(i, col) for col, i in enumerate([row.index(1) for row in solver.board])]
        gui.draw_queens(queens_positions)
        root.mainloop()
    else:
        print(f"No solution found for {n}-Queens.")

# Example usage
n_queens = 8
solve_and_display_nqueens(n_queens)
