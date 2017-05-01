#!/usr/bin/env python
# coding=utf-8
import xlrd
workbook = xlrd.open_workbook('cet.xlsx')
worksheets = workbook.sheets()[0]
num_rows = worksheets.nrows
count = 0
#print count
for i in range(num_rows):
    if i == 1 :
        continue
    li = worksheets.row_values(i)
    score_str = li[-3]
    score_num = score_str.encode('utf-8')
    print int(str(score_num))
    if score_str > 425:
        count += 1
        print count
    else:
        continue
print '%d人中过线%d人' % (num_rows,count)

