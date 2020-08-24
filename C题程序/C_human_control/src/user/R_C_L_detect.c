/*
 * R_C_L_detect.c
 *
 *  Created on: 2020年8月9日
 *      Author: jianghanlin
 */
#include "msp430f5529.h"
#include <stdio.h>
#include <inc/driver/ssd1351.h>
#include <inc/driver/ads1118.h>
#include <inc/system/fonts.h>
#include <src/user/R_C_L_detect.h>

unsigned char dc_open_flag=1;

//P1.2控制交流20mA输入,也就是给MAX4662的1引脚高电平，根据芯片的特性，内部电子开关将会连通2、3引脚


/*void R_C_L_detect(void)
{
    char v0[15] = {};//字符数组，用来保存电压值
    if(dc_open_flag==1)
    {
        a1 = average_voltage_caculate(5, 20);//A1通道用来读取ADC2
        sprintf(v0, "%.5fV ", a1); //A1通道的电压
        ssd1351_display_string(40, 40, v0, 1, White, Black);

        if(a1<0.2)//判断为是电感或短路
        {
            open_ac_20ma();
            dc_open_flag=0;
            __delay_cycles(100);
            a0 = average_voltage_caculate(4, 20); //A0通道用来读取ADC1
            sprintf(v0, "%.5fV ", a0); //将A0的电压转换成字符串保存在数组中
            ssd1351_display_string(40, 20, v0, 1, White, Black);
            if(a0>0.2)//判断为是电感
            {
                display_l(a0);
            }
            else//判断为是短路
            {
                ssd1351_display_string(0, 60, "Warning!!    ", 1, White, Black);
                ssd1351_display_string(0, 80, "Short Circuit!!", 1, White, Black);
            }
        }
        else if(a1<3)//判断为是电阻
        {
            display_res(a1);
        }
        else//判断为是电容或开路
        {
            open_ac_20ma();
            dc_open_flag=0;
            __delay_cycles(100);
            a0 = average_voltage_caculate(4, 20); //A0通道用来读取ADC1
            sprintf(v0, "%.5fV ", a0); //将A0的电压转换成字符串保存在数组中
            ssd1351_display_string(40, 20, v0, 1, White, Black);
            if(a0<4)//判断为是电容
            {
                display_cap(a0);
            }
            else//判断为是开路
            {
                ssd1351_display_string(0, 60, "Warning!!    ", 1, White, Black);
                ssd1351_display_string(0, 80, "Open Circuit!!", 1, White, Black);
            }
        }
    }
    open_dc_1ma();
    __delay_cycles(100);
    dc_open_flag=1;
}*/
