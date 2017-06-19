#-*- coding: utf-8 -*-
"""
version 2:
    open file one time
"""

def countLines(fd):
    return len(fd.readlines())

def countChars(fd):
    return len(fd.read())

def test(filename):
    with open(filename) as myfile:
        lines = countLines(myfile)
        myfile.seek(0)
        chars = countChars(myfile)

    print('{0}: has {1} lines, and {2} charaters.'.format(filename,
                                                          lines,
                                                          chars))

if __name__ == '__main__':
    test('mymod.py')
