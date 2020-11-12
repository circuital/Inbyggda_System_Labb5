#ifndef BUTTONS_H_
#define BUTTONS_H_

#define BAUDRATE 38400
#define UBRR (F_CPU/16/BAUDRATE-1)

void buttons_init(void);

#endif