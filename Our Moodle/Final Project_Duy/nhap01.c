int loginacc(string name, string pass) {
	ifstream f;
	string temp;
	f.open("login.txt");
	if (f.is_open()) {
		Loginacc acc;
		getline(f,temp,'\n');
		while (!f.eof()) {

			getline(f, acc.position, ',');
			getline(f, acc.name, ',');
			getline(f, acc.pass, '\n');
			if (acc.position == "student" && acc.name == name && acc.pass == pass) {
				{
					deleteRow(0, 80);

					currentlog = name;

					f.close();
					return 1; // 1 - Student
				}
			}
			else if (acc.position == "lecturer" && acc.name == name && acc.pass == pass) {
				deleteRow(0, 80);

				currentlog = name;
				f.close();
				return 2; //2- Lecturer

			}
			else if (acc.position == "staff" && acc.name == name && acc.pass == pass) {
				deleteRow(0, 80);

				currentlog = name;
				f.close();
				return 3; // 3- Staff
			}


		}
		cout << "Fail, please login again " << endl;

		system("pause");
		return 0;
	}
	else {
		cout << "sorry cannot open file";
	}

	system("pause >nul");

}
void forgotpassword(string name) {
	cin.ignore();
	ofstream of;
	ifstream f;
	int check = 0;
	string temp;
	f.open("login.txt");
	getline(f, temp, '\n');
	string tempname, temppass, temprole;
	while (!f.eof()) {
		getline(f, temprole, ',');
		getline(f, tempname, ',');
		getline(f, temppass, '\n');
		if (tempname == name) {
			of.open("forgotpass.csv", std::ofstream::app);
			if (of.is_open()) {
				of << name << ",";
				of << temppass << endl;
				check = 1;
				of.close();
				cout << "Your info has been sent to the staff. Please wait for the response from your email";
				break;
			}

		}
	}
	if (check == 0) {
		cout << "Cannot find your username. Please enter again";
	}
	f.close();
	system("pause >nul");

}

void option(int& i, int& pointer) {
	White(); //Change Text Color
	string startoption[2] = { "LOGIN","FORGOT PASS" };
	for (i; i < 2; i++) {

		if (i == pointer) {

			gotoXY(46, 6);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			cout << startoption[i];



		}
		else {
			gotoXY(67, 6);
			White();
			cout << startoption[i];
		}
	}
}
void Inputaccoount(int& n, string name, string pass, string re_enter, string newpass, int& pointer, int& Role) {
	cin.ignore();
	gotoXY(51, 9);
	LightMagenta();

	cout << "--User name--" << endl;
	gotoXY(51, 10);
	White();
	getline(cin, name);
	if (pointer == 0) {
		gotoXY(51, 12);
		LightMagenta();
		cout << "--Your Current Password--" << endl;
		gotoXY(51, 13);
		White();
		getline(cin, pass);
		gotoXY(25, 16);
		Red();
		cout << "Enter 0 to exit  || 1 to login || 2 to input again || 3 to switch to Forgot Password" << endl;
		White();
		gotoXY(51, 17);
		cin >> n;
	}
	else {
		gotoXY(25, 16);
		Red();
		cout << "Enter 0 to exit  || 1 to confirm || 2 to input again || 3 to switch to Login " << endl;
		White();
		gotoXY(51, 17);
		cin >> n;
	}

	deleteRow(15, 40);
	White();
	if (n == 0) {
		exit(0);
	}
	else if (n == 1) {

		if (pointer == 0) {
			deleteRow(0, 80);
			Role = loginacc(name, pass); //Check account in file
			return;
		}
		else {
			gotoXY(15, 16);
			Red();
			forgotpassword(name);
			White();

		}
	}
	else if (n == 3) {

		if (pointer == 0) {
			pointer = 1;
		}
		else if (pointer == 1) {
			pointer = 0;

		}

	}
	else {
		return;
	}
}

void clear()
{
	system("cls");
}

void Login(int& Role) {
	string name;
	string pass;
	string course;
	string newpass;
	string re_enter;
	deleteRow(0, 80);
	gotoXY(40, 15);
	Cyan();
	cout << "Welcome to the Student Management System! " << endl;
	Sleep(2000);
	deleteRow(0, 80);
	int pointer = 0;
	int n = 1;

	while (true) {
		deleteRow(0, 80);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
		cout << "                                               STUDENT MANAGEMENT SYSTEM";
		int i = 0;
		option(i, pointer);
		while (true) {

			if (GetAsyncKeyState(VK_RIGHT) != 0) //Take Keyboard event
			{
				pointer += 1;
				if (pointer == 2) {
					pointer = 0;
				}

				break;

			}
			else if (GetAsyncKeyState(VK_LEFT) != 0) {
				pointer -= 1;
				if (pointer == -1) {
					pointer = 0;

				}
				break;
			}
			else if (GetAsyncKeyState(VK_RETURN) != 0) {

				deleteRow(8, 40);

				if (pointer == 0 && i == 2) {
					//Log in
					Inputaccoount(n, name, pass, re_enter, newpass, pointer, Role);
					if (Role != 0) {
						return;
					}
					else {
						break;
					}
				}

				if (pointer == 1 && i == 2)
				{
					//Change password
					Inputaccoount(n, name, pass, re_enter, newpass, pointer, Role);

					break;
				}

				break;
			}

			Sleep(150);
			break;
		}

		Sleep(150);
	}

	system("pause >nul");

}

bool changepasswordacc(string account, string pass, string newpass) {
	cin.ignore();
	ifstream f;
	ofstream of;
	int check = 0;
	f.open("login.txt");
	if (f.is_open()) {

		int n;
		f >> n;
		Loginacc* acc;
		acc = new Loginacc[n];
		for (int i = 0; i < n; i++) {

			getline(f, acc[i].position, ',');
			getline(f, acc[i].name, ',');
			getline(f, acc[i].pass, '\n');
			if (acc[i].name == account && acc[i].pass == pass) {
				{
					acc[i].pass = newpass;
					check = 1;
					gotoXY(45, 21);
					Red();
					cout << "Your password has changed successfully! ";

				}
			}
		}
		if (check == 0) {
			{
				gotoXY(45, 21);
				Red();
				cout << "Fail, please enter password again " << endl;
				system("pause >nul");
				f.close();
				delete[]acc;
				return false;

			}
		}

		of.open("login.txt");
		if (of.is_open()) {
			of << n;
			for (int i = 0; i < n; i++) {

				of << acc[i].position << ',';
				of << acc[i].name << ',';
				of << acc[i].pass << '\n';

			}
			of.close();
		}
		else {
			cout << "sorry cannot open file";
			return false;
		}
		system("pause >nul");
		f.close();
		delete[]acc;
		return true;
	}
	else {
		cout << "sorry cannot open file";
		return false;
	}

}
void UIchangepass(string acc, string pass, string newpass) {

	newpass = "1";
	string re_enter = "0";
	bool check = false;
	while (re_enter != newpass || check == false) {
		clear();

		gotoXY(51, 12);
		LightMagenta();
		cout << "--Your Current Password--" << endl;
		gotoXY(51, 13);
		White();
		getline(cin, pass);
		White();
		gotoXY(51, 15);
		LightMagenta();
		cout << "--Your New Password--" << endl;
		gotoXY(51, 16);
		White();
		getline(cin, newpass);
		gotoXY(51, 18);
		LightMagenta();
		cout << "--Enter your new password again--" << endl;
		gotoXY(51, 19);
		White();
		getline(cin, re_enter);
		if (re_enter != newpass) {
			gotoXY(45, 21);
			Red();
			cout << "Please check again your new password!";
			system("pause >nul");
			continue;
		}

		check = changepasswordacc(acc, pass, newpass);
	}

}


