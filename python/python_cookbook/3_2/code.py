#!/usr/bin/python3
t = (1, 2, 3)

first, *last = t

print(t)
print(first)
print(last)

print('========================================')

records = [
    ('foo', 1, 2),
    ('bar', 'hello'),
    ('foo', 3, 4),
] // note

def do_foo(x, y):
    print('foo', x, y)

def do_bar(s):
    print('bar', s)

for tag, *args in records:
    if tag == 'foo':
        do_foo(*args)
    elif tag == 'bar':
        do_bar(*args)

a = {

}
