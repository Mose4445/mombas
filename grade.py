import sqlite3
import csv

# Connect to SQLite (in-memory database)
conn = sqlite3.connect(":memory:")
cursor = conn.cursor()

# Create students table
cursor.execute("""
CREATE TABLE students (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    name TEXT,
    math INTEGER,
    science INTEGER,
    english INTEGER
)
""")

# Student data
students = [
    ("Alice", 85, 90, 88),
    ("Bob", 78, 82, 79),
    ("Charlie", 92, 85, 90),
    ("Diana", 88, 88, 85),
    ("Ethan", 76, 79, 80),
    ("Fiona", 95, 92, 94),
    ("George", 80, 81, 83),
    ("Hannah", 89, 87, 86),
    ("Ian", 84, 86, 87),
    ("Julia", 91, 93, 89)
]

# Insert data into the table
cursor.executemany("INSERT INTO students (name, math, science, english) VALUES (?, ?, ?, ?)", students)
conn.commit()

# Query results with average calculation
cursor.execute("""
SELECT name, math, science, english,
       ROUND((math + science + english) / 3.0, 2) AS average
FROM students
ORDER BY average DESC
""")
results = cursor.fetchall()

# Function to assign grades
def get_grade(avg):
    if avg >= 90:
        return "A"
    elif avg >= 80:
        return "B"
    elif avg >= 70:
        return "C"
    elif avg >= 60:
        return "D"
    else:
        return "F"

# Add Grade to results
results_with_grades = [(name, math, science, english, avg, get_grade(avg)) for name, math, science, english, avg in results]

# Print a neat table
print("Name\t\tMath\tScience\tEnglish\tAverage\tGrade")
print("-" * 60)
for row in results_with_grades:
    print(f"{row[0]:<10}\t{row[1]}\t{row[2]}\t{row[3]}\t{row[4]}\t{row[5]}")


