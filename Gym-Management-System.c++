#include <iostream>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <ctime>
#include <unistd.h>
using namespace std;
class student
{
private:
    int roll;
    int age;
    long long phone;
    char name[50];
    char address[50];
    char payment[50];

public:
    void setpwd()
    {
        string pass;
        string pw = "dinesh";
    hi:
        cout << "Enter password to continue:" << endl;
        cin >> pass;
        int res = pw.compare(pass);
        if (res == 0)
        {
            cout << "Matching password..." << endl;
        }
        else
        {
            cout << "Password incorrect" << endl;
            cout << "Please try again" << endl;
            goto hi;
        }
    }

    void setapwd()
    {
        string pass;
        string pw = "dineshh";
    hj:
        cout << "Enter password to continue:" << endl;
        cin >> pass;
        int res = pw.compare(pass);
        if (res == 0)
        {
            cout << "Matching password..." << endl;
        }
        else
        {
            cout << "Password incorrect" << endl;
            cout << "Please try again" << endl;
            goto hj;
        }
    }
    void getdata()
    {
        cout << "enter name of the costumer:" << endl;
        cin >> name;
        cout << "enter address of the costumer:" << endl;
        cin >> address;
        cout << "enter the id :" << endl;
        cin.clear();
        cin >> roll;
        cout << "enter phone number of the costumer : " << endl;
        cin.clear();
        cin >> phone;
        cout << "enter your age :" << endl;
        cin.clear();
        cin >> age;
        cout<<"enter the advanced amount in Rs:"<<endl;
        cin.clear();
        cin>>payment;
    }
    void regetdata()
    {
        cout << "enter name of the costumer:" << endl;
        cin >> name;
        cout << "enter address of the costumer:" << endl;
        cin >> address;
        cout << "enter the id :" << endl;
        cin.clear();
        cin >> roll;
        cout << "enter phone number of the costumer : " << endl;
        cin.clear();
        cin >> phone;
        cout << "enter your age :" << endl;
        cin.clear();
        cin >> age;
    }

    void putdata()
    {
        cout << setw(15) << name << setw(20) << address << setw(15) << setw(10) << age << '\n';
    }
    void putadata()
    {
        cout << setw(15) << name << setw(20) << address << setw(15) << phone << setw(10) << age <<setw(10)<<payment<< '\n';
    }

    int getroll()
    {
        return roll;
    }
    void showtime()
    {
        time_t now = time(0);
        struct tm current_time = *localtime(&now);
        std::cout << "Current Date: ";
        std::cout << (current_time.tm_year + 1900) << "-" << (current_time.tm_mon + 1) << "-" << current_time.tm_mday << std::endl;
    }
};

int main()
{

    student std;
    bool isAdmin;
    void menue();
    {
        while (1)
        {
            int c;
            cout << "please choose the required option" << endl;
            cout << "press 1 for admin" << endl;
            cout << "press 2 for other" << endl;
            cin.clear();
            cin >> c;
            switch (c)
            {
            case 1:
                std.setapwd();
                isAdmin = true;
                break;
            case 2:
                std.setpwd();
                isAdmin = false;
                break;

            default:
                cout << "please enter valid option:" << endl;
                continue;
            }
            break;
           
            
        }
    }
    fstream inout;
    int m, roll, object, isfound;
    if (isAdmin==true)
    {
    hk:
        int c;
        cout << "\n\n\n\t\t\t";
        std.showtime();
        cout << "\n\n\n\n\n\n\n";

        cout << "\t\t\t\t\t\t==============================\n";
        cout << "\t\t\t\t\t\t   SCAVENGER GYM AND FITNESS\n";
        cout << "\t\t\t\t\t\t==============================\n\n\n\n";
        cout << "\t\t\t\t\t\t HEARTY WELCOME\n";
        cout << "\t\t\t\t\t\t================\n\n\n\n";
        cout << "1. Add new member :" << endl;
        cout << "2. see who are with us :" << endl;
        cout << "3. Edit your information" << endl;
        cout << "4. Revoke membership :" << endl;
        cout << "==================================================================\n";
        cout << "Enter choice:\n";
        cin.clear();
        cin >> c;
        switch (c)
        {
        case 1:
            inout.open("rec.txt", ios::out);
            int z;
            cout << "enter the number of costumer: "
                 << "\n";
            cin >> z;
            for (int i = 1; i <= z; i++)
            {
                std.getdata();
                inout.write((char *)&std, sizeof(std));
            }
            cout << "file written successfully" << endl;
            inout.close();
            {
            hn:
                int ch;
                cout << "==================================================================\n";
                cout << "Enter 0 to exit and 1 to go to main menu\n";
                cin.clear();
                cin >> ch;
                if (ch == 0)
                {
                    exit(0);
                }
                else if (ch == 1)
                {
                    goto hk;
                }
            }
            break;

        case 2:
            inout.open("rec.txt", ios::in);
            cout << "current contents of file" << endl;
            while (inout.read((char *)&std, sizeof(std)))
            {
                std.putadata();
            }
            inout.close();
            goto hn;
            break;

        case 3:
            inout.open("rec.txt", ios::in | ios::out | ios::ate);
            int location;
            object = isfound = 0;
            cout << "enter the id :" << endl;
            cin >> roll;
            inout.seekg(0, ios::beg);
            while (inout.read((char *)&std, sizeof(std)))
            {
                ++object;
                if (std.getroll() == roll)
                {
                    isfound = 1;
                    location = (object - 1) * sizeof(std);
                    inout.seekp(location, ios::beg);
                    cout << "enter the new data" << endl;
                    std.regetdata();
                    inout.write((char *)&std, sizeof(std));
                    cout << "record modified" << endl;
                    break;
                }
            }
            if (!isfound)
            {
                cout << "the record is not found" << endl;
            }
            inout.close();
            goto hn;
            break;

        case 4:
            inout.open("rec.txt", ios::in);
            student st[48];
            int i, j;
            i = 0;
            cout << "enter id :" << endl;
            cin >> roll;
            inout.seekg(0, ios::beg);
            while (inout.read((char *)&st[i], sizeof(st[i])))
            {
                ++i;
            }
            j = i;
            inout.close();
            inout.open("rec.txt", ios::out);
            for (i = 0; i < j; i++)
            {
                if (st[i].getroll() != roll)
                {
                    inout.write((char *)&st[i], sizeof(st[i]));
                }
            }
            cout << "record deleted" << endl;
            inout.close();
            goto hn;
            break;
        default:
            cout << "please enter the valid choice" << endl;
        }
    }
    else if (isAdmin == false)
    {
    hq:

        cout << "\n\n\n\t\t\t";
        std.showtime();
        cout << "\n\n\n\n\n\n\n";
        cout << "\t\t\t\t\t\t==============================\n";
        cout << "\t\t\t\t\t\t   SCAVENGER GYM AND FITNESS\n";
        cout << "\t\t\t\t\t\t==============================\n\n\n\n";
        cout << "\t\t\t\t\t\t HEARTY WELCOME\n";
        cout << "\t\t\t\t\t\t================\n\n\n\n";
        cout << "1. add new memeber :" << endl;
        cout << "2. View your info:" << endl;
        cout << "3. contact us" << endl;
        cout << "4. About us" << endl;
        cout << "==================================================================\n";
        cout << "Enter choice:\n";
        {

            int k;
            cin.clear();
            cin >> k;

            switch (k)
            {
            case 1:
                inout.open("rec.txt", ios::app);
                cout << "add record of the costumer:" << endl;
                std.getdata();
                inout.write((char *)&std, sizeof(std));
                cout << "record added" << endl;
                inout.close();
                {
                    ho:
                    int ch;
                    cout << "==================================================================\n";
                    cout << "Enter 0 to exit and 1 to go to main menu\n";
                    cin.clear();
                    cin >> ch;
                    if (ch == 0)
                    {
                        exit(0);
                    }
                    else if (ch == 1)
                    {
                        goto hq;
                    }
                }
                break;

            case 2:
                inout.open("rec.txt", ios::in);
                isfound = 0;
                cout << "enter id :" << endl;
                cin >> roll;
                
                inout.seekg(0, ios::beg);
                while (inout.read((char *)&std, sizeof(std)))
                {
                    if (std.getroll() == roll)
                    {
                        isfound = 1;
                        cout << "search record:" << endl;
                        std.putdata();
                        break;
                    }
                }
                if (isfound == 0)
                {
                    cout << "record not found" << endl;
                }
                inout.close();
                goto ho;
                break;

            case 3:
                cout << "\t\t\t\t\t\tContact Information\n\n\n\n\n\n";
                cout << "Email:dineshtamang1308@gmail.com\n";
                cout << "Phone number:1234567898\n";
                cout << "Facebook:dinesh448\n";
                cout << "Instagram:dineshtamang1308\n\n\n";
                goto ho;
                break;
            case 4:
                cout << "\t\t\t\t\t\t WHY US  \n\n\n\n\n\n\n";
                cout << "1.Child care with exercise arcade so your kids stay active.\n2.Huge weight room and workout floor.\n3.Internationally certified personal trainers.\n4.The best personal trainers in town.\n5.Big screen cardio movie experience.\n6.Separate cycle studio.\n8.Team Training Now Offered.\n";
                cout << "Other services:\n\t-group fitness classes.\n\t-Kick Boxing Training.\n\t-Muay Thai.\n\t-physical therapy service.\n\t-Specialized class.\n\t-Towel service.\n\t-Nutritional Guidance.\n\t-Sauna and Steam Rooms.\n\t-Gymnasium and many more.\n\n\n";
                cout << "\t\t\t\t***\n\n\n";
                cout << "If you have any queries regarding our gym please contact us.\n\n\n";
                goto ho;
                break;

            default:
                cout << "please enter valid option" << endl;
            }
        }
    }
    return 0;
}
