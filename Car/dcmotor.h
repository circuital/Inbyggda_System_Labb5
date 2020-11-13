#ifndef _DCMOTOR_H_
#define _DCMOTOR_H_

void dcmotor_init(void);

void forward(void);
void right(void);

void back(void);
void left(void);

void forwardleft(void);
void forwardright(void);

void backleft(void);
void backright(void);

void dcmotor1_stop(void);
void dcmotor2_stop(void);

void motor_executer(char command);

#endif 
