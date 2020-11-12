#ifndef BUTTONS_H_
#define BUTTONS_H_

#define BAUDRATE 38400
#define UBRR (F_CPU/16/BAUDRATE-1)

#define FORWARD '1'
#define BACK '2'
#define LEFT '3'
#define RIGHT '4'
#define FORWARDLEFT '5'
#define FORWARDRIGHT '6'
#define BACKLEFT '7'
#define BACKRIGHT '8'

void buttons_init(void);

#endif