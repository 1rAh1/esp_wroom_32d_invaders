#ifndef IMG_H
#define IMG_H
#include "pgmspace.h"

//Online image converter https://notisrac.github.io/FileToCArray/

const unsigned int FILE_IMAGES_NUMBER = 4;

PROGMEM const char imgAlienPath[] = "img/alien.bmp";
#define imgAlienWidth 11
#define imgAlienHeight 8
PROGMEM const unsigned char imgAlienBits[] = {
   0x04, 0x01, 0x88, 0x00, 0xfc, 0x01, 0x76, 0x03, 0xff, 0x07, 0xfd, 0x05,
   0x05, 0x05, 0xd8, 0x00 };

PROGMEM const char imgCraftPath[] = "img/craft.bmp";  
#define imgCraftWidth 13
#define imgCraftHeight 8
static unsigned char imgCraftBits[] = {
   0x40, 0x00, 0xe0, 0x00, 0xe0, 0x00, 0xfe, 0x0f, 0xff, 0x1f, 0xff, 0x1f,
   0xff, 0x1f, 0xff, 0x1f };
   
PROGMEM const char imgAlienShootPath[] = "img/alien_shoot.bmp";   
#define imgAlienShootWidth 3
#define imgAlienShootHeight 7
static unsigned char imgAlienShootBits[] = {
   0x04, 0x02, 0x01, 0x02, 0x04, 0x02, 0x01 };
  
PROGMEM const char imgCraftShootPath[] = "img/craft_shoot.bmp";  
#define imgCraftShootWidth 1
#define imgCraftShootHeight 4
static unsigned char imgCraftShootBits[] = {
   0x01, 0x01, 0x01, 0x01 };
   
PROGMEM const char* imgPaths[] = {
	imgAlienPath,
	imgCraftPath,
	imgAlienShootPath,
	imgCraftShootPath
};

typedef struct ImgData_t{
  Uint16 w;
  Uint16 h;
  const unsigned char* bits;
};

PROGMEM ImgData_t imgDataHandlers[] = {
	{imgAlienWidth, imgAlienHeight, imgAlienBits},
	{imgCraftWidth, imgCraftHeight, imgCraftBits},
	{imgAlienShootWidth, imgAlienShootHeight, imgAlienShootBits},
	{imgCraftShootWidth, imgCraftShootHeight, imgCraftShootBits}
};

// const unsigned long imgAlien [] PROGMEM = {
// 	// 'alien, 11x8px
// 	0x00ffffff, 0x00ffffff, 0x0000ff00, 0x00ffffff, 0x00ffffff, 0x00ffffff, 0x00ffffff, 0x00ffffff, 0x0000ff00, 0x00ffffff, 0x00ffffff, 
// 	0x00ffffff, 0x00ffffff, 0x00ffffff, 0x0000ff00, 0x00ffffff, 0x00ffffff, 0x00ffffff, 0x0000ff00, 0x00ffffff, 0x00ffffff, 0x00ffffff, 
// 	0x00ffffff, 0x00ffffff, 0x0000ff00, 0x0000ff00, 0x0000ff00, 0x0000ff00, 0x0000ff00, 0x0000ff00, 0x0000ff00, 0x00ffffff, 0x00ffffff, 
// 	0x00ffffff, 0x0000ff00, 0x0000ff00, 0x00ffffff, 0x0000ff00, 0x0000ff00, 0x0000ff00, 0x00ffffff, 0x0000ff00, 0x0000ff00, 0x00ffffff, 
// 	0x0000ff00, 0x0000ff00, 0x0000ff00, 0x0000ff00, 0x0000ff00, 0x0000ff00, 0x0000ff00, 0x0000ff00, 0x0000ff00, 0x0000ff00, 0x0000ff00, 
// 	0x0000ff00, 0x00ffffff, 0x0000ff00, 0x0000ff00, 0x0000ff00, 0x0000ff00, 0x0000ff00, 0x0000ff00, 0x0000ff00, 0x00ffffff, 0x0000ff00, 
// 	0x0000ff00, 0x00ffffff, 0x0000ff00, 0x00ffffff, 0x00ffffff, 0x00ffffff, 0x00ffffff, 0x00ffffff, 0x0000ff00, 0x00ffffff, 0x0000ff00, 
// 	0x00ffffff, 0x00ffffff, 0x00ffffff, 0x0000ff00, 0x0000ff00, 0x00ffffff, 0x0000ff00, 0x0000ff00, 0x00ffffff, 0x00ffffff, 0x00ffffff
// };
   
#endif
