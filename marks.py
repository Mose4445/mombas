import sqlite3

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

# Insert data into table
cursor.executemany("INSERT INTO students (name, math, science, english) VALUES (?, ?, ?, ?)", students)
conn.commit()

# Query to get student averages
cursor.execute("""
SELECT name, math, science, english,
       ROUND((math + science + english) / 3.0, 2) AS average
FROM students
ORDER BY average DESC
""")

# Fetch and print results
results = cursor.fetchall()
print("Name\t\tMath\tScience\tEnglish\tAverage")
print("-" * 50)
for row in results:
    print(f"{row[0]:<10}\t{row[1]}\t{row[2]}\t{row[3]}\t{row[4]}")

# Close connection
conn.close()
