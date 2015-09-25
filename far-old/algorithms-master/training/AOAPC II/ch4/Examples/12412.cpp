# include <iostream>
# include <cstdio>
# include <cstring>
using namespace std;

# define clr(x) memset((x), 0, sizeof(x))

class student
{
public:
    char sid[15];
    unsigned int cid;
    char name[15];
    int score[5]; // order: chinese, math, english, programming
    unsigned int rank;
    unsigned int totScore;
    double averageScore;
    student * next;
    student() {
        rank = 0;
        totScore = 0;
        averageScore = 0.0;
        next = NULL;
    }
};
const char * study[] = {
    "Chinese", "Mathematics", "English", "Programming"
};
class SPMS
{
public:
    student * head;
    SPMS() {
        head = NULL;
    }
    bool sort() {
        student * p = head;
        while (p != NULL) {
            int cntGreater = 0;
            student *q = head;
            while (q != NULL) {
                if (q->totScore > p->totScore) {
                    ++cntGreater;
                }
                q = q->next;
            }
            p->rank = cntGreater + 1;
            p = p->next;
        }
        return true;
    }
    bool add() {
        cout << "Please enter the SID, CID, name and four scores. Enter 0 to finish." << endl;
        student * newStu = new student();
        cin >> newStu->sid;
        if (strcmp(newStu->sid, "0") == 0) {
            delete newStu;
            return false;
        }
        cin >> newStu->cid >> newStu->name;
        for (int i = 0; i < 4; ++i) {
            cin >> newStu->score[i];
            newStu->totScore += newStu->score[i];
        }
        newStu->averageScore = newStu->totScore / 4.0;
        student * cur = head;
        student * pre = NULL;
        bool duplicate = false;
        while (cur != NULL && !duplicate) {
            if (strcmp(cur->sid, newStu->sid) == 0) {
                duplicate = true;
            } else {
                pre = cur;
                cur = cur->next;
            }
        }
        if (duplicate == true) {
            cout << "Duplicated SID." << endl;
            delete newStu;
        } else {
            if (cur == head) {
                head = newStu;
            } else {
                pre->next = newStu;
            }
        }
        return true;
    }
    bool mv() {
        cout << "Please enter SID or name. Enter 0 to finish." << endl;
        char key[15];
        cin >> key;
        if (strcmp(key, "0") == 0) return false;
        student * cur = head;
        student * pre = NULL;
        unsigned int cntMv = 0;
        while (cur != NULL) {
            if (strcmp(cur->sid, key) == 0 || strcmp(cur->name, key) == 0) {
                ++cntMv;
                if (cur == head) {
                    head = cur->next;
                    delete cur;
                    cur = head;
                } else {
                    pre->next = cur->next;
                    delete cur;
                    cur = pre->next;
                }
            } else {
                pre = cur;
                cur = cur->next;
            }
        }
        cout << cntMv << " student(s) removed." << endl;
        return true;
    }
    bool query() {
        cout << "Please enter SID or name. Enter 0 to finish." << endl;
        char key[15];
        cin >> key;
        if (strcmp(key, "0") == 0) return false;
        sort();
        student * cur = head;
        while (cur != NULL) {
            if (strcmp(cur->sid, key)==0 || strcmp(cur->name, key)==0) {
                cout << cur->rank << ' '
                     << cur->sid << ' '
                     << cur->cid << ' '
                     << cur->name << ' ';
                for (int i = 0; i < 4; ++i) {
                    cout << cur->score[i] << ' ';
                }
                printf("%d %.2f\n", cur->totScore, cur->averageScore);
            }
            cur = cur->next;
        }
        return true;
    }
    bool showStati() {
        cout << "Please enter class ID, 0 for the whole statistics." << endl;
        unsigned int cid;
        cin >> cid;
        double sumScore[5];
        unsigned int cntNums = 0;
        unsigned int numOfPassed[5];
        unsigned int passSta[6];
        clr(sumScore);
        clr(numOfPassed);
        clr(passSta);
        student * cur = head;
        student * pre = NULL;
        while (cur != NULL) {
            if (!cid || cur->cid == cid) {
                ++cntNums;
                unsigned int cntPassed = 0;
                for (int i = 0; i < 4; ++i) {
                    sumScore[i] += cur->score[i];
                    if (cur->score[i] >= 60) {
                        ++numOfPassed[i];
                        ++cntPassed;
                    }
                }
                ++passSta[cntPassed];
            }
            cur = cur->next;
        }
        for (int i = 0; i < 4; ++i) {
            printf("%s\nAverage Score: %.2f\nNumber of passed students: %d\nNumber of failed students: %d\n\n",
                   study[i], cntNums>0 ? sumScore[i]/cntNums:0, numOfPassed[i], cntNums-numOfPassed[i]);
        }
        cout << "Overall:"
             << "\nNumber of students who passed all subjects: " <<  passSta[4]
             << "\nNumber of students who passed 3 or more subjects: " << passSta[4] + passSta[3]
             << "\nNumber of students who passed 2 or more subjects: " << passSta[4] + passSta[3] + passSta[2]
             << "\nNumber of students who passed 1 or more subjects: " << cntNums - passSta[0]
             << "\nNumber of students who failed all subjects: " << passSta[0]
             << "\n" << endl;
        return false;
    }
    bool showRank() {
        cout << "Showing the ranklist hurts students' self-esteem. Don't do that." << endl;
        return false;
    }
    bool showWelc() {
        cout << "Welcome to Student Performance Management System (SPMS).\n" << endl;
        cout << "1 - Add\n"
             << "2 - Remove\n"
             << "3 - Query\n"
             << "4 - Show ranking\n"
             << "5 - Show Statistics\n"
             << "0 - Exit\n" << endl;
        return false;
    }
    bool work() {
        showWelc();
        int od;
        while (cin >> od) {
            // printAllStudents();
            switch(od) {
            case 0 :
                return true;
            case 1 :
                while(add()) ;
                break;
            case 2 :
                while(mv()) ;
                break;
            case 3 :
                while(query()) ;
                break;
            case 4 :
                while(showRank()) ;
                break;
            case 5 :
                while(showStati()) ;
                break;
            }
            // printAllStudents();
            showWelc();
        }
        return false;
    }
    bool printAllStudents() {
        sort();
        cout << "printAllStudents" << endl;
        student * cur = head;
        while (cur != NULL) {
            cout << cur->rank << '\t'
                 << cur->name << endl;
            cur = cur->next;
        }
        cout << endl;
    }
};
# define testin freopen("data.in", "r", stdin)
# define testout freopen("data.out", "w", stdout)
SPMS sys;
int main()
{
 //   testin;
 //   testout;

    sys.work();

    return 0;
}
