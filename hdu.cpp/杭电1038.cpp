#include<iostream>
#include<cstdio>  
using namespace std;  
const double pi = 3.1415927;  
int main()  
{  
    double diameter, time;  //直径 时间
    double distances, speed;//距离 速度  
    int revolutions;  //转数  
    int counts = 1;  
    while ((cin >> diameter >> revolutions >> time) && (revolutions != 0))  
    {  
        distances = pi * diameter * revolutions / 63360;  //英里
        speed = distances / (time / 3600); // 英里每小时
        printf ("Trip #%d: %.2f %.2f\n", counts, distances, speed);  
        counts++;  
    }  
    return 0;  
} 
