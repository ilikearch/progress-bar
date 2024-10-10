#include "process.h"

const int base = 10;
double total = 2048.0; // 2048MB
double once = 0.1;     // 0.5MB
const int pnum=6;

//根据下载量动态刷新进度条
void FlushProcess(double total, double current){
    //更新进度百分比
    double rate=(current/total)*100;
    //更新进度条主体
    char bar[NUM];//1%是一个等号

    memset(bar,'\0',sizeof(bar));
    for(int i=0;i<(int)rate;i++){
        bar[i]=STYLE;
    }

    //更新旋转光标或其他风格
    static int num=0;
    num++;
    num%=pnum;

    char points[pnum+1];
    memset(points,'\0',sizeof(points));

    //循环'.'光标
    for(int i=0;i<pnum;i++){
        if(i<num)points[i]=POINT;
        else points[i]=SPACE;
    }

    printf("[%-100s][%.1lf%%]%s\r",bar,rate,points);
    fflush(stdout);
}

//进度条的下载
void download(flush_t f){
    double current=0.0;

    while(current < total){
       //模拟下载行为
        int r=rand()%base+1;//[1,10]
        double speed = r*once;
        current+=speed;
        if(current>=total)current=total;
        usleep(5000);

        //更新新的下载量
        f(total,current);
    }

    printf("\r");
}
