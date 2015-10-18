#include <iostream>
#include "SDLApp.h"


bool SDLApp::initSDL()
{
    bool success = true;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "Failed to initialize SDL! SDL error: "
            << SDL_GetError() << std::endl;
        success = false;
    }

    //Set texture filtering to linear
    if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) ) {
        printf( "Warning: Linear texture filtering not enabled!" );
    }

    int imgFlags = IMG_INIT_PNG;
    if( !( IMG_Init( imgFlags ) & imgFlags ) ) {
        printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
        success = false;
    }

    return success;
}

void SDLApp::cleanupSDL()
{
    delete this->window;
    this->window = NULL;

    SDL_Quit();
}

void SDLApp::handleWindowEvent(SDL_Event *event)
{
    switch (event->window.event) {
    case SDL_WINDOWEVENT_SIZE_CHANGED:
        this->windowSurface = this->window->getSDLSurface();
        break;
    case SDL_WINDOWEVENT_EXPOSED:
        this->windowSurface = this->window->getSDLSurface();
        break;
    }
}

SDL_Texture *SDLApp::loadTexture(string path)
{
    //The final texture
	SDL_Texture *newTexture = NULL;

	//Load image at specified path
	SDL_Surface *loadedSurface = IMG_Load(path.c_str());
	if( loadedSurface == NULL ) {
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	} else {
		//Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( mRenderer, loadedSurface );
		if( newTexture == NULL ) {
			printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	return newTexture;
}

void SDLApp::render()
{
    SDL_Rect destRect;
    MovementHandler movementHandler = this->world->getMovementHandler();
    auto movables = movementHandler.getMovables();
    Movable *movable;

    destRect.w = 64;
    destRect.h = 64;

    SDL_FillRect(
        this->windowSurface,
        NULL,
        SDL_MapRGB(this->windowSurface->format, 0x00, 0x00, 0x00)
    );

    for (auto it = movables.begin(); it != movables.end(); ++it) {
        movable = *it;
        destRect.x = movable->x;
        destRect.y = movable->y;

        SDL_RenderClear( mRenderer );
        SDL_RenderCopy( mRenderer, this->playerTexture, NULL, &destRect );
        SDL_RenderPresent( mRenderer );
    }
}

void SDLApp::start()
{
    this->quit = false;
    SDL_Event e;

    this->window = new lsWindow("Walking Simulator 2016");

    mRenderer = SDL_CreateRenderer(
        this->window->getSDLWindow(), -1, SDL_RENDERER_ACCELERATED
    );
    SDL_SetRenderDrawColor(mRenderer, 0x00, 0x00, 0x00, 0xFF);
    this->playerTexture = loadTexture("assets/pic1.png");

    while(!this->quit) {
        while ( SDL_PollEvent( &e ) != 0 ) {
            // Window events should be handled here
            if (e.type == SDL_WINDOWEVENT) {
                this->handleWindowEvent(&e);
            } else {
                // Game-relevant events are handled by SDLEventHandler
                this->quit = this->evtHandler->handleEvent(&e);
            }
        }

        this->world->tick();
        this->render();
    }

    std::cout << "Destroying renderer" << std::endl;
    SDL_DestroyRenderer(mRenderer);
    std::cout << "Deleting window" << std::endl;
    delete this->window;
    this->window = NULL;
    std::cout << "End of start()" << std::endl;
}

SDLApp::SDLApp()
{
    this->initSDL();

    this->player = new Movable;
    this->world = new World;
    this->world->putMovable(this->player);

    this->evtHandler = new SDLEventHandler(this->player, this->world);
}

SDLApp::~SDLApp()
{
    this->cleanupSDL();

    delete this->evtHandler;
    delete this->world;
    delete this->player;
}
