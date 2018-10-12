#include <QCoreApplication>
#include<QList>
#include<QDebug>
#include<QVector>
#include "student.h"

void print(QVector <student> stu);
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QVector <student> stu(4);
    student temp;
    stu[0].Set(1403140103,"武松",88,80);
    stu[1].Set(1403140101,"林冲",82,76);
    stu[2].Set(1403130209,"鲁智深",80,72);
    stu[3].Set(1403140102,"宋江",76,85);
    qDebug()<<"原数据排序如下：";
    print(stu);
    qDebug()<<"按照姓名排序如下：";
    std::sort(stu.begin(),stu.end(), student::name_sort);
    print(stu);
    qDebug()<<"按照课程1排序如下：";
    std::sort(stu.begin(),stu.end(), student::sub1_sort);
    print(stu);
    qDebug()<<"按照课程2排序如下：";
    std::sort(stu.begin(),stu.end(), student::sub2_sort);
    print(stu);
    return 0;

}

void print(QVector <student> stu)
{
    stu[0].Printfirst();
    for (int i=0;i<sizeof(stu);i++)
        {
            stu[i].Print();
        }
}
