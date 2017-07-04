#-*- coding: utf-8 -*-

# Build GUI with tkinter with buttons that change color and grow

import tkinter
import random

fontsize = 25
colors = ['red', 'green', 'blue', 'yellow', 'orange', 'white', 'cyan',
          'purple']

def reply(text):
    print(text)
    popup = tkinter.Toplevel()
    color = random.choice(colors)
    tkinter.Label(popup, text='Popup', bg='black', fg=color).pack()
    L.config(fg=color)

def timer():
    L.config(fg=random.choice(colors))
    win.after(250, timer)

def grow():
    global fontsize
    fontsize += 5
    L.config(font=('arial', fontsize, 'italic'))
    win.after(100, grow)

win = tkinter.Tk()
L = tkinter.Label(win, text='Spam', font=('arial', fontsize, 'italic'),
                  fg='yellow', bg='navy', relief=tkinter.RAISED)
L.pack(side=tkinter.TOP, expand=tkinter.YES, fill=tkinter.BOTH)
tkinter.Button(
        win, text='press', command=(lambda: reply('red'))
        ).pack(side=tkinter.BOTTOM, fill=tkinter.X)
tkinter.Button(
        win, text='timer', command=timer
        ).pack(side=tkinter.BOTTOM, fill=tkinter.X)
tkinter.Button(
        win, text='grow', command=grow
        ).pack(side=tkinter.BOTTOM, fill=tkinter.X)
win.mainloop()
