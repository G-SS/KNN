/*************************************************************************
	> File Name: tools.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年04月10日 星期五 11时03分16秒
 ************************************************************************/

#include <iostream>
#include <ctime>
#include <cstring>
#include <string>

using namespace std;

void calcTime(char *TM)
{
    time_t tm;
    time(&tm);

    struct tm *stTm;
    stTm = localtime(&tm);
    
    sprintf(TM, "%d-%d-%d  %d:%d:%d", stTm->tm_year+1900, stTm->tm_mon+1,
           stTm->tm_mday, stTm->tm_hour, stTm->tm_min, stTm->tm_sec);

}








