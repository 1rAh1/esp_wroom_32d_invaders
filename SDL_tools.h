#ifndef SDL_TOOLS_H
#define SDL_TOOLS_H
#include "SDL_tft_espi.h"


//Data types
typedef struct Area_t {
	Sint16 x;
	Sint16 y;
	Sint16 w;
	Sint16 h;
};

typedef struct Image_t{
	SDL_Texture image;
	Sint32 w;
	Sint32 h;
	float screenScale;
};

Image_t loadTexture(const char* path_s, SDL_Color* colorKey, SDL_Renderer* screenRenderer);
Image_t getTextImage(const char* text_s, TTF_Font* p_font, SDL_Color p_color, SDL_Renderer* screenRenderer);
#define testingEndProgram() /**/
bool detectCollision(SDL_Rect* elementA, SDL_Rect* elementB);

enum TextPosition {
	XY_POSITION = 0,
  HORIZONTAL_CENTERED,
	WINDOW_CENTERED
};

typedef struct ShowMessageIn_t {
	char * text;
	Uint16 position;
	Uint16 x;
	Uint16 y;
	Uint16 size;
	SDL_Color fontColor;
	//GameScreen_t* p_gameScreen;
};

void showMessage(ShowMessageIn_t* p_showMessageIn, SDL_Renderer* screenRenderer);

#endif