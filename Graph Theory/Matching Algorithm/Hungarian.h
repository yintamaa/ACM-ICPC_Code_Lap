//
// Created by root on 11/30/22.
//

#ifndef CPPTEST_HUNGARIAN_H
#define CPPTEST_HUNGARIAN_H

#include <string.h>

namespace hungry {

    const int N=505;
    int line[N][N];
    int girl[N],used[N];
    int k,m,n;
    bool found(int x)
    {
        for(int i=1; i<=n; i++)
        {
            if(line[x][i]&&!used[i])
            {
                used[i]=1;
                if(girl[i]==0||found(girl[i]))
                {
                    girl[i]=x;
                    return 1;
                }
            }
        }
        return 0;
    }

    int hungarian() {
        int sum=0;
        for(int i=1; i<=m; i++)
        {
            memset(used,0,sizeof(used));
            if(found(i)) sum++;
        }
        return sum;
    }

}

#endif //CPPTEST_HUNGARIAN_H
