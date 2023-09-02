#include <string.h>
#include "pc_libs.h"
#include "SDL_tft_espi.h"
//#include "esp_random.h"

// int rand(void){
//   uint32_t randorm_number = 0;

//   randorm_number = esp_random();
	
// 	return int(randorm_number);
// }	

// void srand(unsigned int seed){

	
// }

// time_t time( time_t *second ){

//   return 1;
// }

// void printf(...){

// }

 void intToArray(Uint32 number, char * number_s){
   Uint16 number_s_length = 0;

   number_s_length = strlen(number_s);

   for (Uint16 i = 0; i < number_s_length; i ++){
     number_s[i] = 0;
   }
   if (number != 0){
    Uint16 n = log10(number) + 1;
    for (Sint16 i = (n - 1); i >= 0; i--){        
        number_s[i] = char((number % 10) + '0');
        number = number / 10;
    }    
   }
   else{
     number_s[0] = '0';
   }
  }

void initRandomNumbers(void){
  randomSeed(analogRead(A0));
}

Uint32 getRandomNumber(Uint32 min, Uint32 max){
   Uint32 range = 0;
   Uint32 randormNumber = 0;

  randormNumber = random(min,max);
  //  range = max - min;
  //  randormNumber = (esp_random() % ( range + 1)) + min;

   return randormNumber;
 }