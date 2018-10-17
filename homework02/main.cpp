#include <QDebug>
#include <QList>
#include <QTextStream>
#include <QString>
#include <QFile>
namespace SK {
enum SortKind{
    col01    =   0x00000001<<0,         //!< 第1列
    col02    =   0x00000001<<1,         //!< 第2列
    col03    =   0x00000001<<2,         //!< 第3列
    col04    =   0x00000001<<3,         //!< 第4列
    col05    =   0x00000001<<4,         //!< 第5列
    col06    =   0x00000001<<5,         //!< 第6列
    col07    =   0x00000001<<6,         //!< 第7列
    col08    =   0x00000001<<7,         //!< 第8列
    col09    =   0x00000001<<8,         //!< 第9列
    col10    =   0x00000001<<9,         //!< 第10列
    col11    =   0x00000001<<10,        //!< 第11列
    col12    =   0x00000001<<11,        //!< 第12列
    col13    =   0x00000001<<12,        //!< 第13列
    col14    =   0x00000001<<13,        //!< 第14列
    col15    =   0x00000001<<14,        //!< 第15列
    col16    =   0x00000001<<15,        //!< 第16列
    col17    =   0x00000001<<16,        //!< 第17列
    col18    =   0x00000001<<17,        //!< 第18列
    col19    =   0x00000001<<18,        //!< 第19列
    col20    =   0x00000001<<19,        //!< 第20列
    col21    =   0x00000001<<20,        //!< 第21列
    col22    =   0x00000001<<21,        //!< 第22列
    col23    =   0x00000001<<22,        //!< 第23列
    col24    =   0x00000001<<23,        //!< 第24列
    col25    =   0x00000001<<24,        //!< 第25列
    col26    =   0x00000001<<25,        //!< 第26列
    col27    =   0x00000001<<26,        //!< 第27列
    col28    =   0x00000001<<27,        //!< 第28列
    col29    =   0x00000001<<28,        //!< 第29列
    col30    =   0x00000001<<29,        //!< 第30列
    col31    =   0x00000001<<30,        //!< 第31列
    col32    =   0x00000001<<31,        //!< 第32列
};
}

typedef struct
{
    QStringList stu;                                                             //定义一个字符串列表类的 stu

} stuData;

QDebug operator<< (QDebug d, const stuData &data)                                //运算符<<重载
{
   QDebugStateSaver saver(d);                                                    //在自定义QDebug运算符时，先保存QDebug当前设置，当saver对象，超出作用域进行析构时，会自动恢复QDebug的状态
   for(int i=0;i<data.stu.size();i++)
    {
        d.noquote().nospace()<<data.stu.at(i)<<"\t";                            //按照要求分别输出一行的学生数据
    }
       return d;
}

class myCmp//比较类，用于std::sort第三参数
{
public:
    myCmp(int selectedColumn)
    {
        currentColumn = selectedColumn;                                         //在构造函数中初始化
    }
    bool operator() (const stuData& d1,const stuData& d2);                      //函数排序依据的声明
private:
    int currentColumn;                                                          //定义当前列
};

bool myCmp::operator()(const stuData &d1, const stuData &d2)                    //进行对排序依据的实现
{
    bool result = false;
        quint32 sortedColumn = 0x00000001<<currentColumn;                       //对数据进行降序排序
        switch (sortedColumn)
        {
            case SK::col01: result=d1.stu.at(1)>d2.stu.at(1);break;
            case SK::col02: result=d1.stu.at(2)>d2.stu.at(2);break;
            case SK::col03: result=d1.stu.at(3)>d2.stu.at(3);break;
            case SK::col04: result=d1.stu.at(4)>d2.stu.at(4);break;
            case SK::col05: result=d1.stu.at(5)>d2.stu.at(5);break;
            case SK::col06: result=d1.stu.at(6)>d2.stu.at(6);break;
            case SK::col07: result=d1.stu.at(7)>d2.stu.at(7);break;
            case SK::col08: result=d1.stu.at(8)>d2.stu.at(8);break;
            case SK::col09: result=d1.stu.at(9)>d2.stu.at(9);break;
            case SK::col10: result=d1.stu.at(10)>d2.stu.at(10);break;
            case SK::col11: result=d1.stu.at(11)>d2.stu.at(11);break;
            case SK::col12: result=d1.stu.at(12)>d2.stu.at(12);break;
            case SK::col13: result=d1.stu.at(13)>d2.stu.at(13);break;
            case SK::col14: result=d1.stu.at(14)>d2.stu.at(14);break;
            case SK::col15: result=d1.stu.at(15)>d2.stu.at(15);break;
            case SK::col16: result=d1.stu.at(16)>d2.stu.at(16);break;
            case SK::col17: result=d1.stu.at(17)>d2.stu.at(17);break;
            case SK::col18: result=d1.stu.at(18)>d2.stu.at(18);break;
            case SK::col19: result=d1.stu.at(19)>d2.stu.at(19);break;
            case SK::col20: result=d1.stu.at(20)>d2.stu.at(20);break;
            case SK::col21: result=d1.stu.at(21)>d2.stu.at(21);break;
            case SK::col22: result=d1.stu.at(22)>d2.stu.at(22);break;
            case SK::col23: result=d1.stu.at(23)>d2.stu.at(23);break;
            case SK::col24: result=d1.stu.at(24)>d2.stu.at(24);break;
            case SK::col25: result=d1.stu.at(25)>d2.stu.at(25);break;
            case SK::col26: result=d1.stu.at(26)>d2.stu.at(26);break;
            case SK::col27: result=d1.stu.at(27)>d2.stu.at(27);break;
            case SK::col28: result=d1.stu.at(28)>d2.stu.at(28);break;
            case SK::col29: result=d1.stu.at(29)>d2.stu.at(29);break;
            case SK::col30: result=d1.stu.at(30)>d2.stu.at(30);break;
            case SK::col31: result=d1.stu.at(31)>d2.stu.at(31);break;
            case SK::col32: result=d1.stu.at(32)>d2.stu.at(32);break;
        }
        return result;
}


class ScoreSorter
{
public:
    ScoreSorter(QString dataFile);                                              //构造函数
    void readFile();                                                            //函数读取文件声明
    void doSort();                                                              //函数实现排序功能的声明
private:
    QString data_file;                                                          //定义Qstring类型的data_file
    QList<stuData> data;                                                        //定义stuData类型的Qlist列表
    stuData tablelist;                                                          //定义stuData类型的tablelist用于存放表头
    void outwrite_file(int col);                                                //实现将排序好后的数据写入文档
};

ScoreSorter::ScoreSorter(QString dataFile)                                      //构造函数实现初始化
{
    data_file=dataFile;
}

void ScoreSorter::readFile()
{
    QFile file(data_file);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))                      //判断文件是否能够打开
    {
        qDebug()<<QString("Cannot open the file: %1").arg(data_file);
    }

    QString title(file.readLine());                                             //以下三行在读取文件第一行表头（以“\n”为标志）
    tablelist.stu= title.split(" ", QString::SkipEmptyParts);
    if((tablelist.stu).last() == "\n") tablelist.stu.removeLast();
    stuData usefuldata;                                                         //定义stuData类的 usefuldata存放学生数据
    while (!file.atEnd())                                                       //用while从头查找所有数据
    {
        QByteArray line = file.readLine();
        QString str(line);
        usefuldata.stu = str.split(" ", QString::SkipEmptyParts);
        if((usefuldata.stu).last() == "\n")                                     //除去不需要的元素
        {
            usefuldata.stu.removeLast();
        }
        if(usefuldata.stu.size()==0) continue;
        this->data.append(usefuldata);                                          //将所找出符合条件的数据存入data中
    }
    file.close();                                                               //关闭文件
}

void ScoreSorter::doSort()
{
    for(int i=1;i<tablelist.stu.size();i++)
    {
        myCmp cmp(i-1);
        std::sort(data.begin() , data.end() ,cmp );                             //利用std::sort函数排序
        qDebug()<<"Sort by NO."<<i+1<<"column:";                              //输出按照第几列排序
        qDebug() << "   "<<(tablelist)<<"\t";                                   //输出表头
        for(int i=0;i<data.size();i++)
        {
            qDebug()<<data.at(i)<<"\t";                                         //利用重载的“<<”输出每个学生的数据
        }
        qDebug()<<"\n";                                                         //输出换行
        this->outwrite_file(i+1);                                               //数据存入外部文件
    }
}

void ScoreSorter::outwrite_file(int col)
{
    QFile file("sorted_"+data_file);
    file.open(QIODevice::ReadWrite | QIODevice::Append);                        //读写，追加的形式打开文件
    QTextStream in(&file);
    in.setCodec("UTF-8");                                                       //编码
    in<<QString("Sort by NO.")<<col<<QString("column")<<"\r\n";
    in<<"\t";
    for(int j=0;j<tablelist.stu.size();j++)
        in<<tablelist.stu.at(j)<<"\t";
    in<<"\r\n";
    for(int i=0;i<data.size();i++)
    {
        for(int j=0;j<tablelist.stu.size();j++)
            in<<data.at(i).stu.at(j)<<"\t";
        in<<"\r\n";
    }
    in<<"\r\n";
    file.close();
}

int main()
{
    QString datafile = "data.txt";                                              //将所需的操作的文件以Qstring类型赋值给datafile
    QFile f("sorted_"+datafile);                                                // 如果排序后文件已存在，则删除之
    if (f.exists())
    {
        f.remove();
    }
    ScoreSorter s(datafile);                                                    //定义ScoreSorter类的s
    s.readFile();                                                               //读文件
    s.doSort();                                                                 //写文件，并输出并写入新文件
    return 0;
}

