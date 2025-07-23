# Student Management System in Python

# Function to display menu
def display_menu():
    print("\n===== Student Management System =====")
    print("1. Add Student")
    print("2. View All Students")
    print("3. Search Student")
    print("4. Delete Student")
    print("5. Save & Exit")
    print("=====================================")

# Function to add a student
def add_student(students):
    name = input("Enter student name: ")
    age = input("Enter student age: ")
    grade = input("Enter student grade: ")
    
    # Append as a dictionary
    students.append({"name": name, "age": age, "grade": grade})
    print(f"✅ Student '{name}' added successfully!")

# Function to view all students
def view_students(students):
    if not students:
        print("No students found.")
    else:
        print("\n--- Student List ---")
        for i, student in enumerate(students, start=1):
            print(f"{i}. Name: {student['name']}, Age: {student['age']}, Grade: {student['grade']}")

# Function to search for a student
def search_student(students):
    keyword = input("Enter name to search: ").lower()
    found = False
    for student in students:
        if keyword in student['name'].lower():
            print(f"Found: {student['name']} | Age: {student['age']} | Grade: {student['grade']}")
            found = True
    if not found:
        print("❌ Student not found.")

# Function to delete a student
def delete_student(students):
    name = input("Enter the name of student to delete: ")
    for student in students:
        if student['name'].lower() == name.lower():
            students.remove(student)
            print(f"✅ Student '{name}' deleted.")
            return
    print("❌ Student not found.")

# Save students to file
def save_students(students, filename="students.txt"):
    with open(filename, "w") as file:
        for student in students:
            file.write(f"{student['name']},{student['age']},{student['grade']}\n")
    print("✅ Data saved successfully!")

# Load students from file
def load_students(filename="students.txt"):
    students = []
    try:
        with open(filename, "r") as file:
            for line in file:
                name, age, grade = line.strip().split(",")
                students.append({"name": name, "age": age, "grade": grade})
    except FileNotFoundError:
        pass
    return students

# Main Program
def main():
    students = load_students()
    
    while True:
        display_menu()
        choice = input("Enter choice (1-5): ")
        
        if choice == "1":
            add_student(students)
        elif choice == "2":
            view_students(students)
        elif choice == "3":
            search_student(students)
        elif choice == "4":
            delete_student(students)
        elif choice == "5":
            save_students(students)
            print("Goodbye!")
            break
        else:
            print("❌ Invalid choice. Try again.")

# Run program
if __name__ == "__main__":
    main()
