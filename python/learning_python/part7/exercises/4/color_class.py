#-*- coding: utf-8 -*-
# Similar to color.py, but use classes so each window has own state
# information

import tkinter
import random

class MyGui:
    """
    A GUI with buttons that change color and make the label grow
    """
    colors = ['blue', 'green', 'orange', 'red', 'brown', 'yellow']

    def __init__(self, parent, title='popup'):
        parent.title(title)
        self.growing = False
        self.fontsize = 10
        self.lab = tkinter.Label(parent, text='Gui1', fg='white', bg='navy')
        self.lab.pack(expand=tkinter.YES, fill=tkinter.BOTH)
        tkinter.Button(
                parent, text='Spam', command=self.reply
                ).pack(side=tkinter.LEFT)
        tkinter.Button(
                parent, text='Grow', command=self.grow
                ).pack(side=tkinter.LEFT)
        tkinter.Button(
                parent, text='Stop', command=self.stop
                ).pack(side=tkinter.LEFT)

    def reply(self):
        "change the button's color at random on Spam presses"
        self.fontsize += 5
        color = random.choice(self.colors)
        self.lab.config(bg=color,
                        font=('courier', self.fontsize, 'bold italic'))

    def grow(self):
        "start making the label grow on Grow presses"
        self.growing = True
        self.grower()

    def grower(self):
        if self.growing:
            color = random.choice(self.colors)
            self.fontsize += 5
            self.lab.config(bg=color,
                            font=('courier', self.fontsize, 'bold'))
            self.lab.after(500, self.grower)

    def stop(self):
        "stop the button growing on Stop presses"
        self.growing = False

class MySubGui(MyGui):
    colors = ['black', 'purple']

MyGui(tkinter.Tk(), 'main')
MyGui(tkinter.Toplevel())
MySubGui(tkinter.Toplevel())

tkinter.mainloop()
