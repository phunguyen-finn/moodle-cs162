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
