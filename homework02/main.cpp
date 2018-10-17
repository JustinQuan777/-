#include <QDebug>
#include <QList>
#include <QTextStream>
#include <QString>
#include <QFile>
namespace SK {
enum SortKind{
    col01    =   0x00000001<<0,         //!< ��1��
    col02    =   0x00000001<<1,         //!< ��2��
    col03    =   0x00000001<<2,         //!< ��3��
    col04    =   0x00000001<<3,         //!< ��4��
    col05    =   0x00000001<<4,         //!< ��5��
    col06    =   0x00000001<<5,         //!< ��6��
    col07    =   0x00000001<<6,         //!< ��7��
    col08    =   0x00000001<<7,         //!< ��8��
    col09    =   0x00000001<<8,         //!< ��9��
    col10    =   0x00000001<<9,         //!< ��10��
    col11    =   0x00000001<<10,        //!< ��11��
    col12    =   0x00000001<<11,        //!< ��12��
    col13    =   0x00000001<<12,        //!< ��13��
    col14    =   0x00000001<<13,        //!< ��14��
    col15    =   0x00000001<<14,        //!< ��15��
    col16    =   0x00000001<<15,        //!< ��16��
    col17    =   0x00000001<<16,        //!< ��17��
    col18    =   0x00000001<<17,        //!< ��18��
    col19    =   0x00000001<<18,        //!< ��19��
    col20    =   0x00000001<<19,        //!< ��20��
    col21    =   0x00000001<<20,        //!< ��21��
    col22    =   0x00000001<<21,        //!< ��22��
    col23    =   0x00000001<<22,        //!< ��23��
    col24    =   0x00000001<<23,        //!< ��24��
    col25    =   0x00000001<<24,        //!< ��25��
    col26    =   0x00000001<<25,        //!< ��26��
    col27    =   0x00000001<<26,        //!< ��27��
    col28    =   0x00000001<<27,        //!< ��28��
    col29    =   0x00000001<<28,        //!< ��29��
    col30    =   0x00000001<<29,        //!< ��30��
    col31    =   0x00000001<<30,        //!< ��31��
    col32    =   0x00000001<<31,        //!< ��32��
};
}

typedef struct
{
    QStringList stu;                                                             //����һ���ַ����б���� stu

} stuData;

QDebug operator<< (QDebug d, const stuData &data)                                //�����<<����
{
   QDebugStateSaver saver(d);                                                    //���Զ���QDebug�����ʱ���ȱ���QDebug��ǰ���ã���saver���󣬳����������������ʱ�����Զ��ָ�QDebug��״̬
   for(int i=0;i<data.stu.size();i++)
    {
        d.noquote().nospace()<<data.stu.at(i)<<"\t";                            //����Ҫ��ֱ����һ�е�ѧ������
    }
       return d;
}

class myCmp//�Ƚ��࣬����std::sort��������
{
public:
    myCmp(int selectedColumn)
    {
        currentColumn = selectedColumn;                                         //�ڹ��캯���г�ʼ��
    }
    bool operator() (const stuData& d1,const stuData& d2);                      //�����������ݵ�����
private:
    int currentColumn;                                                          //���嵱ǰ��
};

bool myCmp::operator()(const stuData &d1, const stuData &d2)                    //���ж��������ݵ�ʵ��
{
    bool result = false;
        quint32 sortedColumn = 0x00000001<<currentColumn;                       //�����ݽ��н�������
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
    ScoreSorter(QString dataFile);                                              //���캯��
    void readFile();                                                            //������ȡ�ļ�����
    void doSort();                                                              //����ʵ�������ܵ�����
private:
    QString data_file;                                                          //����Qstring���͵�data_file
    QList<stuData> data;                                                        //����stuData���͵�Qlist�б�
    stuData tablelist;                                                          //����stuData���͵�tablelist���ڴ�ű�ͷ
    void outwrite_file(int col);                                                //ʵ�ֽ�����ú������д���ĵ�
};

ScoreSorter::ScoreSorter(QString dataFile)                                      //���캯��ʵ�ֳ�ʼ��
{
    data_file=dataFile;
}

void ScoreSorter::readFile()
{
    QFile file(data_file);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))                      //�ж��ļ��Ƿ��ܹ���
    {
        qDebug()<<QString("Cannot open the file: %1").arg(data_file);
    }

    QString title(file.readLine());                                             //���������ڶ�ȡ�ļ���һ�б�ͷ���ԡ�\n��Ϊ��־��
    tablelist.stu= title.split(" ", QString::SkipEmptyParts);
    if((tablelist.stu).last() == "\n") tablelist.stu.removeLast();
    stuData usefuldata;                                                         //����stuData��� usefuldata���ѧ������
    while (!file.atEnd())                                                       //��while��ͷ������������
    {
        QByteArray line = file.readLine();
        QString str(line);
        usefuldata.stu = str.split(" ", QString::SkipEmptyParts);
        if((usefuldata.stu).last() == "\n")                                     //��ȥ����Ҫ��Ԫ��
        {
            usefuldata.stu.removeLast();
        }
        if(usefuldata.stu.size()==0) continue;
        this->data.append(usefuldata);                                          //�����ҳ��������������ݴ���data��
    }
    file.close();                                                               //�ر��ļ�
}

void ScoreSorter::doSort()
{
    for(int i=1;i<tablelist.stu.size();i++)
    {
        myCmp cmp(i-1);
        std::sort(data.begin() , data.end() ,cmp );                             //����std::sort��������
        qDebug()<<"Sort by NO."<<i+1<<"column:";                              //������յڼ�������
        qDebug() << "   "<<(tablelist)<<"\t";                                   //�����ͷ
        for(int i=0;i<data.size();i++)
        {
            qDebug()<<data.at(i)<<"\t";                                         //�������صġ�<<�����ÿ��ѧ��������
        }
        qDebug()<<"\n";                                                         //�������
        this->outwrite_file(i+1);                                               //���ݴ����ⲿ�ļ�
    }
}

void ScoreSorter::outwrite_file(int col)
{
    QFile file("sorted_"+data_file);
    file.open(QIODevice::ReadWrite | QIODevice::Append);                        //��д��׷�ӵ���ʽ���ļ�
    QTextStream in(&file);
    in.setCodec("UTF-8");                                                       //����
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
    QString datafile = "data.txt";                                              //������Ĳ������ļ���Qstring���͸�ֵ��datafile
    QFile f("sorted_"+datafile);                                                // ���������ļ��Ѵ��ڣ���ɾ��֮
    if (f.exists())
    {
        f.remove();
    }
    ScoreSorter s(datafile);                                                    //����ScoreSorter���s
    s.readFile();                                                               //���ļ�
    s.doSort();                                                                 //д�ļ����������д�����ļ�
    return 0;
}

