#include "student.h"
#include<QDebug>

student::student()                                                                            //构造函数
{

}

void student::Set(int num,QString nam, int sub1, int sub2)                                   //实现每个对象赋值
{
    number=num;
    name=nam;
    subject1=sub1;
    subject2=sub2;

}

void student::Printfirst()                                                                    //输出表头
{
    qDebug()<<"\t"<<"\t"<<"学号"<<"\t"<<"姓名"<<"\t"<<"\t"<<"课程1"<<"\t"<<"课程2";

}

void student::Print()                                                                         //输出每位学生的信息
{
    qDebug()<<"\t"<<number<<"\t"<<name<<"\t"<<subject1<<"\t"<<subject2;
}

bool student::name_sort(const student &t1, const student &t2)                                 //实现姓名比较
{
    if (t1.name>t2.name)
        return true;
    else
        return false;
}

bool student::sub1_sort(const student &t1, const student &t2)                                //实现课程1比较
{
    if (t1.subject1>t2.subject1)
        return true;
    else
        return false;
}

bool student::sub2_sort(const student &t1, const student &t2)                                //实现课程2比较
{
    if (t1.subject2>t2.subject2)
        return true;
    else
        return false;
}






