#include <QCoreApplication>
#include<QList>
#include<QDebug>
#include<QVector>
#include "student.h"                                              //class student头文件

void print(QVector <student> stu);                                //输出函数声明
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QVector <student> stu(4);                                     //开辟student类型的容器空间
    stu[0].Set(1403140103,"武松",88,80);                          //调用成员函数Set,赋值
    stu[1].Set(1403140101,"林冲",82,76);
    stu[2].Set(1403130209,"鲁智深",80,72);
    stu[3].Set(1403140102,"宋江",76,85);
    qDebug()<<"原数据排序如下：";
    print(stu);                                                  //调用输出函数print输出原数据
    qDebug()<<"按照姓名排序如下：";
    std::sort(stu.begin(),stu.end(), student::name_sort);        //使用sort函数并调用成员函数name_sort进行按照姓名排序
    print(stu);                                                  //调用输出函数输出当前按照姓名排序的数据
    qDebug()<<"按照课程1排序如下：";
    std::sort(stu.begin(),stu.end(), student::sub1_sort);        //使用sort函数并调用成员函数sub1_sort进行按照姓名排序
    print(stu);                                                  //调用输出函数输出当前按照课程1排序的数据
    qDebug()<<"按照课程2排序如下：";
    std::sort(stu.begin(),stu.end(), student::sub2_sort);        //使用sort函数并调用成员函数sub2_sort进行按照姓名排序
    print(stu);                                                  //调用输出函数输出当前按照课程2排序的数据
    return 0;

}

void print(QVector <student> stu)                                //输出函数实现
{
    stu[0].Printfirst();                                         //调用成员函数Printfirst输出
    for (int i=0;i<sizeof(stu);i++)
        {
            stu[i].Print();                                      //调用成员函数Print输出
        }
}
