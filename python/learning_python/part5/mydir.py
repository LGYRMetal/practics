"""
mydir.py: a module that lists the namespaces of other modules
"""

def printSep(sepstr, seplen=60, sepchr='-'):
    sepline = sepchr * seplen
    print(sepline)
    print(sepstr)
    print(sepline)

def listing(module, verbose=True):
    if verbose:
        sepstr = 'name: {0}, file: {1}'.format(module.__name__,
                module.__file__)
        printSep(sepstr)

    count = 0
    for attr in module.__dict__:    # Scan namespace keys
        print('{0:02d}) {1}'.format(count, attr), end = ' ')
        if attr.startswith('__'):
            print('<built-in name>')    # Skip __file__, etc.
        else:
            print(getattr(module, attr))    # Same as .__dict__[attr]
        count += 1

    if verbose:
        sepstr = '{0} has {1} names'.format(module.__name__, count)
        printSep(sepstr)

if __name__ == '__main__':
    import mydir
    listing(mydir)
