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
void deleteStudent(vector<Student*> &studentVect);

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
      deleteStudent(studentVect);
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
  vector<Student*>::iterator iter; //iteration code from https://stackoverflow.com/questions/23318875/iterating-through-a-vector-of-pointers
  for (iter = studentVect.begin(); iter < studentVect.end(); iter++) {
    cout << (*iter)->firstName << " " << (*iter)->lastName << ", " << (*iter)->studentID << ", " << (*iter)->gpa << endl;
  }
}

void deleteStudent(vector<Student*> &studentVect) { //delete student based on id, then DELETE DATA!!
  cout << "Enter the ID that you want to delete" << endl << "> ";
  int deleteID = 0;
  cin >> deleteID;
  cin.ignore();
  int count = 0;
  vector<Student*>::iterator iter;
  for (iter = studentVect.begin(); iter < studentVect.end(); iter++) {
    if (deleteID == (*iter)->studentID) {
      cout << (*iter)->firstName << " " << (*iter)->lastName << " was removed from the program" << endl;
      delete *iter;
      studentVect.erase(iter);
      return;
    }
  }
  cout << "Student ID not found" << endl;
}
