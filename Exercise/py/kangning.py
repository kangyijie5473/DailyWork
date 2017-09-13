#!/usr/bin/env python
# coding=utf-8
import xlrd
import xlwt
import sys
reload(sys)
#sys.setdefaultencoding('utf-8')

data = xlrd.open_workbook("xupt.xls")
table = data.sheets()[0]

birthday_list = []
nama_list = []
ID_list = []
num_rows = table.nrows
for i in range(num_rows):
    if i < 3:
        continue
    li = table.row_values(i)
    ID_num = li[6]
    name = li[4]
    if ID_num == '***': #obj 
    	break
    birthday = ID_num[6:10] + '-' + ID_num[10:12] + '-' + ID_num[12:14]
    birthday_list.append(birthday)
    nama_list.append(name)
    ID_list.append(ID_num)
    print name+birthday
 
xls = xlwt.Workbook()
sheet = xls.add_sheet('sample')
for row  in range(1, 233):
	value = birthday_list[row -1]
	name = nama_list[row - 1]
	ID = ID_list[row - 1]
	sheet.write(row, 0, name)
	sheet.write(row, 2, ID)
	sheet.write(row, 3, value)
xls.save('sample.xls')


