#ifndef PC_LIBS_H
#define PC_LIBS_H
#include "stdint.h"
#include "sdl_types2stdint.h"

//#define printf //printf
// void printf(...);
//#define printf(...) os_printf( __VA_ARGS__ )

// //stdlib.h
// int rand(void);
// void srand(unsigned int seed);

// //time.h
// typedef uint8_t time_t;
// time_t time( time_t *second );

 void intToArray(uint32_t number, char * number_s);

void initRandomNumbers(void);

Uint32 getRandomNumber(Uint32 min, Uint32 max);


#endif