#include <iostream>
using namespace std;

#include "GradeBook.h"

GradeBook::GradeBook(string nome, string professor)
{
  setCoutseName(nome);
  setProfessorName(professor);
}

void GradeBook::setCoutseName(string nome)
{
  courseName = nome;
}

string GradeBook::getCourseName()
{
  return courseName;
}

void GradeBook::displayMessege()
{
  cout << "\nWelcome to the grade book for:\n" << getCourseName() << "\nBy teacher: " << getProfessorName() << endl;
}

void GradeBook::setProfessorName(string nome)
{
  professorName = nome;
}

string GradeBook::getProfessorName()
{
  return professorName;
}