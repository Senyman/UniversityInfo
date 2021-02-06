#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string>

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string path = "myFile.txt";
    string pathLessons = "Lessons.txt";
    string pathStudents = "Students.txt";
    string pathRatings = "Ratings.txt";
    string bufferpathStudents = "BuffStud.txt";
    string bufferpathRatings = "BuffRatings.txt";
    string bufferpathLessons = "BufferLessons.txt";



    ofstream fout;   
    ofstream ratingsfout;
    ifstream fin;
    ifstream finRatings;
    ifstream finStudents;
    int a;
    int subjectscount = 0;
    int pupilcount = 0;

    do
    {
        subjectscount = 0;
        fin.open(pathLessons);       // ������� ���������� ���������
        if (!fin.is_open())
        {
            cout << "������ �������� �����" << endl;
        }
        else
        {
            string str;
            while (!fin.eof())
            {
                str = "";
                getline(fin, str);      // ���� ����� �� �����, �� ���� while ����������
                ++subjectscount;
            }
            fin.close();
        }

        pupilcount = 0;
        fin.open(pathStudents);     // ������� ���������� ���������  
        if (!fin.is_open())
        {
            cout << "������ �������� �����" << endl;
        }
        else
        {
            string str;
            while (!fin.eof())
            {
                str = "";
                getline(fin, str);      // ���� ����� �� �����, �� ���� while ����������
                ++pupilcount;
            }
            fin.close();
        }


        cout << "�� ������: " << endl
            << "2 - ������� ������ ������" << endl
            << "3 - ������������ ���� � �������" << endl
            << "4 - �������� ������� ������ �������" << endl
            << "5 - �������� �������� ���� � ��������� ���������������� �� ��������" << endl
            << "6 - �������� ������� ������� � ��� ������ � ���� ������" << endl
            << "7 - ������� ������ �� �������" << endl
            << "8 - �������� ������ � ��������"<<endl
            << "9 - ������� ������ � �������� � ������� ����� ��������" << endl
            << "0 - �����" << endl;
        cin >> a;

        if (a == 2 || a == 4)
        {
            fin.open(pathLessons);
            if (!fin.is_open())  // ��������, �������� �� ����
            {
                cout << "������ �������� �����" << endl;
            }
            else if (a == 2)
            {
                string str;
                cout << "\t";
                while (!fin.eof())      // ���� ���� ����� ���� ������ 
                {
                    str = "";
                    getline(fin, str);      // ��������� ������ �� fin � ���������� str
                    cout << str << " ";

                }
                cout << endl;

            }
            fin.close();

            fin.open(pathStudents);      //��������� ������� � ������
            finRatings.open(pathRatings);
            if (!fin.is_open() || !finRatings.is_open())  // ��������, �������� �� ����
            {
                cout << "������ �������� �����" << endl;
            }
            else
            {
                //cout << "���� ������� ������!" << endl;
                string str;
                string str2;

                if (a == 4)       // ������� ������ �������
                {
                    string enteredword;
                    cout << "������� ������� ������� �� ������������ � ����" << endl;
                    while (!fin.eof() && !finRatings.eof())      // ���� ���� ����� ���� ������ 
                    {
                        str = "";
                        getline(fin, str);      // ��������� ������ �� fin � ���������� str
                        getline(finRatings, str2); //??? �� ����
                        cout << str << endl;
                    }

                    fin.close();                // ��� �����, ������ ��� ���� ���������� eof, �� ��������� eof �� ����������, ��� ��� �� ����� ��������� ������ ������ ����� ������
                    fin.open(pathStudents);
                    finRatings.close();
                    finRatings.open(pathRatings);

                    cin >> enteredword;
                    while (!fin.eof() && !finRatings.eof())      // ���� ���� ����� ���� ������ 
                    {
                        str = "";
                        double first;
                        double summ = 0;
                        getline(fin, str);      // ��������� ������ �� fin � ���������� str
                        getline(finRatings, str2);
                        if (str == enteredword)         // ������� ������� ������ �� �������
                        {
                            for (int i = 0; i < str2.length(); i++)
                            {
                                if (str2[i] != ' ')
                                {
                                    first = (double)str2[i] - 48;
                                    summ += first;
                                }
                            }
                            cout << summ / subjectscount << endl;
                        }
                    }
                }

                else
                {
                    while (!fin.eof() && !finRatings.eof())      // ���� ���� ����� ���� ������ 
                    {
                        str = "";
                        getline(fin, str);      // ��������� ������ �� fin � ���������� str
                        getline(finRatings, str2);
                        cout << str << "\t";
                        cout << str2 << endl;

                    }

                }
                fin.close();
                finRatings.close();

            }
        }
        else if (a == 3)
        {
            fin.open(pathLessons);
            fout.open(path);
            if (!fin.is_open() && !fout.is_open())  // ��������, �������� �� ����
            {
                cout << "������ �������� �����" << endl;
            }
            else
            {
                string str;
                fout << "\t";
                while (!fin.eof())      // ���� ���� ����� ���� ������ 
                {
                    str = "";
                    getline(fin, str);      // ��������� ������ �� fin � ���������� str
                    fout << str << " ";    // ������� ������ �� ���������� str � ���� myFail ������� fout

                }
                fout << endl;
                fin.close();
            }

            fin.open(pathStudents);      //��������� ������� � ������
            finRatings.open(pathRatings);
            if (!fin.is_open() || !finRatings.is_open())  // ��������, �������� �� ����
            {
                cout << "������ �������� �����" << endl;
            }
            else
            {
                string str;
                string str2;

                while (!fin.eof() && !finRatings.eof())      // ���� ���� ����� ���� ������ 
                {
                    str = "";
                    str2 = "";
                    getline(fin, str);      // ��������� ������ �� fin � ���������� str
                    getline(finRatings, str2);
                    fout << str << "\t";
                    fout << str2 << endl;

                }
                fin.close();
                finRatings.close();
                fout.close();
            }
            cout << "���� �����" << endl << endl;
        }
        else if (a == 5)
        {
            fin.open(pathLessons);
            fout.open(path);
            if (!fin.is_open() || !fout.is_open())  // ��������, �������� �� ����
            {
                cout << "������ �������� �����" << endl;
            }
            else
            {
                cout << "���� ������� ������!" << endl;
                string str;
                fout << "\t";
                while (!fin.eof())          // ���� ���� ����� ���� ������ 
                {
                    str = "";
                    getline(fin, str);      // ��������� ������ �� fin � ���������� str
                    fout << str << " ";    // ������� ������ �� ���������� str � ���� myFail ������� fout

                }
                // fout << endl;
                fin.close();
            }

            fin.open(pathStudents);
            finRatings.open(pathRatings);
            if (!fin.is_open() || !finRatings.is_open())  // ��������, �������� �� ����
            {
                cout << "������ �������� �����" << endl;
            }
            else
            {
                //cout << "���� ������� ������!" << endl;
                string str;
                string str2;
                string* pupil = new string[pupilcount];       // ������ �������� ///////////////////////////////////////////////////////////////////////////////////////////
                string* allratings = new string[pupilcount];  // ������ ������ ��������  ////////////////////////
                int pupilnumber = 0;
                int* ppupilnumber = &pupilnumber;

                while (!fin.eof() && !finRatings.eof())      // ���� ���� ����� ���� ������ 
                {

                    str = "";
                    getline(fin, str);      // ��������� ������ �� ������� ��������� � ���������� str
                    getline(finRatings, str2);

                    //fout << str << "\t";
                    //fout << str2 << endl;
                    pupil[pupilnumber] = str;   // ��������� ������ �� �������� � ������
                    allratings[pupilnumber] = str2;
                    // cout << allratings[pupilnumber] << endl;

                    (*ppupilnumber)++;

                }
                string buffer;
                string ratingsbuffer;

                int nameindex;

                fout << endl;
                for (int i = 0; i < pupilcount; i++)              // ���������� �� ��������
                {
                    string minname = pupil[i];           // ���������� �������
                    char minchar = pupil[i][0];
                    nameindex = i;

                    string mratings = allratings[i];     // ���������� ������


                    for (int j = i + 1; j < pupilcount; j++)
                    {
                        if (pupil[j][0] < minchar)       // ���� ������ ������ ������ ���������� ����� ������ ������������, �� ��� � ���� �������� ���������� �����������
                        {
                            minchar = pupil[j][0];        // ����������� min ������ ��������
                            minname = pupil[j];            // ����
                            mratings = allratings[j];
                            nameindex = j;               // ������ min ��������
                        }
                    }
                    buffer = pupil[i];                   // ����� ��� �������� � ������
                    ratingsbuffer = allratings[i];

                    pupil[i] = minname;
                    allratings[i] = mratings;

                    pupil[nameindex] = buffer;
                    allratings[nameindex] = ratingsbuffer;
                    fout << pupil[i] << "\t";
                    fout << allratings[i] << endl;
                }
                delete[] pupil;
                delete[] allratings;

                fin.close();
                finRatings.close();
                fout.close();
            }
        }
        else if (a == 6)
        {
            fout.open(pathStudents, ofstream::app);    // � ������ ������ ������� ����, app - append - ��������, ��������� ����������� ����� ������ �� ������� ������
            ratingsfout.open(pathRatings, ofstream::app);

            if (!fout.is_open() && !ratingsfout.is_open())  // ��������, ��������� �� �����
            {
                cout << "������ �������� �����" << endl;
            }
            else
            {
                string allsubjects;     // ���������� ��� ������ � ������� ���������, �� ������� ���������� �������
                int subjectscount = 0;
                fin.open(pathLessons);
                if (!fin.is_open())  // ��������, �������� �� ����
                {
                    cout << "������ �������� �����" << endl;
                }
                else
                {
                    string str;
                    while (!fin.eof())      // ���� ���� ����� ���� ������ 
                    {
                        str = "";
                        getline(fin, str);      // ��������� ������ �� fin � ���������� str
                        allsubjects = allsubjects + str + " ";
                        subjectscount++;
                    }
                    fin.close();
                }
                string newsurname;
                string newpupilratings;
                cout << "������� �������" << endl;
                cin >> newsurname;
                fout << newsurname << endl;
                cout << "������� ������ ������� �� ��������� " << allsubjects << endl;
                cin >> newpupilratings;
                pupilcount++;
                ratingsfout << endl;
                for (int i = 0; i < subjectscount; i++)
                {
                    ratingsfout << newpupilratings[i] << "   ";
                }
            }
            fout.close();
            ratingsfout.close();
        }
        else if (a == 7)
        {
            fin.open(pathStudents);                 // ��������� ������� 
            finRatings.open(pathRatings);           // � ������ �� ������������ ������
            fout.open(bufferpathStudents);          // ��������� ��������� ���� ��� ������ ��������� ��� ����������
            ratingsfout.open(bufferpathRatings);    // � ������ ��� ����� ��������

            if (!fin.is_open() || !finRatings.is_open() || !fout.is_open() || !ratingsfout.is_open())  // ��������, ��������� �� �����
            {
                cout << "������ �������� �����" << endl;
            }
            else
            {
                string str;     // � ��� ������ ������������ ������ �� ������
                string str2;
                string enteredword;
                string allpupils;

                while (!fin.eof())      // ���� ���� ����� ���� ������ 
                {
                    str = "";
                    getline(fin, str);
                    allpupils = allpupils + str + " ";
                }
                cout << "������� ������� ������� �� ������������ � ����: " << endl << allpupils << endl;      // �������� ������ �������
                cin >> enteredword;

                fin.close();
                fin.open(pathStudents);

                while (!fin.eof() && !finRatings.eof())      // ���� ���� ����� ���� ������ 
                {
                    str2 = "";
                    str = "";
                    getline(fin, str);          // ��������� �������
                    getline(finRatings, str2);  // � ������
                    if (str != enteredword)
                    {
                        fout << str << endl;
                        ratingsfout << str2 << endl;
                    }
                }

                fin.close();
                finRatings.close();
                fout.close();
                ratingsfout.close();
                remove("Students.txt");                     // ������� ������ 2 ����� 
                remove("Ratings.txt");
                rename("BuffStud.txt", "Students.txt");     // �������� ����� 2 ����� ������������� � ������
                rename("BuffRatings.txt", "Ratings.txt");
                remove("BuffStud.txt");                     // ������� ����� 2 ����� 
                remove("BuffRatings.txt");
            }
        }
        else if (a == 8)
        {


            ratingsfout.open(bufferpathRatings);                // ��������� �������� ���� � �������� ��� ������
            finRatings.open(pathRatings);                       // ��������� ���� � �������� ��� ������ 
            fin.open(pathStudents);                             // ��������� ���� � ��������� ��� ����������� ����� ��� ������� �������� �������� ������ �� ������ ��������

            fout.open(pathLessons, ofstream::app);         // ��������� ���� � ����������
            if (!fout.is_open()|| !ratingsfout.is_open() || !fin.is_open() || !finRatings.is_open())
            {
                cout << "������ �������� �����" << endl;
            }
            else
            {
                string subject;                                     // ���������� ��������
                cout << "������� ����������� �������� (3 �����)"<<endl;
                cin >> subject;
                fout << endl << subject;
                fout.close();

                string pupilratings;
                string newpupilratings;
                string pupil;
                while (!fin.eof())
                {
                    pupilratings = "";
                    pupil = "";
                    newpupilratings = "";
                    getline(fin, pupil);
                    cout << "������� ������ �������: " << pupil << endl;
                    cin >> newpupilratings;

                    getline(finRatings, pupilratings);      // ��������� ������ ��� ������� �������
                    ratingsfout << pupilratings + "   " + newpupilratings << endl;     // ������� ������ � �������� ���� � ���������� ����� ������
                }
                ratingsfout.close();
                finRatings.close();
                fin.close();
                remove("Ratings.txt");
                rename("BuffRatings.txt", "Ratings.txt");                                             
            }
        }
        else if (a == 9)
        {
            fin.open(pathLessons);
            finRatings.open(pathRatings);
            fout.open(bufferpathLessons);
            ratingsfout.open(bufferpathRatings);
        
            string ratings;
            string str;
            string lessons = "";
            string enteredlesson ="";
            string result = "";
            int strcount=0;
            int deletedchars = 0;
        
            while (!fin.eof())
            {
                str = "";
                getline(fin, str);
                lessons = lessons + str + " ";
            }
            fin.close();
            fin.open(pathLessons);
            if(!fin.is_open()|| !finRatings.is_open() ||!fout.is_open()|| !ratingsfout.is_open())  cout << "������ �������� �����" << endl;
            else
            {
                cout << "������� ������� �� ������������ � ����: " << lessons << endl;
                cin >> enteredlesson;
                while (!fin.eof())
                {
                    str = "";
                    getline(fin, str);          // ���������� � str �������� ��������
                    strcount++;                 // ����������� ������� ��������� �� ����� ������
                    if (enteredlesson != str )  // ���� �������� ������� �� ����� �� ������ �� ���������� � ����
                    {
                        fout << str << endl;    // � ����� ���� �������� ��� �������� ���������, ����� ����, ������� ���� �������   
                    }
                    else deletedchars = (strcount-1)*4;   // ���� ������� = �������� � ���� ������
                }

                while (!finRatings.eof())       // ���������� ������ � ����� ���� ��� ������ ���������� ��������
                {
                    ratings = "";
                    result = "";
                    getline(finRatings, ratings);
                    cout << ratings.length() << endl;
                    for (int i = 0; i < ratings.length(); i++)
                    {
                        // ���� ��������� ������� ������ = ��������� ������� ���������� ��������, �� ������� ������ � 3 ������� ���� ���( ����� � ������, ���� ������ ������ �������)

                        if (i == deletedchars || i == deletedchars - 1 || i == deletedchars - 2 || i == deletedchars - 3)   // ���� � ������ �� ������ �������
                        {}
                        else if(deletedchars!=0)
                        {
                            ratingsfout << ratings[i];
                            cout << ratings[i];
                        }

                        if (i == deletedchars || i == deletedchars + 1 || i == deletedchars + 2 || i == deletedchars + 3)   // ���� � ������ ������ �������
                        {
                        }
                        else if (deletedchars == 0)
                        {
                            ratingsfout << ratings[i];
                            cout << ratings[i];
                        }
                    }
                    ratingsfout << endl;
                }
                fout.close();
                fin.close();
                remove("Lessons.txt");
                rename("BufferLessons.txt", "Lessons.txt");
                remove("BufferLessons.txt");                // ������� ��������

                ratingsfout.close();
                finRatings.close();
                remove("Ratings.txt");
                rename("BuffRatings.txt", "Ratings.txt");
                remove("BuffRatings.txt");
            }
        }
        else exit(0);
    }
    while (a);
}

