//Kojiro, Brandon
//23 September, 2024
//Student List
//Create a program that can read in, store, print, and delete students

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

struct Student {
  char firstName[20];
  char lastName[20];
  int studentID;
  float gpa;
};

void addStudent(vector<Student*> &studentVect);
void printStudents(vector<Student*> studentVect);
void deleteStudent();

int main() {
  vector<Student*> studentVect;
  bool active = true;
  while (active) {
    cout << "Type ADD, PRINT, DELETE, or QUIT" << endl << "> ";
    //read in what user wants to do
    char action[10];
    cin.get(action, 11);
    cin.get();
    if (strcmp(action, "ADD") == 0) { //adding a new student to vector
      addStudent(studentVect);
    } else if (strcmp(action, "PRINT") == 0) { //printing the vector
      printStudents(studentVect);
    } else if (strcmp(action, "DELETE") == 0) { //deleting a student from the vector
      deleteStudent();
    } else if (strcmp(action, "QUIT") == 0) { //ending the program
      cout << "Program terminated";
      return 0;
    } else {
      cout << "Invalid input. Please check your capitalization and spelling" << endl;
    }
  }
  return 0;
}

void addStudent(vector<Student*> &studentVect) { //add pointer to new student with info, then add to vector
  Student* newStudent = new Student();
  cout << "First Name:" << endl << "> ";
  cin.get(newStudent->firstName, 21);
  cin.get();
  cout << "Last Name:" << endl << "> ";
  cin.get(newStudent->lastName, 21);
  cin.get();
  cout << "Student ID" << endl << "> ";
  cin >> newStudent->studentID;
  cout << "GPA" << endl << "> ";
  cin >> newStudent->gpa;
  cout << "Name: " << newStudent->lastName << ", " << newStudent->firstName << endl << "ID: " << newStudent->studentID << endl << "GPA: " << newStudent->gpa << endl;
  cin.ignore(); //for null terminating char
  studentVect.push_back(newStudent); //add to vector
}
  
void printStudents(vector<Student*> studentVect) { //go through vector and print all info
  for (int i = 0; i < studentVect.size(); i++) { //DON'T USE FOR LOOP FOR THIS!! LOOK UP ITERATORS
    cout << studentVect[i]->firstName << " " << studentVect[i]->lastName << ", " << studentVect[i]->studentID << ", " << studentVect[i]->gpa << endl;
  }
}

void deleteStudent() { //delete student based on id, then DELETE DATA!!

}
