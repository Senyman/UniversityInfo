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
        fin.open(pathLessons);       // Считаем количество предметов
        if (!fin.is_open())
        {
            cout << "Ошибка открытия файла" << endl;
        }
        else
        {
            string str;
            while (!fin.eof())
            {
                str = "";
                getline(fin, str);      // Если этого не будет, то цикл while бесконечен
                ++subjectscount;
            }
            fin.close();
        }

        pupilcount = 0;
        fin.open(pathStudents);     // Считаем количиство студентов  
        if (!fin.is_open())
        {
            cout << "Ошибка открытия файла" << endl;
        }
        else
        {
            string str;
            while (!fin.eof())
            {
                str = "";
                getline(fin, str);      // Если этого не будет, то цикл while бесконечен
                ++pupilcount;
            }
            fin.close();
        }


        cout << "Вы хотите: " << endl
            << "2 - Вывести данные файлов" << endl
            << "3 - Сформировать файл с данными" << endl
            << "4 - Получить среднюю оценку ученика" << endl
            << "5 - Получить отчетный файл с фамилиями отсортированными по алфавиту" << endl
            << "6 - Добавить фамилию ученика и его оценки в базу данных" << endl
            << "7 - Удалить данные об ученике" << endl
            << "8 - Добавить данные о предмете"<<endl
            << "9 - Удалить данные о предмете и оценках этого предмета" << endl
            << "0 - Выйти" << endl;
        cin >> a;

        if (a == 2 || a == 4)
        {
            fin.open(pathLessons);
            if (!fin.is_open())  // Проверка, открылся ли файл
            {
                cout << "Ошибка открытия файла" << endl;
            }
            else if (a == 2)
            {
                string str;
                cout << "\t";
                while (!fin.eof())      // Пока есть какие либо данные 
                {
                    str = "";
                    getline(fin, str);      // Считывает данные из fin в переменную str
                    cout << str << " ";

                }
                cout << endl;

            }
            fin.close();

            fin.open(pathStudents);      //Считываем фамилии и оценки
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

                if (a == 4)       // Средняя оценка ученика
                {
                    string enteredword;
                    cout << "Введите фамилию ученика из существующих в базе" << endl;
                    while (!fin.eof() && !finRatings.eof())      // Пока есть какие либо данные 
                    {
                        str = "";
                        getline(fin, str);      // Считывает данные из fin в переменную str
                        getline(finRatings, str2); //??? не надо
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
                        double summ = 0;
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
                            cout << summ / subjectscount << endl;
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
            if (!fin.is_open() && !fout.is_open())  // Проверка, открылся ли файл
            {
                cout << "Ошибка открытия файла" << endl;
            }
            else
            {
                string str;
                fout << "\t";
                while (!fin.eof())      // Пока есть какие либо данные 
                {
                    str = "";
                    getline(fin, str);      // Считывает данные из fin в переменную str
                    fout << str << " ";    // Выводим данные из переменной str в файл myFail объекта fout

                }
                fout << endl;
                fin.close();
            }

            fin.open(pathStudents);      //Считыывем фамилии и оценки
            finRatings.open(pathRatings);
            if (!fin.is_open() || !finRatings.is_open())  // Проверка, открылся ли файл
            {
                cout << "Ошибка открытия файла" << endl;
            }
            else
            {
                string str;
                string str2;

                while (!fin.eof() && !finRatings.eof())      // Пока есть какие либо данные 
                {
                    str = "";
                    str2 = "";
                    getline(fin, str);      // Считывает данные из fin в переменную str
                    getline(finRatings, str2);
                    fout << str << "\t";
                    fout << str2 << endl;

                }
                fin.close();
                finRatings.close();
                fout.close();
            }
            cout << "Файл готов" << endl << endl;
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
                    fout << str << " ";    // Выводим данные из переменной str в файл myFail объекта fout

                }
                // fout << endl;
                fin.close();
            }

            fin.open(pathStudents);
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
                string* pupil = new string[pupilcount];       // Массив учеников ///////////////////////////////////////////////////////////////////////////////////////////
                string* allratings = new string[pupilcount];  // Массив оценок учеников  ////////////////////////
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
                string buffer;
                string ratingsbuffer;

                int nameindex;

                fout << endl;
                for (int i = 0; i < pupilcount; i++)              // Сортировка по алфавиту
                {
                    string minname = pupil[i];           // Сортировка фамилий
                    char minchar = pupil[i][0];
                    nameindex = i;

                    string mratings = allratings[i];     // Сортировка оценок


                    for (int j = i + 1; j < pupilcount; j++)
                    {
                        if (pupil[j][0] < minchar)       // если первый символ любого следующего слова меньше минимального, то имя с этим символом становится минимальным
                        {
                            minchar = pupil[j][0];        // Присваиваем min новому элементу
                            minname = pupil[j];            // Тоже
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
                delete[] pupil;
                delete[] allratings;

                fin.close();
                finRatings.close();
                fout.close();
            }
        }
        else if (a == 6)
        {
            fout.open(pathStudents, ofstream::app);    // В первый запуск создаст файл, app - append - добавить, позволяет добавляться новые данные не затирая старые
            ratingsfout.open(pathRatings, ofstream::app);

            if (!fout.is_open() && !ratingsfout.is_open())  // Проверка, открылись ли файлы
            {
                cout << "Ошибка открытия файла" << endl;
            }
            else
            {
                string allsubjects;     // Переменная для вывода в консоль предметов, по которым занимаются ученики
                int subjectscount = 0;
                fin.open(pathLessons);
                if (!fin.is_open())  // Проверка, открылся ли файл
                {
                    cout << "Ошибка открытия файла" << endl;
                }
                else
                {
                    string str;
                    while (!fin.eof())      // Пока есть какие либо данные 
                    {
                        str = "";
                        getline(fin, str);      // Считывает данные из fin в переменную str
                        allsubjects = allsubjects + str + " ";
                        subjectscount++;
                    }
                    fin.close();
                }
                string newsurname;
                string newpupilratings;
                cout << "Введите фамилию" << endl;
                cin >> newsurname;
                fout << newsurname << endl;
                cout << "Введите оценки ученика по предметам " << allsubjects << endl;
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
            fin.open(pathStudents);                 // Считываем фамилии 
            finRatings.open(pathRatings);           // и оценки из существующих файлов
            fout.open(bufferpathStudents);          // Открываем буфферные фалы для записи студентов без удаленного
            ratingsfout.open(bufferpathRatings);    // и оценок для этого студента

            if (!fin.is_open() || !finRatings.is_open() || !fout.is_open() || !ratingsfout.is_open())  // Проверка, открылись ли файлы
            {
                cout << "Ошибка открытия файла" << endl;
            }
            else
            {
                string str;     // В эти строки записываются данные из файлов
                string str2;
                string enteredword;
                string allpupils;

                while (!fin.eof())      // Пока есть какие либо данные 
                {
                    str = "";
                    getline(fin, str);
                    allpupils = allpupils + str + " ";
                }
                cout << "Введите фамилию ученика из существующих в базе: " << endl << allpupils << endl;      // Которого хотите удалить
                cin >> enteredword;

                fin.close();
                fin.open(pathStudents);

                while (!fin.eof() && !finRatings.eof())      // Пока есть какие либо данные 
                {
                    str2 = "";
                    str = "";
                    getline(fin, str);          // Считывает фамилии
                    getline(finRatings, str2);  // и оценки
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
                remove("Students.txt");                     // Удалить старые 2 файла 
                remove("Ratings.txt");
                rename("BuffStud.txt", "Students.txt");     // Копируем новые 2 файла переименовать в старые
                rename("BuffRatings.txt", "Ratings.txt");
                remove("BuffStud.txt");                     // Удалить новые 2 файла 
                remove("BuffRatings.txt");
            }
        }
        else if (a == 8)
        {


            ratingsfout.open(bufferpathRatings);                // Открываем буферный файл с оценками для записи
            finRatings.open(pathRatings);                       // Открываем файл с оценками для чтения 
            fin.open(pathStudents);                             // Открываем файл с учениками для составления цикла для каждого студента добавить оценку по новому предмету

            fout.open(pathLessons, ofstream::app);         // Открываем файл с предметами
            if (!fout.is_open()|| !ratingsfout.is_open() || !fin.is_open() || !finRatings.is_open())
            {
                cout << "Ошибка открытия файла" << endl;
            }
            else
            {
                string subject;                                     // Добавление предмета
                cout << "Введите абривиатуру предмета (3 буквы)"<<endl;
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
                    cout << "Введите оценку ученика: " << pupil << endl;
                    cin >> newpupilratings;

                    getline(finRatings, pupilratings);      // Считываем оценки для каждого ученика
                    ratingsfout << pupilratings + "   " + newpupilratings << endl;     // Выводим данные в буферный файл и прибовляем новую оценку
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
            if(!fin.is_open()|| !finRatings.is_open() ||!fout.is_open()|| !ratingsfout.is_open())  cout << "Ошибка открытия файла" << endl;
            else
            {
                cout << "Введите предмет из существующих в базе: " << lessons << endl;
                cin >> enteredlesson;
                while (!fin.eof())
                {
                    str = "";
                    getline(fin, str);          // Записываем в str название предмета
                    strcount++;                 // Увеличиваем счетчик переходов на новую строку
                    if (enteredlesson != str )  // Если введеный предмет не равен ни одному из хранящихся в базу
                    {
                        fout << str << endl;    // В новый файл добавляю все названия предметов, кроме того, который хочу удалить   
                    }
                    else deletedchars = (strcount-1)*4;   // Если предмет = предмету в базе данных
                }

                while (!finRatings.eof())       // Добавление оценок в новый файл без оценок удаленного предмета
                {
                    ratings = "";
                    result = "";
                    getline(finRatings, ratings);
                    cout << ratings.length() << endl;
                    for (int i = 0; i < ratings.length(); i++)
                    {
                        // если положение текущей оценки = положению символа удаленного предмета, то удаляем оценку и 3 символа пред ним( после с случае, кода первый символ нулевой)

                        if (i == deletedchars || i == deletedchars - 1 || i == deletedchars - 2 || i == deletedchars - 3)   // Если я удаляю не первый предмет
                        {}
                        else if(deletedchars!=0)
                        {
                            ratingsfout << ratings[i];
                            cout << ratings[i];
                        }

                        if (i == deletedchars || i == deletedchars + 1 || i == deletedchars + 2 || i == deletedchars + 3)   // Если я удаляю первый предмет
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
                remove("BufferLessons.txt");                // Изменил предметы

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

