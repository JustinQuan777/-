#include <QDebug>
#include <QVector>
#include <QTextStream>
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
    QStringList stu;                                                            //����һ���ַ����б���� stu

} studData;

QDebug operator<< (QDebug d, const studData &data)                              //�����<<����
{
   QDebugStateSaver saver(d);                                                   //���Զ���QDebug�����ʱ���ȱ���QDebug��ǰ���ã���saver���󣬳����������������ʱ�����Զ��ָ�QDebug��״̬��
   for(int i=0;i<data.stu.size();i++)
    {
        d.noquote().nospace()<<data.stu.at(i)<<"\t";                            //����Ҫ��ֱ����һ�е�ѧ������
    }
       return d;
}



class myCmp {                                                                   // �Ƚ��࣬����std::sort����������
public:
    myCmp(int selectedColumn) { this->currentColumn = selectedColumn; }
    bool operator() (const studData& d1,const studData& d2);
private:
    int currentColumn;
};

bool myCmp::operator()(const studData &d1, const studData &d2)                  //���ж��������ݵ�ʵ��
{
    if (d1.stu.at(currentColumn+1)>d2.stu.at(currentColumn+1))                  //�����ݽ�����������
            return 0;
        else
            return 1;

}


class ScoreSorter                                                               //
{
public:
    ScoreSorter(QString dataFile);
    void readFile();
    void doSort();
private:
    QString data_file;
    QList<studData> data;

    // �벹ȫ���࣬ʹ��ʵ������Ҫ��
    // ...
};

// �벹ȫ
ScoreSorter::ScoreSorter(QString dataFile)                                           //��ɹ��캯�������г�ʼ��
{
    data_file=dataFile;

}


void myMessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    // �Զ���qDebug
}

int main()
{
    qInstallMessageHandler(myMessageOutput);
    QString datafile = "data.txt";

    // ���������ļ��Ѵ��ڣ���ɾ��֮
    QFile f("sorted_"+datafile);
    if (f.exists()){
        f.remove();
    }

    ScoreSorter s(datafile);
    s.readFile();
    s.doSort();
    return 0;
}
