from tkinter import *
from tkinter.font import BOLD
import requests 
import json
import math

response = requests.get('http://localhost:3000/raw')
obj = json.loads(response.text)
def on_click(event):
    response = requests.get('http://localhost:3000/raw')
    obj = json.loads(response.text)
window = Tk()
window.title("Weather")
window.resizable(width=False, height=False)
c = Canvas(window, width=269, height=378, bg='white')
c.pack()
c.create_rectangle(0, 0, 269, 74,
                   fill='orange')
c.create_rectangle(0, 312, 269, 378,
                   fill='orange')
c.create_text(135, 19, 
              text="Симферополь",
              justify=CENTER, font=('Verdana', 13, BOLD))
c.create_text(135, 40, 
              text=obj[0]['Weather'].encode('l1').decode(),
              justify=CENTER, font=('Verdana', 13))
c.create_text(135, 190, 
              text=(str(round(obj[0]['Temperature']))+u"\u00b0C"),
              justify=CENTER, font=('Verdana', 60, BOLD))       
c.bind("<Button-1>", on_click)           
window.geometry('269x378')
window.mainloop()