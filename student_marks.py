import csv
with open("students_marks.csv", "r") as file:
    data = file.read()
    print(data)
reader=csv.reader(file)
next(reader)
for row in reader:
    print(row[1])