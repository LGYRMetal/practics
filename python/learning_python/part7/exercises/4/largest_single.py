#-*- coding: utf-8 -*-

# Find the largest Python source file in a single directory

import os, glob
dirname = r'/usr/lib/python3.5'

allsizes = []
allpy = glob.glob(dirname + os.sep + '*.py')
for filename in allpy:
    filesize = os.path.getsize(filename)
    allsizes.append((filesize, filename))

allsizes.sort()
print(allsizes[:2])
print(allsizes[-2:])
