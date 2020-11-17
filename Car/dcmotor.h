#ifndef _DCMOTOR_H_
#define _DCMOTOR_H_

void dcmotor_init(void);

void forward(void);

void back(void);

void left(void);

void right(void);

void forwardleft(void);

void forwardright(void);

void backleft(void);

void backright(void);

void dcmotor1_stop(void);

void dcmotor2_stop(void);

void basic_executer(char command);
void STEM_executer(char command);
void STEM_save_to_array(char command);
void STEM_read_array(void);

#endif 
