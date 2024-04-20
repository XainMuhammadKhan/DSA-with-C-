#include<iostream>
#include<cstdlib>
using namespace std;

struct Student {
    int studentID;
    Student* next;
};

struct Course {
    int courseID;
    Student* studStart;
    Course* next;
};

Course* head = NULL;

// Search Course Function
bool searchCourse (int ID){
    if (head == NULL){
        return false;
    }
    Course* curr = head;
    while (curr != NULL){
        if (curr->courseID == ID){
            return true;
        }
        curr = curr->next;
    }
    if (curr  == NULL){
        return false;
    }
}

// Add course function
void addCourse (int ID){
    if (searchCourse(ID)){
        cout << "Course ID already Exists in the List !!! " << endl;
        return;
    }
    Course* ptr = (Course*)malloc(sizeof(Course));
    ptr->courseID = ID;
    ptr->studStart =  NULL;
    ptr->next = NULL;
    if (head == NULL){
        head = ptr;
        return;
    }
    Course* curr = head;
    while (curr->next != NULL){
        curr = curr->next;
    }
    curr->next = ptr;
}

// Delete Course Function
void delCourse (int ID){
    if (head == NULL){
        cout << "List is Empty "<< endl;
        return;
    }
    Course* curr = head;
    if (ID == curr->courseID){
        head = head->next;
        free(curr);
        cout << "Deleted successfully  " << endl;
        return;
    }
    Course* prev = head;
    curr = prev->next;
    while(curr != NULL){
        if (curr->courseID == ID){
            prev->next = curr->next;
            free(curr);
            cout << "Deleted successfully  " << endl;
            break;
        }
        prev = prev->next;
        curr = curr->next;
    }
    if (curr == NULL){
        cout << "Course Not found in the List " << endl;
    }
}

void printCourseList (){
    if (head == NULL){
        cout << "Course List is Empty "<< endl;
        return;
    }
    if (head->next == NULL){
        cout << "course ID is " << head->courseID << endl;
        return;
    }
    Course* curr = head;
    while (curr != NULL){
        cout << "course ID is " << curr->courseID << endl;
        curr = curr->next;
    }
}

// Search student in course extra function
bool searchStudentFromCourse (int courseID, int studentID){
    if (head->courseID == courseID){
        Student* currStud = head->studStart;
        while (currStud != NULL){
            if (currStud->studentID == studentID){
                return true;
            }
            currStud = currStud->next;
        }
        return false;
    }
    Course* currCourse = head->next;
    while (currCourse != NULL){
        if (currCourse->courseID == courseID){
            Student* currStud = currCourse->studStart;
            while (currStud != NULL){
                if (currStud->studentID == studentID){
                    return true;
                }
                currStud = currStud->next;
            }
            return false;
        }
        currCourse = currCourse->next;
    }
}

void addStudToCourse (int studentID, int courseID){
    if (searchStudentFromCourse(courseID, studentID)){
        cout << "Student already enroll in this course !!!" << endl;
        return;
    }
    Course* curr = head;
    while (curr != NULL){
        if (curr->courseID == courseID){
            break; 
        }
        curr = curr->next;
    }
    Student* ptr = (Student*)malloc(sizeof(Student));
    ptr->studentID = studentID;
    ptr->next = NULL;
    if (curr->studStart == NULL){
        curr->studStart = ptr;
        return;
    }
    Student* currStud = curr->studStart;
            while (currStud->next != NULL){
                currStud = currStud->next;
            }
            currStud->next = ptr;  
}

// Delete Student from Course
void delStudFromCourse (int studentID, int courseID){
    Course* currCourse = head;
    while (currCourse != NULL){
        if (currCourse->courseID == courseID) break;
        currCourse = currCourse->next;
    }
    if (currCourse->studStart == NULL){
        cout << "0 students enroll in this course " << endl;
        return;
    }
    Student* currStud = currCourse->studStart;
    if (studentID == currStud->studentID){
        currCourse->studStart = currCourse->studStart->next;
        free(currStud);
        cout << "Deleted successfully  " << endl;
        return;
    }
    Student* prevStud = currCourse->studStart;
    currStud = prevStud->next;
    while(currStud != NULL){
        if (currStud->studentID == studentID){
            prevStud->next = currStud->next;
            free(currStud);
            cout << "Deleted successfully  " << endl;
            return;
        }
        prevStud = prevStud->next;
        currStud = currStud->next;
    }
}

// Delete a Student
void delStudent (int studentID){
    if (head == NULL){
        cout << "Course List is Empty " << endl;
        return;
    }
    Course* currCourse = head;
    while (currCourse != NULL){
        Student* prevStud = NULL;
        Student* currStud = currCourse->studStart;
        if (currStud != NULL){
            if (currStud->studentID == studentID){
                currCourse->studStart = currStud->next;
                free(currStud);
                cout << "Delete student in course no " << currCourse->courseID << endl;
                currCourse = currCourse->next;
                continue;
            }
            prevStud = currStud;
            currStud = currStud->next;
            while (currStud != NULL){
                if (currStud->studentID == studentID){
                    prevStud->next = currStud->next;
                    free(currStud);
                    cout << "Delete student in course no " << currCourse->courseID << endl;
                    break;
                }    
                prevStud = currStud;
                currStud = currStud->next;
            }
        }
        currCourse = currCourse->next;
    }

}

// Print list of Students in a course
void printListOfStudentsInCourse(int courseID){
    Course* currCourse = head;
    while (currCourse != NULL){
        if (currCourse->courseID == courseID) break;
        currCourse = currCourse->next;
    }
    if (currCourse->studStart == NULL){
        cout << "0 Students Enroll in this course " << endl;
        return;
    }
    Student* currStudent = currCourse->studStart;
    while (currStudent != NULL){
        cout << "Student ID is " << currStudent->studentID << endl;
        currStudent = currStudent->next;
    }
}

void printCoursesOfStudent(int studentID){
    if (head == NULL){
        cout << "Course List is Empty !!!" << endl;
        return;
    }
    int i = 0;
    Course* currCourse = head;
    while (currCourse != NULL){
        Student* currStud = currCourse->studStart;
        while (currStud != NULL){
            if (currStud->studentID == studentID){
                cout << "Course ID : " << currCourse->courseID << endl;
                i++;
                break;
            }
            currStud = currStud->next;
        }
        currCourse = currCourse->next;
    }
    if (i == 0){
        cout << "Student has not opted any course !!!" << endl;
    }
}


int main (){
    int n;
    do {
        cout << "Enter 1 to Add a Course " << endl << "Enter 2 to Delete a Course " << endl << "Enter 3 to Search a Course " << endl << "Enter 4 to Print a Course List " << endl << "Enter 5 to Add a Student to a Course " << endl << "Enter 6 to Delete a Student from a Course " << endl << "Enter 7 to Delete a Student " << endl << "Enter 8 to Search a Student in Course " << endl << "Enter 9 to Print list of Students in a Course " << endl << "Enter 10 to Print the list of Courses in which a student has enrolled " << endl << "Enter 11 to Exit " << endl;
        cin >> n;
        if (n == 1){
            int courseID;
            cout << "Enter Course ID " << endl;
            cin >> courseID;
            if (courseID < 0){
                cout << "Course ID must be positive !!!" << endl;
            } else {
                addCourse (courseID);
            }
        } else if (n == 2){
            int courseID;
            cout << "Enter course ID which you want to Delete : ";
            cin >> courseID;
            if (courseID < 0){
                cout << "Course ID must be positive !!!" << endl;
            } else {
                delCourse (courseID);
            }
        } else if (n == 3){
            int courseID;
            cout << "Enter course ID which you want to Search : ";
            cin >> courseID;
            if (courseID < 0){
                cout << "Course ID must be positive !!!" << endl;
            } else {
                if (searchCourse(courseID)){
                    cout << "Course found in the List " << endl;
                } else {
                    cout << "Course not Found in the List !!!" << endl;
                }
            }
        } else if (n == 4){
            printCourseList();
        } else if (n == 5){
            int studentID;
            int courseID;
            cout << "Enter Course in which you want to Add Student : ";
            cin >> courseID;
            if (searchCourse(courseID)){
                cout << "Enter Student ID : ";
                cin >> studentID;
                if (studentID < 0){
                    cout << "Student ID must be positive !!!" << endl;
                } else {
                    addStudToCourse(studentID, courseID);
                }
            } else{
                cout << "Course not Found in the List !!!" << endl;
            }
        } else if (n == 6){
            int studentID;
            int courseID;
            cout << "Enter Course ID in which you want to Delete Student : ";
            cin >> courseID;
            if (searchCourse(courseID)){
                cout << "Enter Student ID you want to Delete in this Course : ";
                cin >> studentID;
                if (studentID < 0){
                    cout << "Student ID must be positive !!!" << endl;
                } else {
                    delStudFromCourse(studentID, courseID);
                }
            } else {
                cout << "Course not Found in the List !!!" << endl;
            }
        } else if (n == 7){
            int studentID;
            cout << "Enter student ID : ";
            cin >> studentID;
            if (studentID < 0){
                    cout << "Student ID must be positive !!!" << endl;
            } else {
                delStudent(studentID);
            }
        } else if (n == 8){
            int courseID;
            int studentID;
            cout << "Enter Course ID in which you want to Search for a Student : ";
            cin >> courseID;
            if (courseID < 0){
                    cout << "Course ID must be positive !!!" << endl;
            } else {
                if (searchCourse(courseID)){
                    cout << "Enter Student you want to Search in this Course : ";
                    cin >> studentID;
                    if (studentID < 0){
                        cout << "Student ID must be positive !!!" << endl;
                    } else {
                        if (searchStudentFromCourse (courseID, studentID)){
                            cout << "Student enroll in this course " << endl;
                        } else {
                            cout << "Student not found in this course !!!" << endl;
                        }
                    }
                } else {
                    cout << "Course not Found in the List " << endl;
                }   
            }
        } else if (n == 9){
            int courseID;
            cout << "Enter Course ID : ";
            cin >> courseID;
            if (courseID < 0){
                cout << "Course ID must be positive !!!" << endl;
            } else {
                if (searchCourse(courseID)){
                    printListOfStudentsInCourse(courseID);
                } 
            }
        } else if (n == 10){
            int ID;
            cout << "Enter ID of Student : ";
            cin >> ID;
            if (ID < 0){
                cout << "Student ID must be positive !!!" << endl;
            } else {
                printCoursesOfStudent(ID);
            }
        } else if (n == 11){
            cout << "Exit" << endl;
        } else {
            cout << "Please input a Number between 1 - 10 !!!" << endl;
        }
    } while (n != 11); 
}