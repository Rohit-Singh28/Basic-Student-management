#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Student
{
protected:
    int roll_no, sap_id;
    string name, address;

public:
    // Student(string name_s,string address_s,int roll_no_s,int sap_id_s)
    Student(string name_s, int roll_no_s)
    {
        name = name_s;
        roll_no = roll_no_s;
        // address=address_s;
        // sap_id=sap_id_s;
    }
    Student() {}
    string return_name()
    {
        return name;
    }
    int return_roll()
    {
        return roll_no;
    }
};

class UserManager : public Student
{
    vector<Student> user;

public:
    void add_new_student()
    {
        cout << "enter name : ";
        cin >> name;
        cout << endl;
        cout << "enter roll_no : ";
        cin >> roll_no;
        cout << endl;
        Student abc(name, roll_no);
        user.push_back(abc);
    }
    void display()
    {
        cout << "Name\t roll no\t" << endl;
        for (int i = 0; i < user.size(); i++)
        {
            cout << user[i].return_name() << "\t" << user[i].return_roll() << endl;
        }
    }
    void search_user(string name)
    {
        int flag = 0;
        for (int i = 0; i < user.size(); i++)
        {
            if (user[i].return_name() == name)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 1)
        {
            cout << "user found" << endl;
        }
        else if (flag == 0)
        {
            cout << "user not found" << endl;
        }
    }
    void Uptate_user()
    {
        cout << "enter the name :  ";
        cin >> name;
        cout << endl;
        cout << "enter the roll :  ";
        cin >> roll_no;
        cout << endl;
        for (int i = 0; i < user.size(); i++)
        {
            if (user[i].return_name() == name && user[i].return_roll() == roll_no)
            {
                user.erase(user.begin() + i);
                cout << "enter the given this to uptate " << endl;
                add_new_student();
                break;
            }
            else
            {
                cout << "invalid user name/rollno " << endl;
                break;
            }
        }
    }
    void delete_user()
    {
        cout << "enter the name : " << endl;
        cin >> name;
        for (int i = 0; i < user.size(); i++)
        {
            if (user[i].return_name() == name)
            {
                user.erase(user.begin() + i);
                cout << "user deleted" << endl;
                break;
            }
        }
    }
};

int main()
{
    UserManager Student_1;
    char str;
    int choice;
    cout << "Student management" << endl;
    do
    {
        system("cls");
        cout << "_____________________________________________\n"
             << endl;
        cout << " 1 : add new student\n 2 : display all student\n 3 : search student\n";
        cout << " 4 : Uptate\n 5 : delete\n 6 : exit" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            Student_1.add_new_student();
            break;
        }
        case 2:
        {
            Student_1.display();
            break;
        }
        case 3:
        {
            string name;
            cout << "enter the name : ";
            cin >> name;
            cout << endl;
            Student_1.search_user(name);
            break;
        }
        case 4:
        {
            Student_1.Uptate_user();
            break;
        }
        case 5:
        {
            Student_1.delete_user();
            break;
        }

        default:
        {
            cout << "invvalid input " << endl;
            break;
        }
        }
        cout << "do you want to continue (YES / No) :";
        cin >> str;
        cout << endl;
    } while (str == 'y' || str == 'Y');
    return 0;
}