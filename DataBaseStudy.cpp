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
        cout << "Вы хотите: " << endl
            << "2 - Увидеть, что находится в файле" << endl
            << "3 - Сформировать файл с данными" << endl
            << "4 - Получить среднюю оценку ученика" << endl
            << "5 - Получить отчетный файл с фамилиями отсортированными по алфавиту"<<endl
            << "6 - Добавить ученика и его оценки в базу данных"<<endl
            << "0 - Выйти" << endl;
        cin >> a;


        if (a == 2 || a==4)
        {
            fin.open(pathLessons);
            if (!fin.is_open())  // Проверка, открылся ли файл
            {
                cout << "Ошибка открытия файла" << endl;
            }
            else if(a==2)
            {
                cout << "Файл успешно открыт!" << endl;
                string str;
                cout << "\t";
                while (!fin.eof())      // Пока есть какие либо данные 
                {
                    str = "";
                    getline(fin, str);      // Считывает данные из fin в переменную str
                    cout << str << endl;

                }
                
            }
            fin.close();

            fin.open(pathStudents);      //Считываем фамилии и оценки
            finRatings.open(pathRatings);
            if (!fin.is_open()|| !finRatings.is_open())  // Проверка, открылся ли файл
            {
                cout << "Ошибка открытия файла" << endl;
            }
            else
            {
                //cout << "Файл успешно открыт!" << endl;
                string str;
                string str2;

                if (a==4)       // Средняя оценка ученика
                {
                    string enteredword;
                    cout << "Введите фамилию ученика из существующих в базе" << endl;
                    while (!fin.eof() && !finRatings.eof())      // Пока есть какие либо данные 
                    {
                        str = "";
                        getline(fin, str);      // Считывает данные из fin в переменную str
                        getline(finRatings, str2);
                        cout << str << endl;
                    }

                    fin.close();                // Это нужно, потому что если происходит eof, то следующий eof не произойдет, так как он будет считывать пустые данные после данных
                    fin.open(pathStudents);
                    finRatings.close();
                    finRatings.open(pathRatings);

                    cin >> enteredword;
                    while (!fin.eof() && !finRatings.eof())      // Пока есть какие либо данные 
                    {
                        str = "";
                        double first;
                        double summ=0;
                        getline(fin, str);      // Считывает данные из fin в переменную str
                        getline(finRatings, str2);
                        if (str == enteredword)         // Выводим среднюю оценку по фамилии
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
                    while (!fin.eof() && !finRatings.eof())      // Пока есть какие либо данные 
                    {
                        str = "";
                        getline(fin, str);      // Считывает данные из fin в переменную str
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
            if (!fin.is_open()|| !fout.is_open())  // Проверка, открылся ли файл
            {
                cout << "Ошибка открытия файла" << endl;
            }
            else
            {
                cout << "Файл успешно открыт!" << endl;
                string str;
                fout << "\t";
                while (!fin.eof())      // Пока есть какие либо данные 
                {
                    str = "";
                    getline(fin, str);      // Считывает данные из fin в переменную str
                    fout << str << endl;    // Выводим данные из переменной str в файл myFail объекта fout

                }
                fin.close();
            }

            fin.open(pathStudents);      //Добавляем фамилии и оценки
            finRatings.open(pathRatings);
            if (!fin.is_open() || !finRatings.is_open())  // Проверка, открылся ли файл
            {
                cout << "Ошибка открытия файла" << endl;
            }
            else
            {
                //cout << "Файл успешно открыт!" << endl;
                string str;
                string str2;

                while (!fin.eof() && !finRatings.eof())      // Пока есть какие либо данные 
                {
                    str = "";
                    getline(fin, str);      // Считывает данные из fin в переменную str
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
        if (!fin.is_open() || !fout.is_open())  // Проверка, открылся ли файл
        {
            cout << "Ошибка открытия файла" << endl;
        }
        else
        {
            cout << "Файл успешно открыт!" << endl;
            string str;
            fout << "\t";
            while (!fin.eof())          // Пока есть какие либо данные 
            {
                str = "";
                getline(fin, str);      // Считывает данные из fin в переменную str
                fout << str << endl;    // Выводим данные из переменной str в файл myFail объекта fout

            }
            fin.close();
        }

        fin.open(pathStudents);         //Добавляем фамилии и оценки
        finRatings.open(pathRatings);
        if (!fin.is_open() || !finRatings.is_open())  // Проверка, открылся ли файл
        {
            cout << "Ошибка открытия файла" << endl;
        }
        else
        {
            //cout << "Файл успешно открыт!" << endl;
            string str;
            string str2;
            string pupil[5] = {};       // Массив учеников
            string allratings[5] = {};  // Массив оценок учеников
            int pupilnumber = 0;
            int* ppupilnumber = &pupilnumber;

            while (!fin.eof() && !finRatings.eof())      // Пока есть какие либо данные 
            {
               
                str = "";
                getline(fin, str);      // Считывает данные из Фамилий студентов в переменную str
                getline(finRatings, str2);

                //fout << str << "\t";
                //fout << str2 << endl;
                pupil[pupilnumber] = str;   // Записываю данные об учениках в массив
                allratings[pupilnumber] = str2;
                // cout << allratings[pupilnumber] << endl;

                (*ppupilnumber)++;

            }
            string buffer ;
            string ratingsbuffer;
            
            int nameindex;
            

           for (int i = 0; i < 5; i++)              // Сортировка по алфавиту
            {
               string minname = pupil[i];           // Сортировка фамилий
               char minchar = pupil[i][0];
               nameindex = i;

               string mratings = allratings[i];     // Сортировка оценок
               

               for (int j = i+1; j < 5; j++)
               {
                   if (pupil[j][0] < minchar)       // если первый символ любого следующего слова меньше минимального, то имя с этим символом становится минимальным
                   {
                       minchar= pupil[j][0];        // Присваиваем min новому элементу
                       minname=pupil[j];            // Тоже
                       mratings = allratings[j];
                       nameindex = j;               // Индекс min элемента
                   }   
               }
               buffer = pupil[i];                   // Буфер для учеников и оценок
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
        fout.open(path, ofstream::app);    // В первый запуск создаст файл, app - append - добавить, позволяет добавляться новые данные не затирая старые
        if (!fout.is_open())  // Проверка, открылся ли файл
        {
            cout << "Ошибка открытия файла" << endl;
        }
        else
        {
            string b;
            cout << "Введите ченить" << endl;
            cin >> b;
            fout << b << endl;

        }
        fout.close();
        }
        else exit(0);
    }
    while (a);
}

