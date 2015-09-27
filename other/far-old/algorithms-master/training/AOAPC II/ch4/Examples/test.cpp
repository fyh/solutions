#include <cstdio>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#define PB push_back
using namespace std;

typedef string Course;

class Student {
 public:

  Student(string SID, int CID, string name, vector<int> scores) : SID(SID), CID(CID), name(name), scores(scores) {
    total = 0;
    for (int i = 0; i < scores.size(); i++) {
      total += scores[i];
    }
    average = total / (double)scores.size();
  }

  string SID, name;
  int CID;
  vector<int> scores;
  int total;
  double average;
};

class SPMS {
 public:

  SPMS(vector<Course> courses) : courses(courses) {}

  void run() {
    int option = -1;
    do {
      switch (option) {
       case 1:
        add();
        break;
       case 2:
        remove();
        break;
       case 3:
        query();
        break;
       case 4:
        showRanking();
        break;
       case 5:
        showStatics();
        break;
      }
      puts("Welcome to Student Performance Management System (SPMS).\n");
      puts("1 - Add");
      puts("2 - Remove");
      puts("3 - Query");
      puts("4 - Show ranking");
      puts("5 - Show Statistics");
      puts("0 - Exit");
      puts("");
    } while (scanf("%d", &option) && option);
  }

 private:

  void add() {
    char SID[99];
    puts("Please enter the SID, CID, name and four scores. Enter 0 to finish.");
    while (scanf("%s", SID) && string(SID) != "0") {
      int CID;
      char name[99];
      vector<int> scores;
      scanf("%d%s", &CID, name);
      for (int i = 0; i < courses.size(); i++) {
        int score;
        scanf("%d", &score);
        scores.PB(score);
      }
      bool already = false;
      for (int i = 0; i < students.size() && !already; i++) {
        already = (students[i].SID == SID);
      }
      if (already) {
        puts("Duplicated SID.");
      } else {
        students.PB(Student(SID, CID, name, scores));
      }
      puts("Please enter the SID, CID, name and four scores. Enter 0 to finish.");
    }
  }

  void remove() {
    char keyword[99];
    puts("Please enter SID or name. Enter 0 to finish.");
    while (scanf("%s", keyword) && string(keyword) != "0") {
      int removedNum = 0;
      for (int i = 0; i < students.size(); i++) {
        Student & student = students[i];
        if ((student.SID == keyword) || (student.name == keyword)) {
          students.erase(students.begin() + i--);
          removedNum++;
        }
      }
      printf("%d student(s) removed.\n", removedNum);
      puts("Please enter SID or name. Enter 0 to finish.");
    }
  }

  void query() {
    char keyword[99];
    puts("Please enter SID or name. Enter 0 to finish.");
    while (scanf("%s", keyword) && string(keyword) != "0") {
      adjustRank();
      for (int i = 0; i < students.size(); i++) {
        Student & student = students[i];
        if ((student.SID == keyword) || (student.name == keyword)) {
          printf("%d %s %d %s", rankOfScore[student.total], student.SID.c_str(), student.CID, student.name.c_str());
          for (int j = 0; j < student.scores.size(); j++) {
            printf(" %d", student.scores[j]);
          }
          printf(" %d %.2lf\n", student.total, student.average + 1e-5);
        }
      }
      puts("Please enter SID or name. Enter 0 to finish.");
    }
  }

  void showRanking() {
    puts("Showing the ranklist hurts students' self-esteem. Don't do that.");
  }

  void showStatics() {
    puts("Please enter class ID, 0 for the whole statistics.");
    int CID;
    scanf("%d", &CID);
    for (int c = 0; c < courses.size(); c++) {
      puts(courses[c].c_str());
      int num = 0, total = 0, passed = 0;
      for (int i = 0; i < students.size(); i++) {
        Student & student = students[i];
        if (!CID || (student.CID == CID)) {
          num++;
          total += student.scores[c];
          passed += (student.scores[c] >= 60);
        }
      }
      printf("Average Score: %.2lf\n", total / (double)(num == 0 ? 1 : num) + 1e-5);
      printf("Number of passed students: %d\n", passed);
      printf("Number of failed students: %d\n", num - passed);
      puts("");
    }
    vector<int> passedNum(courses.size() + 1, 0);
    for (int i = 0; i < students.size(); i++) {
      Student & student = students[i];
      if (!CID || (student.CID == CID)) {
        int passed = 0;
        for (int c = 0; c < courses.size(); c++) {
          passed += (student.scores[c] >= 60);
        }
        passedNum[passed]++;
      }
    }
    puts("Overall:");
    printf("Number of students who passed all subjects: %d\n", passedNum.back());
    for (int i = passedNum.size() - 2; i > 0; i--) {
      passedNum[i] += passedNum[i + 1];
      printf("Number of students who passed %d or more subjects: %d\n", i, passedNum[i]);
    }
    printf("Number of students who failed all subjects: %d\n", passedNum[0]);
    puts("");
  }

  void adjustRank() {
    rankOfScore.clear();
    vector<int> allScores;
    for (int i = 0; i < students.size(); i++) {
      allScores.PB(students[i].total);
    }
    sort(allScores.begin(), allScores.end());
    reverse(allScores.begin(), allScores.end());
    for (int i = 0; i < allScores.size(); i++) {
      if (rankOfScore.find(allScores[i]) == rankOfScore.end()) {
        rankOfScore[allScores[i]] = i + 1;
      }
    }
  }

  vector<Course> courses;
  vector<Student> students;
  map<int, int> rankOfScore;
};
# define testin freopen("data.in", "r", stdin)
# define testout freopen("test.out", "w", stdout)
int main() {
    testin;
    testout;
  vector<Course> courses;
  courses.PB("Chinese");
  courses.PB("Mathematics");
  courses.PB("English");
  courses.PB("Programming");
  SPMS spms(courses);
  spms.run();
  return 0;
}
