months = [
    'jan',
    'feb',
    'mar',
    'apr',
    'may',
    'jun',
    'jul',
    'aug',
    'sep',
    'oct',
    'nov',
    'dec',
]
ends = ['st', 'nd', 'rd'] + 17 *['th'] + ['st', 'nd', 'rd'] + 7 * ['st']
year = raw_input('year: ')
month = raw_input("month: ")
day = raw_input("day: ")
month_number = int(month)
day_number = int(day)

month_name = months[month_number -1]
ordinal = day + ends[day_number -1]

print month_name + ' ' + ordinal + '.' +year


