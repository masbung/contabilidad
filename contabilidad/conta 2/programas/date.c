#include <stdio.h>
#include <Windows.h>

int main(){

    SYSTEMTIME stime;
    GetSystemTime(&stime);
    printf("%d/ %d/ %d/", stime.wDay, stime.wMonth, stime.wYear);
    getchar();
}


