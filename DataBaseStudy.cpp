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


    ofstream fout;     
    ifstream fin;
    ifstream finRatings;
    int a;
    int ratingscount = 4;

    do 
    {
        cout << "�� ������: " << endl
            << "2 - �������, ��� ��������� � �����" << endl
            << "3 - ������������ ���� � �������" << endl
            << "4 - �������� ������� ������ �������" << endl
            << "5 - �������� �������� ���� � ��������� ���������������� �� ��������"<<endl
            << "6 - �������� ������� � ��� ������ � ���� ������"<<endl
            << "0 - �����" << endl;
        cin >> a;


        if (a == 2 || a==4)
        {
            fin.open(pathLessons);
            if (!fin.is_open())  // ��������, �������� �� ����
            {
                cout << "������ �������� �����" << endl;
            }
            else if(a==2)
            {
                cout << "���� ������� ������!" << endl;
                string str;
                cout << "\t";
                while (!fin.eof())      // ���� ���� ����� ���� ������ 
                {
                    str = "";
                    getline(fin, str);      // ��������� ������ �� fin � ���������� str
                    cout << str << endl;

                }
                
            }
            fin.close();

            fin.open(pathStudents);      //��������� ������� � ������
            finRatings.open(pathRatings);
            if (!fin.is_open()|| !finRatings.is_open())  // ��������, �������� �� ����
            {
                cout << "������ �������� �����" << endl;
            }
            else
            {
                //cout << "���� ������� ������!" << endl;
                string str;
                string str2;

                if (a==4)       // ������� ������ �������
                {
                    string enteredword;
                    cout << "������� ������� ������� �� ������������ � ����" << endl;
                    while (!fin.eof() && !finRatings.eof())      // ���� ���� ����� ���� ������ 
                    {
                        str = "";
                        getline(fin, str);      // ��������� ������ �� fin � ���������� str
                        getline(finRatings, str2);
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
                        double summ=0;
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
                            cout << summ/ratingscount << endl;
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
            if (!fin.is_open()|| !fout.is_open())  // ��������, �������� �� ����
            {
                cout << "������ �������� �����" << endl;
            }
            else
            {
                cout << "���� ������� ������!" << endl;
                string str;
                fout << "\t";
                while (!fin.eof())      // ���� ���� ����� ���� ������ 
                {
                    str = "";
                    getline(fin, str);      // ��������� ������ �� fin � ���������� str
                    fout << str << endl;    // ������� ������ �� ���������� str � ���� myFail ������� fout

                }
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
                //cout << "���� ������� ������!" << endl;
                string str;
                string str2;

                while (!fin.eof() && !finRatings.eof())      // ���� ���� ����� ���� ������ 
                {
                    str = "";
                    getline(fin, str);      // ��������� ������ �� fin � ���������� str
                    getline(finRatings, str2);
                    fout << str << "\t";
                    fout << str2 << endl;

                }
                fin.close();
                finRatings.close();
                fout.close();
            }
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
                fout << str << endl;    // ������� ������ �� ���������� str � ���� myFail ������� fout

            }
            fin.close();
        }

        fin.open(pathStudents);         //��������� ������� � ������
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
            string pupil[5] = {};       // ������ ��������
            string allratings[5] = {};  // ������ ������ ��������
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
            string buffer ;
            string ratingsbuffer;
            
            int nameindex;
            

           for (int i = 0; i < 5; i++)              // ���������� �� ��������
            {
               string minname = pupil[i];           // ���������� �������
               char minchar = pupil[i][0];
               nameindex = i;

               string mratings = allratings[i];     // ���������� ������
               

               for (int j = i+1; j < 5; j++)
               {
                   if (pupil[j][0] < minchar)       // ���� ������ ������ ������ ���������� ����� ������ ������������, �� ��� � ���� �������� ���������� �����������
                   {
                       minchar= pupil[j][0];        // ����������� min ������ ��������
                       minname=pupil[j];            // ����
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
            fin.close();
            finRatings.close();
            fout.close();
        }
        }
        else if (a == 6)
        {
        fout.open(path, ofstream::app);    // � ������ ������ ������� ����, app - append - ��������, ��������� ����������� ����� ������ �� ������� ������
        if (!fout.is_open())  // ��������, �������� �� ����
        {
            cout << "������ �������� �����" << endl;
        }
        else
        {
            string b;
            cout << "������� ������" << endl;
            cin >> b;
            fout << b << endl;

        }
        fout.close();
        }
        else exit(0);
    }
    while (a);
}

