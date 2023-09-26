import tkinter as tk
import time

class VacuumWorldSimulation:
    def __init__(self, root):
        self.root = root
        self.root.title("Vacuum World Simulation")
        
        self.canvas = tk.Canvas(root, width=400, height=200)
        self.canvas.pack()
        
        self.room_a = self.canvas.create_rectangle(50, 50, 200, 150, fill="white")
        self.room_b = self.canvas.create_rectangle(200, 50, 350, 150, fill="white")
        
        self.robot = self.canvas.create_oval(75, 75, 125, 125, fill="blue")
        
        self.dirt_a = None
        self.dirt_b = None
        
        self.current_location = "A"
        self.create_dirt()
        
    def create_dirt(self):
        self.dirt_a = self.canvas.create_oval(90, 90, 110, 110, fill="brown")
        self.dirt_b = self.canvas.create_oval(240, 90, 260, 110, fill="brown")
    
    def clean_dirt(self):
        if self.current_location == "A":
            self.canvas.delete(self.dirt_a)
        else:
            self.canvas.delete(self.dirt_b)
    
    def move(self):
        if self.current_location == "A":
            self.current_location = "B"
            self.canvas.move(self.robot, 150, 0)
        else:
            self.current_location = "A"
            self.canvas.move(self.robot, -150, 0)
    
    def vacuum(self):
        self.clean_dirt()
    
    def simulate(self):
        while True:
            time.sleep(1)
            self.vacuum()
            time.sleep(1)
            self.move()
            self.create_dirt()
            self.root.update()

if __name__ == "__main__":
    root = tk.Tk()
    simulation = VacuumWorldSimulation(root)
    simulation.simulate()
    root.mainloop()
