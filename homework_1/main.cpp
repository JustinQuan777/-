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
    vaules<<WORD_HHI(i)<<WORD_LHI(i)<<WORD_HLO(i)<<WORD_LLO(i);//取出最高8位（HHL）、次高8位（LHI）、次低8位（HLO）、最低8位（LLO）并存入vaules中
    qDebug("原始值：0x%x==%d",i,i);//用16进制和10进制输出原数
    qDebug("0x%x==%d  0x%x==%d  0x%x==%d  0x%x==%d",WORD_HHI(i),WORD_HHI(i),WORD_LHI(i),WORD_LHI(i),WORD_HLO(i),WORD_HLO(i),WORD_LLO(i),WORD_LLO(i));//用16进制和10进制输出最高8位（HHL）、次高8位（LHI）、次低8位（HLO）、最低8位（LLO）
    qDebug("最高8位和次高8位的最大值：0x%x<%d>",MAX(WORD_HHI(i), WORD_LHI(i)),MAX(WORD_HHI(i), WORD_LHI(i)));//输出最高8位和次高8位的最大值
    qDebug("次低8位和最低8位的最小值：0x%x<%d>",MIN(WORD_HLO(i), WORD_LLO(i)),MIN(WORD_HLO(i), WORD_LLO(i)));//输出次低8位和最低8位的最小值
    quint32 n=(WORD_LHI(i)&0xff)<<0|(WORD_LLO(i)&0xff)<<8|(WORD_HHI(i)&0xff)<<16|(WORD_HLO(i)&0xff)<<24;//组合成一个新的32位无符号整形数，由高位到低位分别为原次低8位、最高8位和次高8位
    qDebug("重新组合后的数值：0x%x<%d>",n,n);//用16进制和10进制分别输出重新组合后的数组
    qDebug()<<"排序前："<<vaules;//输出排序前的vaules数组
    std::sort(vaules.begin(),vaules.end(),std::greater<quint8>());//将vaules数组进行降序排序
    qDebug()<<"排序后："<<vaules;//输出排序后的vaules数组
    return 0;
}
