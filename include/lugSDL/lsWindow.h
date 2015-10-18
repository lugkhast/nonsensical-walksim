
#ifndef _LSWINDOW_H_
#define _LSWINDOW_H_

#include <string>
#include <SDL2/SDL.h>

class lsWindow
{
public:
    lsWindow(std::string title="");
    ~lsWindow();

    SDL_Window *getSDLWindow();
    SDL_Surface *getSDLSurface();
    int updateSurface();

private:
    SDL_Window *mWindow;
    int mWidth = 640;
    int mHeight = 480;
};

#endif // _LSWINDOW_H_
