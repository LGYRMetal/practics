#-*- coding: utf-8 -*-

import os, glob
dirname = r'/usr/lib/python3.5'

allsizes = []
allpy = glob.glob(dirname + os.sep + '*.py')
for filename in allpy:
    filesize = os.path.getsize(filename)

