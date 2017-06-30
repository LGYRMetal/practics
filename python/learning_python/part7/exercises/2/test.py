#-*- coding: utf-8 -*-

class MyError(Exception):
    x = "my error!"

def oops():
    raise MyError("my error!")

def func():
    try:
        oops()
    except MyError as myerror:
        print("catch it!")
        print(myerror.x, 'x')
        print(myerror)
    else:
        print("catch nothing!")
