function addStudent() {
    const name = document.getElementById('name').value.trim();
    const math = parseFloat(document.getElementById('math').value);
    const science = parseFloat(document.getElementById('science').value);
    const english = parseFloat(document.getElementById('english').value);

    if (!name || isNaN(math) || isNaN(science) || isNaN(english)) {
        alert("Please fill in all fields correctly!");
        return;
    }

    const average = ((math + science + english) / 3).toFixed(2);
    let grade = '';
    if (average >= 90) grade = 'A';
    else if (average >= 80) grade = 'B';
    else if (average >= 70) grade = 'C';
    else if (average >= 60) grade = 'D';
    else grade = 'F';

    // Insert into table
    const table = document.querySelector("#studentsTable tbody");
    const row = table.insertRow();
    row.innerHTML = `
        <td>${name}</td>
        <td>${math}</td>
        <td>${science}</td>
        <td>${english}</td>
        <td>${average}</td>
        <td>${grade}</td>
    `;

    // Clear form fields
    document.getElementById('name').value = '';
    document.getElementById('math').value = '';
    document.getElementById('science').value = '';
    document.getElementById('english').value = '';
}
