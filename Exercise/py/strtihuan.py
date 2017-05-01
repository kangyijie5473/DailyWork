#!/usr/bin/env python
# coding=utf-8
strings = ['hello','hellowo', 'asd','bbbh']

index = 0

for str in strings:
    if 'asd' in str:
        strings[index] = 'bsd'
    index += 1



'''
for string in strings:
    if 'as' in string:
        index = strings.index(string)
        strings[index] = '[world]'

'''

#for i in strings:
#    print i
print strings
