#ifndef STUDENT_H
#define STUDENT_H
#include<QString>

class student                                                         //创建student类
{
public:
    student();                                                        //构造函数
    void Set(int,QString,int,int);                                    //赋值函数
    void Printfirst();                                                //输出表头函数
    void Print();                                                     //输出每个学生信息函数
    bool static name_sort(const student &t1,const student &t2);       //按照姓名比较大小的函数
    bool static sub1_sort(const student &t1,const student &t2);       //按照课程1比较大小的函数
    bool static sub2_sort(const student &t1,const student &t2);       //按照课程2比较大小的函数

private:
    int number;                                                       //私有 学号
    QString name;                                                     //私有 姓名
    int subject1;                                                     //私有 课程1
    int subject2;                                                     //私有 课程2

};


#endif // STUDENT_H
