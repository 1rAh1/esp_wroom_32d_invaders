#ifndef DSL_TFT_ESPI
#define DSL_TFT_ESPI
#include "sdl_types2stdint.h"
#include <TFT_eSPI.h>

#define SDL_NULL 0



typedef TFT_eSPI SDL_Window;
typedef TFT_eSprite SDL_Renderer;
typedef struct SDL_Texture{
  const unsigned char* imgData;
  const char *text;
};
typedef struct SDL_Color { Uint8 r; Uint8 g; Uint8 b; Uint8 a; };
//typedef SDL_Color TTF_Font;
typedef struct TTF_Font{
  SDL_Color color;
  Uint16 size;
  Uint16 name;
};
typedef struct SDL_Rect {
    int x, y;
    int w, h;
};
typedef Uint8 SDL_Event;

//const char* SDL_GetError(void);
#define SDL_GetError(x) ((const char*) 0)

//const char* TTF_GetError(void);
#define TTF_GetError(x) ((const char*) 0)

//SDL_Init
enum SDL_InitFlagsValues{
  SDL_INIT_VIDEO = 0
};
int SDL_Init(Uint32 flags);

//SDL_CreateWindow
#define SDL_WINDOWPOS_UNDEFINED 0
#define SDL_WINDOW_SHOWN 0

SDL_Window * SDL_CreateWindow(const char *title, int x, int y, int w, int h, Uint32 flags);


#define SDL_RENDERER_ACCELERATED 0
SDL_Renderer * SDL_CreateRenderer(SDL_Window * window, int index, Uint32 flags);

//int TTF_Init(void);
#define TTF_Init(x) 1

//void SDL_DestroyTexture(SDL_Texture * texture);
#define SDL_DestroyTexture(x) /**/

//void SDL_DestroyRenderer(SDL_Renderer * renderer);
#define SDL_DestroyRenderer(x) /**/

//void SDL_DestroyWindow(SDL_Window * window);
#define SDL_DestroyWindow(x) /**/

//void TTF_CloseFont(TTF_Font *font);
#define TTF_CloseFont(x) /**/

//void TTF_Quit(void);
#define TTF_Quit(x) /**/

//void SDL_Quit(void);
#define SDL_Quit(x) /**/




int SDL_RenderClear(SDL_Renderer * renderer);
int SDL_RenderCopy(SDL_Renderer * renderer, SDL_Texture * texture, const SDL_Rect * srcrect, const SDL_Rect * dstrect);
void SDL_RenderPresent(SDL_Renderer * renderer);
int SDL_SetRenderDrawColor(SDL_Renderer * renderer, Uint8 r, Uint8 g, Uint8 b, Uint8 a);
int SDL_RenderFillRect(SDL_Renderer * renderer, const SDL_Rect * rect);

#define SDL_GetTicks() millis()

enum KeyCodes{
  SDL_SCANCODE_LEFT = 0,
  SDL_SCANCODE_RIGHT,
  SDL_SCANCODE_UP,
  SDL_SCANCODE_DOWN,
  SDL_SCANCODE_A,
  SDL_SCANCODE_B,
  SDL_SCANCODE_START,
  SDL_SCANCODE_SELECT,
  SDL_SCANCODE_NUMBER
};

const Uint8* SDL_GetKeyboardState(int *numkeys);

//TTF_Font * TTF_OpenFont(const char *file, int ptsize);
extern TTF_Font sdl_tf_espi_font;
TTF_Font * TTF_OpenFont(const char *file, int ptsize);

#endif