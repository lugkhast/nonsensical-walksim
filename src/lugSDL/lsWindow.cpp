
#include "lugSDL/lsWindow.h"
#include "lugSDL/lsException.h"

lsWindow::lsWindow(std::string title)
{
    mWindow = SDL_CreateWindow(
        title.c_str(),
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        mWidth, mHeight,
        SDL_WINDOW_SHOWN
    );

    if (!mWindow) {
        lsException ex("Failed to create window!");
        throw ex;
    }
}

lsWindow::~lsWindow()
{
    SDL_DestroyWindow(mWindow);
}

SDL_Window *lsWindow::getSDLWindow()
{
    return mWindow;
}

SDL_Surface *lsWindow::getSDLSurface()
{
    return SDL_GetWindowSurface(mWindow);
}

int lsWindow::updateSurface()
{
    return SDL_UpdateWindowSurface(mWindow);
}
