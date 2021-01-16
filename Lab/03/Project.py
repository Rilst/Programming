from tkinter import *
import tkinter as tk
from PIL import Image, ImageTk
from random import randint
from collections import defaultdict
import random
import copy
 
tiles = {}
coordsFree = []
coordsBalls = []
coordsAll = []
BallsImg = {}
ActiveBallsImg = {}
SmallBalls = {}
Buffer = []
names = ["Aqua", "Blue", "Green", "Pink", "Red", "Violet", "Yellow"]
GameOver = False
Selected = False
SelectedBall = {}
GraphPath = {}
BuF =[]

Moveble = False

Score = 0

class Graph:
    def __init__(self, vertices):
        self.V = vertices

        self.graph = defaultdict(list)

    def addEdge(self, u, v):
        self.graph[u].append(v)

    def printAllPathsUtil(self, u, d, visited, path):
        global Moveble
        visited[list(self.graph.keys()).index(u)] = True
        path.append(u)

        if u == d:
            Moveble = True
            #print(path)

        else:
            for i in self.graph[u]:
                if visited[list(self.graph.keys()).index(i)] == False:
                    self.printAllPathsUtil(i, d, visited, path)
        path.pop()
        
    def printAllPaths(self, s, d):
        global GraphPath
        
        visited = [False] * (self.V)

        path = []
        
        self.printAllPathsUtil(s, d, visited, path)
        
        GraphPath.clear()


def CreateTile():
    global coordsFree
    global tiles
    for row in range(9):
        for col in range(9):
            tiles[repr([row, col])] = Label(root, image = tileImg, borderwidth=0)
            tiles[repr([row, col])].row = col
            tiles[repr([row, col])].col = row
            tiles[repr([row, col])].color = None
            tiles[repr([row, col])].bind("<Button-1>", SetActive)
            coordsFree.append([row, col])
            coordsAll.append([row, col])
    for i in coordsFree:
        tiles[repr(i)].place(x=68*i[0], y=68*i[1])

def CreateBallsImg():
    global BallsImg
    global ActiveBallsImg
    global names
    directory = ["./res/ball-aqua.png", "./res/ball-blue.png" , "./res/ball-green.png", "./res/ball-pink.png", "./res/ball-red.png", "./res/ball-violet.png", "./res/ball-yellow.png"]    
    for png in range(len(directory)):
        ball = Image.open(directory[png]).convert('RGBA')
        
        pic_size_same_as_tile = Image.new("RGBA", tileset.crop((1, 0, 67, 66)).size)
        pic_size_same_as_tile.paste(ball.crop((1, 0, 54, 54)), (6,6))
        ball_over_tile = Image.alpha_composite(tileset.crop((1, 0, 67, 66)), pic_size_same_as_tile)
        
        pic_size_same_as_ActTile = Image.new("RGBA", tileset.crop((1, 69, 67, 135)).size)
        pic_size_same_as_ActTile.paste(ball.crop((1, 0, 54, 54)), (6,6))
        ActBall_over_tile = Image.alpha_composite(tileset.crop((1, 69, 67, 135)), pic_size_same_as_ActTile)
        
        SmallBalls[names[png]] = ImageTk.PhotoImage(ball.crop((1, 191, 54, 224)))
        
        BallsImg[names[png]] = ImageTk.PhotoImage(ball_over_tile)
        ActiveBallsImg[names[png]] = ImageTk.PhotoImage(ActBall_over_tile)

def CreateBuffer():
    global smallball_1
    global smallball_2
    global smallball_3

    Buffer.clear()
    
    for i in range(3):
        color = random.choice(names)
        Buffer.append(color)
    c.create_text(743, 250, font="Verdana 15", text="Подсказка:", fill = "grey" )
    c.itemconfigure(smallball_1, image = SmallBalls[Buffer[0]])
    c.itemconfigure(smallball_2, image = SmallBalls[Buffer[1]])
    c.itemconfigure(smallball_3, image = SmallBalls[Buffer[2]])
    c.coords(smallball_1, 700, 290)
    c.coords(smallball_2, 700+40, 290)
    c.coords(smallball_3, 700+40*2, 290)
    
def SetOver():
        c.itemconfigure(gameover, image = gameimg)
        GameOver = True;

def SearchLines():
    buf = 0
    bufC = []
    for row in range(1, 9):
        for col in range(9):
            if tiles[repr([row-1, col])].color != None and tiles[repr([row-1, col])].color == tiles[repr([row, col])].color:
                buf += 1
                bufC.append([row-1, col])
            else:
                buf = 0
                bufC.clear()
    print(buf)
    print(bufC)
    
def SearchPath(start, end):
    global Moveble
    global coordsFree
    
    for i in coordsFree:
        if [i[0]-1, i[1]] in coordsFree:
            BuF.append(repr([i[0]-1, i[1]]))
        if [i[0]+1, i[1]] in coordsFree:
            BuF.append(repr([i[0]+1, i[1]]))
        if [i[0], i[1]-1] in coordsFree:
            BuF.append(repr([i[0], i[1]-1]))
        if [i[0], i[1]+1] in coordsFree:
            BuF.append(repr([i[0], i[1]+1]))
        if len(BuF) != 0:
            GraphPath[repr(i)] = list(BuF)
            BuF.clear()
    
    
    if [start[0]-1, start[1]] in coordsFree:
        BuF.append(repr([start[0]-1, start[1]]))
        if GraphPath.get(repr([start[0]-1, start[1]])) == None:
            GraphPath[repr([start[0]-1, start[1]])] = [repr(list([start[0], start[1]]))]
    if [start[0]+1, start[1]] in coordsFree:
        BuF.append(repr([start[0]+1, start[1]]))
        if GraphPath.get(repr([start[0]+1, start[1]])) == None:
            GraphPath[repr([start[0]+1, start[1]])] = [repr(list([start[0], start[1]]))]
    if [start[0], start[1]-1] in coordsFree:
        BuF.append(repr([start[0], start[1]-1]))
        if GraphPath.get(repr([start[0], start[1]-1])) == None:
            GraphPath[repr([start[0], start[1]-1])] = [repr(list([start[0], start[1]]))]
    if [start[0], start[1]+1] in coordsFree:
        BuF.append(repr([start[0], start[1]+1]))
        if GraphPath.get(repr([start[0], start[1]+1])) == None:
            GraphPath[repr([start[0], start[1]+1])] = [repr(list([start[0], start[1]]))]
    if len(BuF) != 0:
        GraphPath[repr([start[0], start[1]])] = list(BuF)
        BuF.clear()
            
    g = Graph(len(GraphPath.keys()))
    for i, v in GraphPath.items():
        for e in v:
            g.addEdge(i, e)

    s = repr(start)
    d = repr(end)
    
    #print(coordsFree)
    #print("=====================")
   # print(GraphPath)
    
    g.printAllPaths(s, d)
  
def SetActive(event):
    global ActiveBallsImg
    global tiles
    global Selected
    global SelectedBall
    global Moveble
    
    if Selected == False and ([event.widget.row, event.widget.col] in coordsBalls):
        tiles[repr([event.widget.row, event.widget.col])] = Label(root, image = ActiveBallsImg[event.widget.color], borderwidth=0)
        tiles[repr([event.widget.row, event.widget.col])].row = event.widget.row
        tiles[repr([event.widget.row, event.widget.col])].col = event.widget.col
        tiles[repr([event.widget.row, event.widget.col])].color = event.widget.color
        tiles[repr([event.widget.row, event.widget.col])].bind("<Button-1>", SetActive)
        tiles[repr([event.widget.row, event.widget.col])].place(x=68*event.widget.col, y=68*event.widget.row)
        Selected = True
        SelectedBall = {'row': event.widget.row, 'col': event.widget.col, 'color': event.widget.color}
    elif Selected == True and ([event.widget.row, event.widget.col] in coordsFree) and len(SelectedBall) != 0:
        SearchPath([SelectedBall['row'],SelectedBall['col']], [event.widget.row, event.widget.col])
        if Moveble == True:
            tiles[repr([SelectedBall['row'],SelectedBall['col']])] = Label(root, image = tileImg, borderwidth=0)
            tiles[repr([SelectedBall['row'],SelectedBall['col']])].row = SelectedBall['row']
            tiles[repr([SelectedBall['row'],SelectedBall['col']])].col = SelectedBall['col']
            tiles[repr([SelectedBall['row'],SelectedBall['col']])].color = None
            tiles[repr([SelectedBall['row'],SelectedBall['col']])].bind("<Button-1>", SetActive)
            tiles[repr([SelectedBall['row'],SelectedBall['col']])].place(x=68*SelectedBall['col'], y=68*SelectedBall['row'])
            coordsBalls.remove([SelectedBall['row'],SelectedBall['col']])
            coordsBalls.append([event.widget.row, event.widget.col])
            
   
            tiles[repr([event.widget.row, event.widget.col])] = Label(root, image = BallsImg[SelectedBall['color']], borderwidth=0)
            tiles[repr([event.widget.row, event.widget.col])].row = event.widget.row
            tiles[repr([event.widget.row, event.widget.col])].col = event.widget.col
            tiles[repr([event.widget.row, event.widget.col])].color = SelectedBall['color']
            tiles[repr([event.widget.row, event.widget.col])].bind("<Button-1>", SetActive)
            tiles[repr([event.widget.row, event.widget.col])].place(x=68*event.widget.col, y=68*event.widget.row)
            coordsFree.remove([event.widget.row, event.widget.col])
            coordsFree.append([SelectedBall['row'],SelectedBall['col']])
                
            Selected = False
            Moveble = False
            SelectedBall.clear()
            SearchLines()
            CreateBall()
            
        elif Moveble == False:
            tiles[repr([SelectedBall['row'],SelectedBall['col']])] = Label(root, image = BallsImg[SelectedBall['color']], borderwidth=0)
            tiles[repr([SelectedBall['row'],SelectedBall['col']])].row = SelectedBall['row']
            tiles[repr([SelectedBall['row'],SelectedBall['col']])].col = SelectedBall['col']
            tiles[repr([SelectedBall['row'],SelectedBall['col']])].color = SelectedBall['color']
            tiles[repr([SelectedBall['row'],SelectedBall['col']])].bind("<Button-1>", SetActive)
            tiles[repr([SelectedBall['row'],SelectedBall['col']])].place(x=68*SelectedBall['col'], y=68*SelectedBall['row'])
            Selected = False
            SelectedBall.clear() 
    elif Selected == True and ([event.widget.row, event.widget.col] in coordsBalls) and ([SelectedBall['row'],SelectedBall['col']] == [event.widget.row, event.widget.col]):
        tiles[repr([event.widget.row, event.widget.col])] = Label(root, image = BallsImg[event.widget.color], borderwidth=0)
        tiles[repr([event.widget.row, event.widget.col])].row = event.widget.row
        tiles[repr([event.widget.row, event.widget.col])].col = event.widget.col
        tiles[repr([event.widget.row, event.widget.col])].color = event.widget.color
        tiles[repr([event.widget.row, event.widget.col])].bind("<Button-1>", SetActive)
        tiles[repr([event.widget.row, event.widget.col])].place(x=68*event.widget.col, y=68*event.widget.row)
        Selected = False
        SelectedBall.clear()
        
    elif Selected == True and ([event.widget.row, event.widget.col] in coordsBalls) and ([SelectedBall['row'],SelectedBall['col']] != [event.widget.row, event.widget.col]):
        tiles[repr([SelectedBall['row'],SelectedBall['col']])] = Label(root, image = BallsImg[SelectedBall['color']], borderwidth=0)
        tiles[repr([SelectedBall['row'],SelectedBall['col']])].row = SelectedBall['row']
        tiles[repr([SelectedBall['row'],SelectedBall['col']])].col = SelectedBall['col']
        tiles[repr([SelectedBall['row'],SelectedBall['col']])].color = SelectedBall['color']
        tiles[repr([SelectedBall['row'],SelectedBall['col']])].bind("<Button-1>", SetActive)
        tiles[repr([SelectedBall['row'],SelectedBall['col']])].place(x=68*SelectedBall['col'], y=68*SelectedBall['row'])
        SelectedBall.clear()
        
        tiles[repr([event.widget.row, event.widget.col])] = Label(root, image = ActiveBallsImg[event.widget.color], borderwidth=0)
        tiles[repr([event.widget.row, event.widget.col])].row = event.widget.row
        tiles[repr([event.widget.row, event.widget.col])].col = event.widget.col
        tiles[repr([event.widget.row, event.widget.col])].color = event.widget.color
        tiles[repr([event.widget.row, event.widget.col])].bind("<Button-1>", SetActive)
        tiles[repr([event.widget.row, event.widget.col])].place(x=68*event.widget.col, y=68*event.widget.row)
        SelectedBall = {'row': event.widget.row, 'col': event.widget.col, 'color': event.widget.color}
        Selected = True
        
    #print(Selected)
    #print(SelectedBall)
    #CreateBall()
    if len(coordsFree) == 0:
        SetOver()
        
    #print(len(coordsFree))
    
def CreateBall():
    global balls
    global tiles
    global BallsImg
    global ActiveBallsImg
    
    if len(coordsFree) == 0:
        SetOver()
    else:    
        for R in range(3):
            coord = random.choice(coordsFree)
            
            row = coord[0]
            col = coord[1]
        
               
            tiles[repr([row, col])] = Label(root, image = BallsImg[Buffer[R]], borderwidth=0)
            tiles[repr([row, col])].bind("<Button-1>", SetActive)
            tiles[repr([row, col])].row = row
            tiles[repr([row, col])].col = col
            tiles[repr([row, col])].color = Buffer[R]
            tiles[repr([row, col])].place(x=68*col, y=68*row)
            coordsFree.remove([row, col])
            coordsBalls.append([row, col])
        CreateBuffer()
    if len(coordsFree) == 0:
        SetOver()

def SetNewGame():
    coordsFree.clear()
    coordsBalls.clear()
    CreateTile()
    CreateBall()
    c.itemconfigure(gameover, image = '')
    GameOver = False;
    Moveble = False;
    #print(len(coordsFree))


root = Tk()

root.geometry('900x610')
root.resizable(False, False)

bgr = Image.open("res/page-bgr.png").convert('RGBA')
bgrImg = Image.new('RGBA', (128*15, 128*15))

bgrImg.paste(bgr, (0,0))
for r in range(15):
    for d in range(15):
        bgrImg.paste(bgr, (128*r,128*d))
            
game = Image.open("res/game_over.png").convert('RGBA')
gameimg = ImageTk.PhotoImage(game)

tileset = Image.open("res/cell-bgr.png").convert('RGBA')
tileImg = ImageTk.PhotoImage(tileset.crop((1, 0, 67, 66)))

c = Canvas(width=900, height=610)
bg = ImageTk.PhotoImage(bgrImg)
c.create_image(0, 0, image=bg)

gameover = c.create_image(0, 0, image = '')
c.coords(gameover, 750, 430)

CreateTile()
CreateBallsImg()

smallball_1 = c.create_image(1, 1, image = '')
smallball_2 = c.create_image(1, 1, image = '')
smallball_3 = c.create_image(1, 1, image = '')


CreateBuffer()
CreateBall()

gethod = Button(text="Сделать ход", background="#555", foreground="#ccc", padx="16", pady="3", font="14", command = CreateBall)
gethod.place(x=680, y=170)

newgame = Button(text="Новая игра", background="#555", foreground="#ccc", padx="16", pady="3", font="14", command = SetNewGame)
newgame.place(x=680, y=330)


c.place(x=-2, y=-2)


#print(len(coordsFree))

root.mainloop()