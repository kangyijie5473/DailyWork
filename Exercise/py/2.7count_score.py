#!/usr/bin/env python
# coding=utf-8
import xlrd
import sys
reload(sys)
#sys.setdefaultencoding('utf-8')
print sys.getdefaultencoding()
obj_score_str = input("you want to count score?:")
obj_score = int(obj_score_str)

data = xlrd.open_workbook("cet.xlsx")
table = data.sheets()[0]

count = 0

num_rows = table.nrows
for i in range(num_rows):
    if i == 0:
        continue
    li = table.row_values(i)
    uni_str = li[-3]
    score =int(uni_str) 
    if score == obj_score:
        count += 1
        print li[-6],li[-8]
print count
