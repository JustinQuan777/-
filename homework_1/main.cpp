#include<QDebug>
typedef quint8 byte;
typedef quint32 word;
#define  WORD_LLO(xxx)  ((byte) ((word)(xxx) & 255))
#define  WORD_HLO(xxx)  ((byte) ((word)(xxx) >> 8))
#define  WORD_LHI(xxx)  ((byte) ((word)(xxx) >> 16))
#define  WORD_HHI(xxx)  ((byte) ((word)(xxx) >> 24))
#define  MAX(x, y)  ( ((x) > (y)) ? (x) : (y) )
#define  MIN(x, y)  ( ((x) < (y)) ? (x) : (y) )


int main()
{
    quint32 i=0x12345678;
    QList<quint8> vaules;
    vaules<<WORD_HHI(i)<<WORD_LHI(i)<<WORD_HLO(i)<<WORD_LLO(i);
    qDebug("原始值：0x%x==%d",i,i);
    qDebug("0x%x==%d  0x%x==%d  0x%x==%d  0x%x==%d",WORD_HHI(i),WORD_HHI(i),WORD_LHI(i),WORD_LHI(i),WORD_HLO(i),WORD_HLO(i),WORD_LLO(i),WORD_LLO(i));
    qDebug("最高8位和次高8位的最大值：0x%x<%d>",MAX(WORD_HHI(i), WORD_LHI(i)),MAX(WORD_HHI(i), WORD_LHI(i)));
    qDebug("次低8位和最低8位的最小值：0x%x<%d>",MIN(WORD_HLO(i), WORD_LLO(i)),MIN(WORD_HLO(i), WORD_LLO(i)));
    quint32 n=(WORD_LHI(i)&0xff)<<0|(WORD_LLO(i)&0xff)<<8|(WORD_HHI(i)&0xff)<<16|(WORD_HLO(i)&0xff)<<24;
    qDebug("重新排列后的数值：0x%x<%d>",n,n);
    qDebug()<<"排序前："<<vaules;
    std::sort(vaules.begin(),vaules.end(),std::greater<quint8>());
    qDebug()<<"排序前："<<vaules;
    return 0;
}
