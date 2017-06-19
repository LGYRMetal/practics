#-*- coding: utf-8 -*-
"""
version 1:
    open file two times
"""

def countLines(filename):
    with open(filename) as myfile:
        lines = len(myfile.readlines())
    return lines

def countChars(filename):
    with open(filename) as myfile:
        chars = len(myfile.read())
    return chars

def test(filename):
    print('{0}: has {1} lines, and {2} charaters.'.format(
        filename,
        countLines(filename),
        countChars(filename)))
