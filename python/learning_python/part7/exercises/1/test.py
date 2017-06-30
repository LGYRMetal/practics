#-*- coding: utf-8 -*-

def oops():
    raise IndexError

def func():
    try:
        oops()
    except IndexError:
        print("catch it!")
