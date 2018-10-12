#ifndef STUDENT_H
#define STUDENT_H
#include<QString>


class student
{
public:
    student();
    void Set(int,QString,int,int);
    void Printfirst();
    void Print();
    bool static name_sort(const student &t1,const student &t2);
    bool static sub1_sort(const student &t1,const student &t2);
    bool static sub2_sort(const student &t1,const student &t2);



private:
    int number;
    QString name;
    int subject1;
    int subject2;

};


#endif // STUDENT_H
