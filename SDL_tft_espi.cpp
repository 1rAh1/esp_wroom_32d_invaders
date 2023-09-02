#include "pins_arduino.h"
#include "SDL_tft_espi.h"
#include <SPI.h>
//#include <HardwareSerial.h>
#include "gpio_def.h"


TFT_eSPI tft = TFT_eSPI();       // Invoke custom library
TFT_eSprite spr = TFT_eSprite(&tft);

TTF_Font sdl_tf_espi_font;



int SDL_Init(Uint32 flags){
  Serial.begin(19200);

  //pinMode(DO_BOARD_LED, OUTPUT);
  pinMode(DO_BUZZER, OUTPUT);

  pinMode(DI_LEFT_BUTTON, INPUT_PULLUP);
  pinMode(DI_RIGHT_BUTTON, INPUT_PULLUP);
  pinMode(DI_UP_BUTTON, INPUT_PULLUP);
  pinMode(DI_DOWN_BUTTON, INPUT_PULLUP);
  pinMode(DI_A_BUTTON, INPUT_PULLUP);
  pinMode(DI_B_BUTTON, INPUT_PULLUP);

  // //buzzer code
  //  {
  //   int freq = 5000;
  //   int channel = 0;
  //   int resolution = 8;
  //   ledcSetup(channel, freq, resolution);
  //   ledcAttachPin(DO_BUZZER, channel);
    
  //   while(1){
  //     freq = 5000;
  //     ledcWriteTone(channel, freq);
  //     ledcWrite(channel, 127);
  //     delay(1000);
  //     ledcWrite(channel, 0);
  //     delay(1000);
  //   }
  //  }


  

  pinMode(A0, INPUT);

  Serial.println("SDL TFT_eSPI Initialized");

  return 1;
}

SDL_Window* SDL_CreateWindow(const char *title, int x, int y, int w, int h, Uint32 flags){
  tft.init(INITR_GREENTAB3);
  //tft.setRotation(0);
  //tft.setRotation(1);
  tft.setRotation(2);
  tft.fillScreen(TFT_BLACK);

  return &tft;
}

uint16_t RenderDrawColor = TFT_BLACK;

SDL_Renderer* SDL_CreateRenderer(SDL_Window * window, int index, Uint32 flags){
  spr.setColorDepth(8);
  spr.createSprite(window->width(), window->height());
  RenderDrawColor = TFT_BLACK;
  tft.fillScreen(RenderDrawColor);
  return &spr;
}

int SDL_SetRenderDrawColor(SDL_Renderer * renderer, Uint8 r, Uint8 g, Uint8 b, Uint8 a){

  RenderDrawColor = 0;
  RenderDrawColor |= ((((Uint16) r) << 8) & 0b1111100000000000);
  RenderDrawColor |= ((((Uint16) g) << 3) & 0b0000011111100000);
  RenderDrawColor |= ((((Uint16) b) >> 3) & 0b0000000000011111);

  // extern HardwareSerial Serial;
  // Serial.print("r=");
  // Serial.println(r,BIN);
  // Serial.println(((((Uint16) r) << 11) & 0b1111100000000000),BIN);

  // Serial.print("g=");
  // Serial.println(g,BIN);
  // Serial.println(((((Uint16) g) << 3) & 0b0000011111100000),BIN);

  // Serial.print("b=");
  // Serial.println(b,BIN);
  // Serial.println(((((Uint16) b) >> 3) & 0b0000000000011111),BIN);
  //Serial.println(RenderDrawColor,HEX);
  return 1;
}

int SDL_RenderFillRect(SDL_Renderer * renderer, const SDL_Rect * rect){
  renderer->fillRect(rect->x, rect->y, rect->w, rect->h, RenderDrawColor);

  return 1;
}



int SDL_RenderClear(SDL_Renderer * renderer){
  tft.fillScreen(RenderDrawColor);
  return 1;
}

int SDL_RenderCopy(SDL_Renderer * renderer, SDL_Texture * texture, const SDL_Rect * srcrect, const SDL_Rect * dstrect){
  //RenderDrawColor = TFT_GREEN;

  if (texture->text != ((const char*) 0)){    
    //renderer->setTextSize(renderer->fontHeight()/7);
    renderer->setTextSize(sdl_tf_espi_font.size);
    renderer->setTextColor(RenderDrawColor, TFT_BLACK);

    renderer->drawString(texture->text, dstrect->x, dstrect->y);    
  }
  if (texture->imgData != ((const unsigned char*) 0)){
    renderer->drawXBitmap(dstrect->x, dstrect->y, texture->imgData, dstrect->w, dstrect->h, RenderDrawColor);
  }

  return 1;
}

void SDL_RenderPresent(SDL_Renderer * renderer){
  renderer->pushSprite(0, 0);
}



Uint8 keyboardState[8];

const Uint8* SDL_GetKeyboardState(int *numkeys){
  for (Uint16 i = 0; i < SDL_SCANCODE_NUMBER; i ++){
    keyboardState[i] = 0;
  }

  if (0 == digitalRead(DI_LEFT_BUTTON)){
    keyboardState[SDL_SCANCODE_LEFT] = 1;
    Serial.println("DI_LEFT_BUTTON");
  }

  if (0 == digitalRead(DI_RIGHT_BUTTON)){
    keyboardState[SDL_SCANCODE_RIGHT] = 1;
    Serial.println("DI_RIGHT_BUTTON");
  }

  if (0 == digitalRead(DI_UP_BUTTON)){
    keyboardState[SDL_SCANCODE_UP] = 1;
    Serial.println("DI_UP_BUTTON");
  }

  if (0 == digitalRead(DI_DOWN_BUTTON)){
    keyboardState[SDL_SCANCODE_DOWN] = 1;
    Serial.println("DI_DOWN_BUTTON");
  }

  if (0 == digitalRead(DI_A_BUTTON)){
    keyboardState[SDL_SCANCODE_A] = 1;
    Serial.println("DI_A_BUTTON");
  }

  if (0 == digitalRead(DI_B_BUTTON)){
    keyboardState[SDL_SCANCODE_B] = 1;
    Serial.println("DI_B_BUTTON");
  }  

  return ((const Uint8*) &keyboardState);
}

TTF_Font * TTF_OpenFont(const char *file, int ptsize){

  sdl_tf_espi_font.size = ptsize;
  sdl_tf_espi_font.name = 0;

  return &sdl_tf_espi_font;

}



