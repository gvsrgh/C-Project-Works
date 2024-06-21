# Attendance Calculator Program

## Overview
This C program calculates and manages student attendance, including:
- Total attendance
- Attendance percentage
- Storing and accessing attendance data from files

## Author
G. Venkata Sai Ram

## Features
1. **Update Attendance**: Update the number of classes held and attended.
2. **View Attendance Percentage**: Calculate and display the percentage of attendance.
3. **View Detailed Attendance**: Display detailed attendance information.
4. **Reset Attendance**: Reset attendance data to zero.

## Files Used
- `total_classes.txt`: Stores the total number of classes held.
- `total_attended.txt`: Stores the total number of classes attended.
- `extra_classes.txt`: Stores the number of extra classes held.
- `extra_attended.txt`: Stores the number of extra classes attended.

## How to Run the Program
1. **Compile the Program**: 
   ```sh
   gcc attendance_calculator.c -o attendance_calculator
   ```
2. **Run the Program**: 
   ```sh
   ./attendance_calculator
   ```

## Program Flow
1. The program first checks if the required files (`total_classes.txt`, `total_attended.txt`, `extra_classes.txt`, `extra_attended.txt`) exist. If not, it creates them with initial values set to zero.
2. The main menu is displayed with options to update attendance, view attendance percentage, view detailed attendance, reset attendance, or exit the program.

## Menu Options

### 1. Update Attendance
- Prompt the user to enter new values for:
  - Total classes held
  - Total classes attended
  - Extra classes held
  - Extra classes attended
- Update the corresponding files with the new values.

### 2. View Attendance Percentage
- Calculate and display the percentage of total and extra classes attended.
- Provide feedback if the attendance is below or above 75%.

### 3. View Detailed Attendance
- Display detailed information including the total number of classes and extra classes held and attended.
- Calculate and display the percentage of attendance for both total and extra classes.
- Provide feedback if the attendance is below or above 75%.

### 4. Reset Attendance
- Backup the current attendance data to separate files.
- Reset the attendance data files to zero.

### 5. Exit
- Exit the program with a thank you message.

## Code Explanation

### Function Definitions

1. **`void createFiles()`**: Creates the necessary files with initial values set to zero if they don't exist.

2. **`void totalClasses(int updated_total_classes)`**: Updates the total number of classes held.

3. **`void totalAttended(int updated_total_attended)`**: Updates the total number of classes attended.

4. **`void extraClasses(int updated_extra_classes)`**: Updates the number of extra classes held.

5. **`void extraAttended(int updated_extra_attended)`**: Updates the number of extra classes attended.

6. **`float calculateTotalAttendance()`**: Calculates and returns the total attendance percentage.

7. **`float calculateExtraAttendance()`**: Calculates and returns the extra attendance percentage.

8. **`void displayDetailedAttendance()`**: Displays detailed attendance information.

9. **`void resetAttendance()`**: Resets attendance data to zero and backs up the current data.

## Usage Example
```sh
$ ./attendance_calculator
--------------------Attendance Calculator--------------------
1. Update Attendance
2. View Attendance Percentage
3. View Detailed Attendance
4. Reset Attendance
5. Exit
--------------------------------------------------------------
Enter your choice: 1
Enter new total classes held: 10
Enter new total classes attended: 8
Enter new extra classes held: 2
Enter new extra classes attended: 1
Attendance updated successfully
...
```

## Notes
- Ensure that the program has the necessary permissions to read/write files in the directory.
- Handle the file operations carefully to prevent data corruption.
