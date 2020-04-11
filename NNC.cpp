/*************************************************************************
	> File Name: NNC.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年04月09日 星期四 16时24分45秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include "datastruct.h"
using namespace std;


Sample getNewCw(Sample x1, Sample x2);

/*
 * 函数功能:最近邻距离聚类
 *入    参:
 *          sample 样本参数 
 *          toler 门限
 *返回值  :
 *          iCnt 聚类的类别个数 
 *          vecResult 聚类中心点  
 *          vecFlag 聚类标志  
 *          vecCnt 每一类包含的样本个数
 *备    注:
 *          对样本的先后计算次序比较敏感，用于发现球状簇
 *
 */
void NNC(const vector<Sample> &sample, const double toler[3], int &iCnt,
         vector<Sample> &vecResult,vector<int> &vecFlag, vector<int> &vecCnt)
{   
    vecResult.push_back(sample[0]);
    iCnt = 1;
    vecCnt.push_back(1);
    vecFlag.push_back(0);
    
    for(int i=1; i<sample.size(); i++)
    {
        int m = iCnt;
        for(int j = 0; j<m; j++)
        {
            //曼哈顿距离
            //符合已有类的要求，则加入已有类别，重新计算中心点
           
            //bool flag = fabs(sample[i].X[0]-vecResult[j].X[0]) < toler[0] &&
            //            fabs(sample[i].X[1]-vecResult[j].X[1]) < toler[1] && 
            //            fabs(sample[i].X[2]-vecResult[j].X[2]) < toler[2];  
            
            double dis = sqrt(pow(sample[i].X[0], vecResult[j].X[0]) +
                    pow(sample[i].X[1], vecResult[j].X[1]) +
                    pow(sample[i].X[2], vecResult[j].X[2]));
            bool flag = (dis<toler[0]);

            if(flag)
            {
                vecResult[j] = getNewCw(sample[i], vecResult[i]);
                vecCnt[j]++;
                break;
            }

            if(!flag && j==(m-1))   //未找到符合要求的类，则自成一类
            {
                vecResult.push_back(sample[i]);
                vecCnt.push_back(1);
                iCnt++;
            }
            vecFlag.push_back(j);
        }
    }
}

Sample getNewCw(Sample x1, Sample x2)
{
    Sample ret; 
    for(int i=0; i<3; i++)
    {
        ret.X[i] = (x1.X[i]+x2.X[i])/2; 
    }
    return ret;
}
