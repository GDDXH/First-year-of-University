#include<iostream>
#include<cstdio>  
using namespace std;  
const double pi = 3.1415927;  
int main()  
{  
    double diameter, time;  //ֱ�� ʱ��
    double distances, speed;//���� �ٶ�  
    int revolutions;  //ת��  
    int counts = 1;  
    while ((cin >> diameter >> revolutions >> time) && (revolutions != 0))  
    {  
        distances = pi * diameter * revolutions / 63360;  //Ӣ��
        speed = distances / (time / 3600); // Ӣ��ÿСʱ
        printf ("Trip #%d: %.2f %.2f\n", counts, distances, speed);  
        counts++;  
    }  
    return 0;  
} 
