/*
KIIT OOP Lab (21.09.2022): Question 2
Q) WAP to input name, roll number, and marks in 5 subjects for n number of students.
Write functions to :-
    a. Find total marks and percentage of total n students
    b. Display details of a student with a given roll number.
    c. Display the details for all the students having percentage in a given range.
    d. Sort the array in ascending order of marks

*/

#include <iostream>
using namespace std;

int noOfStudents; // global declaration

// structure defination of a Student
typedef struct {
    string name;
    int roll;
    float marks[5]; // marks of 5 subjects out of 100
    float total;
    float percentage;
}Student;

void DisplayDetails(Student s)
{
    // Display details of this student
    cout << "\nStudent '" << s.name << "' has roll: " << s.roll;
    cout << "\nMarks for each subject :";
    for (int j=0; j<5; j++){
        cout << " " << s.marks[j];
    }
    cout << "\n";
}

// function to print total marks and percentage of a student
void Part_A(Student s[]){
    for (int i=0; i<noOfStudents; i++){
        float total = 0; // total marks
        for (int j=0; j<5; j++){
            total += s[i].marks[j];
        }
        float percentage = ((total*100)/500);
        s[i].total = total;
        s[i].percentage = percentage;
        cout << "\nTotal marks for Student : " << s[i].total << " is " << total;
        cout << "\nPercentage is : " << s[i].percentage << endl;
    } 
}

// function to display details of a student with a given roll number
void Part_B(Student s[], int roll){
    bool found = false;
    for (int i=0; i<noOfStudents; i++){
        if (s[i].roll == roll){
            // Display details of this student
            DisplayDetails(s[i]);
            found = true;
            break;
        }
    }
    if (found==false) cout << "No match for any student with roll : " << roll;
}

// function to display the details for all the students having percentage in a given range.
void Part_C(Student s[], float p_start, float p_end){
    for (int i=0; i<noOfStudents; i++){

        // if the student's percentage is in range
        if (s[i].percentage >= p_start && s[i].percentage <= p_end){
            DisplayDetails(s[i]);
        }
    }
}

// function to sort students in ascending order of marks
void Part_D(Student s[]){
    // Selection sorting
    for (int i=0; i<noOfStudents-1; i++){
        for (int j=i+1; j<noOfStudents; j++){
            // swapping each value
            if (s[i].total > s[j].total) {

                // swapping name
                string temp_str;
                temp_str = s[i].name;
                s[i].name = s[j].name;
                s[j].name = temp_str;

                // swapping roll
                int temp_i;
                temp_i = s[i].roll;
                s[i].roll = s[j].roll;
                s[j].roll = temp_i;

                // swapping marks
                float temp_f;
                for (int k=0; k<noOfStudents; k++){
                    temp_f = s[i].marks[k];
                    s[i].marks[k] = s[j].marks[k];
                    s[j].marks[k] = temp_f;
                }

                // swapping total
                temp_f = s[i].total;
                s[i].total = s[j].total;
                s[j].total = temp_f;

                // swapping percentage
                temp_f = s[i].percentage;
                s[i].percentage = s[j].percentage;
                s[j].percentage = temp_f;
            }
        }
    }

    // Displaying details of all students after sorting
    for (int i=0; i<noOfStudents; i++){
        DisplayDetails(s[i]);
    }
}

// Driver Code Starts here
int main (){
    
    // Getting the number of students
    cout << "\nHow many students : ";
    cin >> noOfStudents;
    
    // Getting all the details for all students
    Student s[noOfStudents];
    for (int i=0; i<noOfStudents; i++){
        cout << "\n----- For student " << i+1 << " -----\n";
        cout << "Name : ";
        getline(cin >> ws, s[i].name); // for string input 
        cout << "Roll no. : ";
        cin >> s[i].roll;
        cout << "Enter marks for the subjects (Maths, Physics, Chemistry, Biology, English) respectively :\n";
        for (int j=0; j<5; j++){
            cin >> s[i].marks[j]; 
        }
    }
    cout << "----------------------------\n";
    
    // a. Find total marks and percentage of total n students
    Part_A(s);
    cout << "----------------------------\n";
    
    // b. Display details of a student with a given roll number.
    int whichRoll;
    cout << "\nWhich roll number do you want to check ? - ";
    cin >> whichRoll;
    Part_B(s, whichRoll);
    cout << "----------------------------\n";

    // c. Display the details for all the students having percentage in a given range.
    cout << "\n\nEnter percentage range (0-100) - ";
    float p_start, p_end;
    cout << "\nRange Start : ";
    cin >> p_start;
    cout << "Range end : ";
    cin >> p_end;
    Part_C (s, p_start, p_end);
    cout << "----------------------------\n";

    // d. Sort the array in ascending order of marks
    cout << "After sorting total marks for all students in ascending order :\n";
    Part_D(s);
    cout << "\n----------------------------\n";

    return 0;
}

