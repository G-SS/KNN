/*************************************************************************
	> File Name: KNN.h
	> Author: 
	> Mail: 
	> Created Time: 2020年04月10日 星期五 10时28分30秒
 ************************************************************************/

#ifndef _KNN_H
#define _KNN_H

#include "datastruct.h"
#include <vector>

using namespace std;

void NNC(const vector<Sample> &sample, const double toler[3],
        int &iCnt, vector<Sample> &vecResult, vector<int> &vecFlag, vector<int> &vecCnt);

void calcTime(char *TM);

#endif
