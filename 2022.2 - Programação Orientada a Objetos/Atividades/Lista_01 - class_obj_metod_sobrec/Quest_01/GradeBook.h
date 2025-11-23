#include <string>
using namespace std;


class GradeBook{
  private:
    string courseName;
    string professorName;
  public:
    GradeBook(string, string);
    void setCoutseName(string);
    string getCourseName();
    void displayMessege();

    void setProfessorName(string);
    string getProfessorName();
};