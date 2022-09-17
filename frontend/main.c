// Copyright 2011 The Emscripten Authors.  All rights reserved.
// Emscripten is available under two separate licenses, the MIT license and the
// University of Illinois/NCSA Open Source License.  Both these licenses can be
// found in the LICENSE file.

#include <stdio.h>
#include <SDL/SDL.h>
#include <math.h>

#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif


double sampleNormal() {
    double u = ((double) rand() / (RAND_MAX)) * 2 - 1;
    double v = ((double) rand() / (RAND_MAX)) * 2 - 1;
    double r = u * u + v * v;
    if (r == 0 || r > 1) return sampleNormal();
    double c = sqrt(-2 * log(r) / r);
    return u * c;
}

void plotDataPoint(SDL_Surface *screen, double value) {
  static int t = 0;

  // int y_min = -2, y_max = 2
  // int y = value - y_min / 

  int y = (int)value + 100;


  *((Uint32*)screen->pixels + y * 256 + t) = 0;

  t = (t + 1) % 256;

  // printf("%d\n", y);
}

void fill(SDL_Surface *screen) {
  for (int i = 0; i < 256; i++) {
    for (int j = 0; j < 256; j++) {
#ifdef TEST_SDL_LOCK_OPTS
      // Alpha behaves like in the browser, so write proper opaque pixels.
      int alpha = 255;
#else
      // To emulate native behavior with blitting to screen, alpha component is ignored. Test that it is so by outputting
      // data (and testing that it does get discarded)
      int alpha = (i+j) % 255;
#endif
      *((Uint32*)screen->pixels + i * 256 + j) = SDL_MapRGBA(screen->format, 255, 255, 255, alpha);
    }
  }
}

int main(int argc, char** argv) {
  printf("hello, world!\n");

  SDL_Init(SDL_INIT_VIDEO);
  SDL_Surface *screen = SDL_SetVideoMode(256, 256, 32, SDL_SWSURFACE);

// #ifdef TEST_SDL_LOCK_OPTS
//   EM_ASM("SDL.defaults.copyOnLock = false; SDL.defaults.discardOnLock = true; SDL.defaults.opaqueFrontBuffer = false;");
// #endif

  if (SDL_MUSTLOCK(screen)) SDL_LockSurface(screen);

  fill(screen);

  double value = 0.0;
  for (int i = 0; i < 200; i++) {
    plotDataPoint(screen, value);
    value += sampleNormal();
  }

  if (SDL_MUSTLOCK(screen)) SDL_UnlockSurface(screen);
  SDL_Flip(screen); 
  SDL_Quit();
  return 0;
}