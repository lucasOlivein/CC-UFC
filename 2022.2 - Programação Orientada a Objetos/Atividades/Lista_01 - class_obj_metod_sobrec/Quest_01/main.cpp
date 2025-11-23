#include <iostream>

using namespace std;
#include "GradeBook.h"
int main()
{
  GradeBook gradeBook1("BCC221 - POO", "Fabio");
  GradeBook gradeBook2("BCC202 - EAD's I", "Maria");


  cout << "gradeBook1 created for course: " << gradeBook1.getCourseName() << "\ngradeBook2 created for course: " << gradeBook2.getCourseName() << endl;

  gradeBook1.displayMessege();
  gradeBook2.displayMessege();
  return 0;
}