/*
 * display_value.c
 *
 *  Created on: 2020年8月12日
 *      Author: jianghanlin
 */
/*
 * display_value.c
 *
 *  Created on: 2020年7月17日
 *      Author: jianghanlin
 */
#include "msp430f5529.h"
#include <inc/user/input.h>
#include <inc/driver/ssd1351.h>
#include <inc/driver/ads1118.h>
#include <inc/driver/dac8571.h>
#include <stdio.h>
#include <inc/system/user.h>
#include <inc/system/fonts.h> //使用颜色的名称必须包含fonts.h的头文件，比如要使用White，Red....等颜色名称
#include <src/user/R_C_L_detect.h>
float a0 = 0, a1 = 0, a2 = 0;
unsigned char back = 0, open_ac_1ma_flag = 0, open_dc_1ma_flag = 0;
//变量back用来判断界面1的次数,open_ac_1ma_flag是交流1mA打开标志，open_dc_1ma_flag是直流1mA打开标志

void display_value()
{
    char v0[15] = {}; //字符数组，用来保存电压值
    if (jiemian == 2) //KEY3被第1次按下，并且进入2级界面
    {
        switch (jiantou) //根据1级界面的箭头位置，决定显示的内容
        {
        case 1:
            if (open_dc_1ma_flag == 1)
            {
                a1 = average_voltage_caculate(5, 50);
                sprintf(v0, "%.4fV ", a1); //A1通道的电压
                ssd1351_display_string(40, 40, v0, 1, White, Black);
            }
            else if (open_ac_1ma_flag == 1)
            {
                a0 = average_voltage_caculate(4, 50);
                sprintf(v0, "%.4fV ", a0); //A1通道的电压
                ssd1351_display_string(40, 40, v0, 1, White, Black);
            }
            else
                ;
            break;
        case 2:
            net_detect();
            break;
        case 3:
            R_C_L_detect();
            break;
        default:
            break;
        }
    }
    else if ((jiemian == 1) && (confirm == 0))
    {
        if (back == 0)
        {
            ssd1351_clear_gram();
            dislay_topic();
            mode_choose_interface();
            back = 1;
        }
        else
            ;
    }
    else
        ;
}
