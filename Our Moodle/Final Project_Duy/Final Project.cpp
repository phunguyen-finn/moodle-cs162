struct loginAccount{
    string position;
    string username;
    string password;
};

struct infoStudent{
    string id;
    string fullname;
    string birthdate;
    string classname;
    string sex;
    string status;
};

struct studentinfile {
	string id;
	string fullname;
	string sex;
	string classes;
};

struct infoLectureTask4{
    string username;
    string fullname;
    string degree;
    string gender;
};

struct time{
    int hour;
    int minute;
};

struct courseStructTask4{
    int num;
    string name;
    string fullname;
    infoLectureTask4 lecturer;
    string classes;
    Date startdate;
    Date finishdate;
    time starttime;
    time finishtime;
    string room;
    string dayinweek;
};

struct Date {
	/* OBJECT */
	int day, month, year;

	/* CONSTRUCTOR */
	Date(int day = -1, int month = -1, int year = -1) :
		day(day), month(month), year(year)
	{}
};

//12 Login Function
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
            gotoXY(47, 6);
            cout << startOption[i];
        }
        else{
            gotoXY(68,6);
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


bool changePasswordAccount(string account, string pass, string newpass){
    cin.ignore();
    ifstream fin;
    ofstream fout;
    int check = 0;
    fin.open("LoginAccount.txt");
    if(fin.is_open()){
        int n;
        fin >> n;
        loginAccount *acc;
        acc = new loginAccount[n];
        for(int i = 0; i < n; i++){
            getline(fin, acc[i]. position, ',');
            getline(fin, acc[i].username, ',');
            getline(fin, acc[i].password, ',');
        if(acc[i].username == account && acc[i].password == pass){
            acc[i].password = newpass;
            check = 1;
            cout << "Your password has changed succesfully";
        }
        }

        if(check == 0){
            cout <<"Fail, please enter the password again" << endl;
            system("pause >nul");
            fin.close();
            delete [] acc;
            return false;
        }

        fout.open("LoginAccount.txt");
        if(fout.is_open()){
            fout << n;
            for(int i = 0; i < n; i++){
                fout << acc[i].position <<',';
                fout << acc[i].username << ',';
                fout << acc[i].password << '\n';
            }
            fout.close();
        }
            else{
                cout <<"Sorry, can not open the file";
                retun false;
            }
        system("pause >nul");
        fin.close();
        delete [] acc;
        return true;
    }
    else{
        cout <<"Sorry, can not open the file";
        return false;
    }
}

void UIchangePassword(string account, string password, string newpass){
    newpass = "0";
    string re_enter = "1";
    bool check = false;
    while(re_enter != newpass || check == false){
        cout <<"Your current Password:" << endl;
        getline(cin, password);
        cout <<"Your new Password:" << endl;
        getline(cin, newpass);
        cout <<"Enter your Password again:" << endl;
        getline(cin, re_enter);
        if(re_enter != newpass){
            cout <<"Please check again your new password" << endl;
            system("Pause >nul");
            continue;
        }
        check = changePasswordAccount(account, pass, newpass);
    }
}

//================================================
//16 view list of courses in this semester // Co the la 1 file chua danh sach cac khoa hoc cua lop do trong hoc ki nay
void viewListOfCoursesStudyInThisSemester(string classname, string filename){
`   ifstream fin;
    fin.open(filename +".txt");
    if(!fin.is_open()){
        cout <<"Sorry, can not open the file" << endl;
    }
    else{
        char a;
        int column = 1, row = 5;
        courseStructTask4 c;
        gotoXY(column, row);
        cout <<"ID";
        gotoXY(column + 11, row);
        cout <<"Name of Course";
        gotoXY(column + 61, row);
        cout <<"Class";
        gotoXY(column + 70, row);
        cout <<"Lecturer";
        gotoXY(column + 100, row);
        cout <<"Degree";
        gotoXY(column + 110, row);
        cout <<"Day";
        gotoXY(column + 125, row);
        cout <<"Start";
        gotoXY(column + 135, row);
        cout <<"Finish";
        gotoXY(column + 145, row);
        cout <<"Room";
        row++;
        while(!fin.eof()){
            fin >> c.num;
            fin.ignore();
            getline(fin, c.name, '\n');
            getline(fin, c.fullname, '\n');
            getline(fin, c.classes, '\n');
            getline(fin, c.lecturer.username, '\n');
            getline(fin, c.lecturer.fullname, '\n');
            getline(fin, c.lecturer.degree, '\n');
            getline(fin, c.lecturer.gender, '\n');
            fin >> c.startdate.day;
            fin >> a;
            fin >> c.startdate.month;
            fin >> a;
            fin >> c.startdate.year;
            fin >> c.finishdate.day;
            fin >> a;
            fin >> c.finishdate.month;
            fin.ignore();
            fin >> c.finishdate.year;
            fin.ignore();
            getline(fin, c.dayinweek, '\n');
            fin >> c.starttime.hour;
            fin >> a;
            fin >> c.starttime.minute;
            fin >> c.finishtime.hour;
            fin >> a;
            fin >> c.finishtime.minute;
            fin.ignore();
            getline(fin, c.room, '\n');
            if(c.classes == classname){
                gotoXY(column, row);
                cout << c.name;
                gotoXY(column + 11, row);
                cout << c.fullname;
                gotoXY(column + 61, row);
                cout << c.classes;
                gotoXY(column + 70, row);
                cout << c.lecturer.fullname;
                gotoXY(column + 90, row);
                cout << c.lecturer.degree;
                gotoXY(column + 110, row);
                cout << c.dayinweek;
                gotoXY(column + 125, row);
                cout << c.starttime.hour << ":" << c.starttime.minute;
                gotoXY(column + 135, row);
                cout << c.finishtime.hour << ":" << c.finishtime.minute;
                gotoXY(column + 145, row);
                cout << c.room;
                row++;
            }
        }
        fin.close();
    }
}

//17 View List of Classes:
void viewListOfClasses(){
    string classes;
    int n = 1;
    ifstream fin;
    string temp;
    fin.open("Info_Student.txt");
    if(!fin.is_open()){
        cout <<"Can not open the file Info_Student.txt" << endl;
    }
    else{
        getline(fin, temp, '\n');
        while(!fin.eof()){
            infoStudent s;
            getline(fin, s.id, ',');
            getline(fin, s.fullname, ',');
            getline(fin, s.birthdate, ',');
            getline(fin, s.classname, ',');
            getline(fin, s.sex, ',');
            getline(fin, s.status, ',');
        if(classes.find(s.classname) == -1)
            cout << n << ". " << s.classname << endl;
            classes.append(s.classname);
            n++;
        }
        fin.close();
        system("pause >nul");
    }
}

//18 view list of student in a class:
void viewListOfStudentInClass(string classname){
    ifstream fin;
    string temp;
    int n = 1;
    fin.open("Info_Student.txt");
    if(!fin.is_open()){
        cout <<"Can not open the file, please try again" << endl;
    }
    else{
        cout << "     ID        |           Name             |         DOB         |       Gender      |       Status      " << endl;
        getline(fin, temp, '\n');
        int i = 4;
        while(!fin.eof()){
            infoStudnet s;
            getline(fin, s.id, ',');
            getline(fin, s.fullname, ',');
            getline(fin, s.birthdate, ',');
            getline(fin, s.classname, ',');
            getline(fin, s.sex, ',');
            getline(fin, s.status, ',');

            if(classname == st.classname){
                gotoXY(2,i);
                cout << s.id;
                gotoXY(18,i);
                cout << s.fullname;
                gotoXY(50,i);
                cout << s.dob;
                gotoXY(74,i);
                if(s.sex == "Female"){
                    cout <<"Female";
                }
                if(s.sex == "Male"){
                    cout <<"Male";
                }
                gotoXY(94, i);
                i++:
            }
        }
        fin.close();
        system("pause >nul");
    }
}

//19 View list of courses.
void viewListOfCoursesStudyInThisSemester(string classname, string filename){
`   ifstream fin;
    fin.open(filename +".txt");
    if(!fin.is_open()){
        cout <<"Sorry, can not open the file" << endl;
    }
    else{
        char a;
        int column = 1, row = 5;
        courseStructTask4 c;
        gotoXY(column, row);
        cout <<"ID";
        gotoXY(column + 11, row);
        cout <<"Name of Course";
        gotoXY(column + 61, row);
        cout <<"Class";
        gotoXY(column + 70, row);
        cout <<"Lecturer";
        gotoXY(column + 100, row);
        cout <<"Degree";
        gotoXY(column + 110, row);
        cout <<"Day";
        gotoXY(column + 125, row);
        cout <<"Start";
        gotoXY(column + 135, row);
        cout <<"Finish";
        gotoXY(column + 145, row);
        cout <<"Room";
        row++;
        while(!fin.eof()){
            fin >> c.num;
            fin.ignore();
            getline(fin, c.name, '\n');
            getline(fin, c.fullname, '\n');
            getline(fin, c.classes, '\n');
            getline(fin, c.lecturer.username, '\n');
            getline(fin, c.lecturer.fullname, '\n');
            getline(fin, c.lecturer.degree, '\n');
            getline(fin, c.lecturer.gender, '\n');
            fin >> c.startdate.day;
            fin >> a;
            fin >> c.startdate.month;
            fin >> a;
            fin >> c.startdate.year;
            fin >> c.finishdate.day;
            fin >> a;
            fin >> c.finishdate.month;
            fin.ignore();
            fin >> c.finishdate.year;
            fin.ignore();
            getline(fin, c.dayinweek, '\n');
            fin >> c.starttime.hour;
            fin >> a;
            fin >> c.starttime.minute;
            fin >> c.finishtime.hour;
            fin >> a;
            fin >> c.finishtime.minute;
            fin.ignore();
            getline(fin, c.room, '\n');
                gotoXY(column, row);
                cout << c.name;
                gotoXY(column + 11, row);
                cout << c.fullname;
                gotoXY(column + 61, row);
                cout << c.classes;
                gotoXY(column + 70, row);
                cout << c.lecturer.fullname;
                gotoXY(column + 90, row);
                cout << c.lecturer.degree;
                gotoXY(column + 110, row);
                cout << c.dayinweek;
                gotoXY(column + 125, row);
                cout << c.starttime.hour << ":" << c.starttime.minute;
                gotoXY(column + 135, row);
                cout << c.finishtime.hour << ":" << c.finishtime.minute;
                gotoXY(column + 145, row);
                cout << c.room;
                row++;
        }
        fin.close();
    }
}

//20 View list of students in a course.
void viewListOfStudentInCourse(string filename){
    ifstream fin;
    fin.open(filename + ".txt")
    if(!fin.is_open()){
        cout << "\nCould not open the file " << filename << endl;
        return;
    }
    int n, choice;
    char n1;
    fin >> n;
    fin.ignore();
    string temp;
    studentinfile *s;
    s = new studentinfile[n];
    for(int i = 0; i < n; i++){
        getline(fin, s[i].id, ',');
        getline(fin, s[i].fullname, ',');
        getline(fin, s[i].sex, ',');
        getline(fin, s[i].classes, '\n');
    }
    fin.close();
    int column = 1, row = 10;
    gotoXY(column, row);
    cout << "ID" ;
    gotoXY(column + 20, row);
    cout <<"Full name";
    gotoXY(column + 60, row);
    cout <<"Gender";
    gotoXY(column + 80, row);
    cout <<"Classes";
    row++;
    for(int i = 0; i < n; i++){
        gotoXY(column, row);
        cout << s[i].id;
        gotoXY(column + 20, row);
        cout << s[i].fullname;
        gotoXY(column + 60, row);
        cout << s[i].sex;
        gotoXY(column + 80, row);
        cout << s[i].classes;
        row++;
    }
        delete [] s;
    system("Pause >nul");
}

//15 Remove a list from enrolled courses
void removeCourseFromEnrollList(course *c, int &n, string nameyear, string namesemester){
    cin.ignore();
    string namecourse;
    cout <<"What course do you want to the delete? (Ex: CS162-20CTT1)";
    getline(cin, namecourse, '\n');
    string x;
    cout <<"Enter 1 to delete the course " << namecourse << "or any key to return" << endl;
    getline(cin, x, '\n');
    if(x != 1) return;
    int count = 0;
    for(int i = 0; i < n; i++){
        if(a[i].id + "-" +a[i].classes == namecourse){
            int j = i - 1;
            for(int k = j; k < n; k++)
            a[k] = a[k + 1];

            delete a[n];
            n--;
        }
    }
    namecourse = nameyear + "-" + namesemester + "-" namecourse + ".txt";
    char *a = new char[n + 1];
    strcpy_s(a, n + 1, namecourse.c_str());
    remove(a);
    delete [] a;
}
//14 View List Of Enrolled courses
