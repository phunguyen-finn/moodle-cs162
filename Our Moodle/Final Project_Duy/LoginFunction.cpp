struct Student {
	/* OBJECT */
	int id;
	string firstName;
	string LastName;
	bool gender; // 0 = female, 1 = male
	Date dob; // date of birth
	string socialId;

	/* LINK */
	string classId;
	string* coursesId;
};

struct Class {
	/* OBJECT */
	string id;

	/* LINK */
	int yearOfClass; // the school year that this class is first introduced
	int nStudent; // number of students
	string* studentsId; // list of students
};

struct Course {
	/* OBJECT */
	string id;
	string name;
	string teacher;
	int nCredit; // number of credits
	int session[c_NWeekDay]; // sessions the course is taught during weekdays
	int maxCapacity; // maximum number of students

	/* LINK */
	int nStudent; // number of students
	string* studentsId; // list of students ID

	/* CONSTRUCTOR */
	Course(): maxCapacity(c_MaxCapInit), nCredit(), session(), studentsId(), nStudent() {}
};

struct Date {
	/* OBJECT */
	int day, month, year;

	/* CONSTRUCTOR */
	Date() : day(), month(), year() {}
	Date(int day, int month, int year) :
		day(day), month(month), year(year)
	{}
};

struct SchoolYear {
	/* OBJECT */
	int year;

	/* LINK */
	Semester semester[c_NSemester];
};

struct Semester {
	/* OBJECT */
	string name; // Fall, Spring, Summer,... etc
	Date startDate, endDate;

	/* LINK */
	int nStudent; // number of students
	string* studentsId; // list of students
	int nCourse; // number of course
	string* coursesId; // list of courses
	int year; // belong to which school year
};

struct loginAccount{
    string position;
    string username;
    string password;
};

// Login Function
string currentlog;
int logINAccount(string name, string pass){
    ifstream fin;
    string temp;
    fin.open("LoginAccount.txt");
    if(fin.is_open()){
        loginAccount account;
        getline(fin, temp, '\n');

        while(!fin.eof()){
            getline(fin, account.position, ',');
            getline(fin, account.username, ',');
            getline(fin, account.password, '\n');

        if(account.position == "student" && account.username == username && account.password == password){
            currentlog = username;
            fin.close();
            return 1; // 1 is meaning for Student
            }

        else if(account.position == "lecturer" && account.username == usermame && account.password == password){
            currentlog = username;
            fin.close();
            return 2; // 2 is meaning for Lecturer
        }

        else if(account.position == "Staff" && account.username == username && account.password == password){
            currentlog = username;
            fin.close();
            return 3; // 3 is meaning for Staff
        }

        }

        cout <<"Login Fail, please login again" << endl;
        system("pause");
        return 0;
    }

    else{
        cout <<"Can not open the input Account File, please check this file again" << endl;
    }

    system("pause >nul");
}

void forgotPassword(string userName){
    cin.ignore();
    ifstream fin;
    ofstream fout;
    int a = 0;
    string temp;
    fin.open("Login.txt");
    getline(fin, temp, '\n');
    string tempName, tempPass, tempRole;

    while(!fin.eof()){
        getline(fin, tempRole, ',');
        getline(fin, tempName, ',');
        getline(fin, tempPass, ',');
    if(tempName == userName){
        fout.open("ForgotPassword.csv", std::ofstream::app);
        if(fout.is_open()){
            fout << userName << ",";
            fout << tempPass<< endl;
            a = 1;
            fout.close();
            cout <<"Your info has sent to staff, please waiting for email to confirm" << endl;
            break;
        }
    }
    }

    if(a == 0)
        cout <<"Your username is not existed, please try again" << endl;

    fin.close();
    system("pause >nul");
}

void option(int &i, int &selection){
    string startOption[2] = {"Login", "Forgot Pass"};
    for(i = 0; i < 2; i++){
        if(i == selection){
            cout << startOption[i];
        }
        else{
            cout << startOption[i];
        }
    }
}

void inputAccount(int &a, string username, string password, string reEnter, string newPass, int &pointer, int &role){
    cin.ignore();
    cout <<"User Name" << endl;
    getline(cin,username);
    if(pointer == 0){
        cout <<"Your current password is:" << endl;
        getline(cin, password);
        cout << "Enter 0 to exit  || 1 to login || 2 to input again || 3 to switch to Forgot Password" << endl;
        cin >> a;
    }
    else{
        cout << "Enter 0 to exit  || 1 to login || 2 to input again || 3 to switch to Forgot Password" << endl;
        cin >> a;
    }

    if(a == 0){
        exit(0);
    }
    else if(a == 1){
        if(pointer == 0){
            role = loginAccount(username, password);
            return;
        }
        else{
            forgotPassword(username);
        }
    }
    else if(a == 3){
        if(pointer == 0){
            pointer = 1;
        }
        else if(pointer == 1){
            pointer = 0;
        }
    else{
        return;
    }
    }
}

void clear{
    system("cls");
}

...............




