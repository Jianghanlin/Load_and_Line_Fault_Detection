/*
 * R_C_L_detect.h
 *
 *  Created on: 2020年8月9日
 *      Author: jianghanlin
 */

#ifndef SRC_USER_R_C_L_DETECT_H_
#define SRC_USER_R_C_L_DETECT_H_

//P1.2控制交流20mA输入,也就是给MAX4662的1引脚高电平，根据芯片的特性，内部电子开关将会连通2、3引脚
#define open_ac_20ma()                         \
    {                                          \
        P1OUT &= ~(BIT2 + BIT3 + BIT5 + BIT6); \
        P1OUT |= BIT2;                         \
    }

//P1.5控制交流1mA输入，也就是给MAX4662的8引脚高电平，根据芯片的特性，内部电子开关将会连通6、7引脚
#define open_ac_1ma()                          \
    {                                          \
        P1OUT &= ~(BIT2 + BIT3 + BIT5 + BIT6); \
        P1OUT |= BIT5;                         \
    }

//P1.3控制直流1mA输入,也就是给MAX4662的16引脚高电平，根据芯片的特性，内部电子开关将会连通14、15引脚
#define open_dc_1ma()                          \
    {                                          \
        P1OUT &= ~(BIT2 + BIT3 + BIT5 + BIT6); \
        P1OUT |= BIT3;                         \
    }

//P1.6控制直流10mA输入,也就是给MAX4662的9引脚高电平，根据芯片的特性，内部电子开关将会连通10、11引脚
#define open_dc_10ma()                         \
    {                                          \
        P1OUT &= ~(BIT2 + BIT3 + BIT5 + BIT6); \
        P1OUT |= BIT6;                         \
    }
extern void R_C_L_detect(void);
extern void net_detect(void);



#endif /* SRC_USER_R_C_L_DETECT_H_ */
