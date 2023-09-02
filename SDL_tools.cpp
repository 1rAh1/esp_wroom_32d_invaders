#include "SDL_tools.h"
#include "string.h"
#include "img.h"


Image_t loadTexture(const char* path_s, SDL_Color* colorKey, SDL_Renderer * screenRenderer) {
	Image_t textImage;
  uint16_t i = 0;

	//Load image at specified path
  for (Uint16 i = 0; i < FILE_IMAGES_NUMBER; i ++){    
    if( 0 ==  strcmp(path_s, imgPaths[i])){
        textImage.image.text = ((const char *) 0);
        textImage.image.imgData = imgDataHandlers[i].bits;
        textImage.w = imgDataHandlers[i].w;
        textImage.h = imgDataHandlers[i].h;

      break;
    }
  }

	return textImage;
}


bool detectCollision(SDL_Rect* elementA, SDL_Rect* elementB) {
	bool crash = true;
	Sint16 elementAX0 = 0;
	Sint16 elementAY0 = 0;
	Sint16 elementAX1 = 0;
	Sint16 elementAY1 = 0;

	Sint16 elementBX0 = 0;
	Sint16 elementBY0 = 0;
	Sint16 elementBX1 = 0;
	Sint16 elementBY1 = 0;

	elementAX0 = elementA->x;
	elementAY0 = elementA->y;
	elementAX1 = elementA->x + elementA->w;
	elementAY1 = elementA->y + elementA->h;

	elementBX0 = elementB->x;
	elementBY0 = elementB->y;
	elementBX1 = elementB->x + elementB->w;
	elementBY1 = elementB->y + elementB->h;


	if ((elementAX1 <= elementBX0) ||
		(elementBX1 <= elementAX0) ||
		(elementAY1 <= elementBY0) ||
		(elementBY1 <= elementAY0)
		) {

		crash = false;
	}

	return crash;
}

Image_t getTextImage(const char* text_s, TTF_Font* p_font, SDL_Color p_color, SDL_Renderer* screenRenderer) {
	// SDL_Texture* loadedTexture = NULL;
	// SDL_Surface* loadedSurface = NULL;

  Uint8 fontH = 0;
  Uint8 fontW = 0;
  Uint8 fontSpace = 0;
  Uint16 text_s_length = 0;
	Image_t textImage;

  switch(p_font->size){
    case 2:
      fontH = 14;
      fontW = 10;
      fontSpace = 2;
      break;

    default:
      fontH = 7;
      fontW = 6;
      fontSpace = 1;
      break;
  }
  text_s_length = strlen(text_s);



  p_font->color = p_color;
  textImage.image.text =  text_s;
  textImage.image.imgData = ((const unsigned char *) 0);
  textImage.w = text_s_length * fontW + (text_s_length - 1) * fontSpace;
	textImage.h = fontH;



	// loadedSurface = TTF_RenderText_Solid(p_font, text.c_str(), p_color);
	// textImage.w = loadedSurface->w;
	// textImage.h = loadedSurface->h;
	// if (loadedSurface == NULL)
	// {
	// 	printf("Unable to create text surface %s!\n", SDL_GetError());
	// }
	// else {
	// 	loadedTexture = SDL_CreateTextureFromSurface(screenRenderer, loadedSurface);
	// 	if (loadedTexture == NULL) {
	// 		printf("Unable to create texture %s\n", SDL_GetError());
	// 	}

	// 	//Get rid of old loaded surface
	// 	SDL_FreeSurface(loadedSurface);
	// 	loadedSurface = NULL;
	// }
	// textImage.image = loadedTexture;
	return textImage;
}


void showMessage(ShowMessageIn_t* p_showMessageIn, SDL_Renderer* screenRenderer) {
	//SDL_Texture* textTexture = NULL;
	TTF_Font* p_font; 


	Image_t messageImage;

	SDL_Rect stretchRect;

	p_font = TTF_OpenFont("img/space_invaders.ttf", p_showMessageIn->size);

	messageImage = getTextImage(p_showMessageIn->text, p_font, p_showMessageIn->fontColor, screenRenderer);

	switch (p_showMessageIn->position) {
		case WINDOW_CENTERED:      
			stretchRect.x = (screenRenderer->width() - messageImage.w) / 2;
			stretchRect.y = (screenRenderer->height() - messageImage.h) / 2;
			break;
    case HORIZONTAL_CENTERED:
      stretchRect.x = (screenRenderer->width() - messageImage.w) / 2;
			stretchRect.y = p_showMessageIn->y;
      break;
		default:
			stretchRect.x = p_showMessageIn->x;
			stretchRect.y = p_showMessageIn->y;
			break;
	}

	stretchRect.w = messageImage.w;
	stretchRect.h = messageImage.h;
	SDL_RenderCopy(screenRenderer, &messageImage.image, NULL, &stretchRect);

	SDL_DestroyTexture(messageImage.image);
	messageImage.image.text = NULL;
}