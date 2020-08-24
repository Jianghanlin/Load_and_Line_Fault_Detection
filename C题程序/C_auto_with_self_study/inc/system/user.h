/*
 * user.h
 *
 *  Created on: 2018-02-16 18:00
 *      Author: Jack Chen <redchenjs@live.com>
 */

#ifndef INC_SYSTEM_USER_H_
#define INC_SYSTEM_USER_H_

extern void user_init(void);
extern void user_loop(void);
extern void key_dect(void);
extern void display_myinfo(void);
extern void mode_choose_interface(void);
extern char jiantou,jiemian,confirm;
extern float adc[2][8];
#endif /* INC_SYSTEM_USER_H_ */
