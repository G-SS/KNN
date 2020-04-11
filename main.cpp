/*************************************************************************
	> File Name: test.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年04月10日 星期五 10时28分01秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <string.h>
#include "KNN.h"

const int maxsize = 1024;

using namespace std;

bool readFile(const char *path, vector<Sample> &vecData);
void writeFile(const char *path, const vector<Sample> &vecData);

string strPath = "/home/Git/C++/KNN/Data/";

int main(int argc, char *argv[])
{
    
    vector<Sample> vecData;
    vector<Sample> vecResult;
    vector<int>    vecCnt;
    vector<int>    vecFlag;
    int            iCnt = 0;
    double toler[3];
    toler[0] = 5;
    toler[1] = 3;
    toler[2] = 2;
 
    readFile((strPath + "Data2/iris.data").c_str(), vecData);

    printf("聚类开始...\n");
    NNC(vecData, toler, iCnt, vecResult, vecFlag, vecCnt);
    printf("聚类结束,共%d\n类\n", iCnt);

    char TM[128] = "";
    calcTime(TM);

    printf("开始写文件...\n");
    writeFile((strPath + "Result/" + TM).c_str(), vecResult);

    printf("处理完成...\n");
    
    return 0;
}

bool readFile(const char *path, vector<Sample> &vecData)
{
    FILE *fp = fopen(path, "r+");
    if(fp == NULL)
    {
        printf("%s文件打开失败\n", path);
        return false;
    }
    
    char line[maxsize] = "";
    fgets(line, maxsize, fp);
    int j=0;
    char *pTok = NULL;
    Sample data;
    while(!feof(fp))
    {
        fgets(line, maxsize, fp);
        j = 0;
        for(pTok = strtok(line, "\t"); pTok && *pTok; pTok=strtok(NULL, "\t"), j++)
        {
            if(j==0)
            {
                data.X[0] = atof(pTok);
            }
            else if(j==1)
            {
                data.X[1] = atof(pTok);
            }
            else if(j==2)
            {
                data.X[2] = atof(pTok);
            }
        }
        vecData.push_back(data);
    }
    vecData.pop_back();
    
    fclose(fp);
    fp = NULL;

    printf("文件读入成功，共%d条...\n", static_cast<int>(vecData.size()));
    return true;
}


void writeFile(const char *path, const vector<Sample> &vecData)
{
    
    FILE *fp = fopen(path, "w+");
    if(fp == NULL)
    {
        printf("写文件错误\n");
        return;
    }

    for(int i=0; i<vecData.size(); i++)
    {
        fprintf(fp, "%f\t%f\t%f\n", vecData[i].X[0], vecData[i].X[1], vecData[i].X[2]);
    }
    fclose(fp);
    fp = NULL;

}



