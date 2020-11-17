#ifndef BUTTONS_H_
#define BUTTONS_H_

#define STOP '0'
#define FORWARD '1'
#define BACK '2'
#define LEFT '3'
#define RIGHT '4'
#define FORWARDLEFT '5'
#define FORWARDRIGHT '6'
#define BACKLEFT '7'
#define BACKRIGHT '8'
#define CHANGEMODE 'C'
#define START 'S'

void buttons_init(void);

char get_button_command(void);

#endif