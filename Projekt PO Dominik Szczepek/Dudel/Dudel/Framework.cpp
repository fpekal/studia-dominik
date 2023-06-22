#include "framework.h"
#include <SDL.h>
#include <SDL_image.h>
#include <chrono>
#include <iostream>

static struct Size {
	int width = 0;
	int height = 0;
};

static SDL_Window* window = nullptr;
static SDL_Surface* surface = nullptr;
static Size window_size = { 0, 0 };

class Sprite {
public:
	SDL_Surface* img_surface = nullptr;
	Size size;

	Sprite(const char* path) {
		img_surface = IMG_Load(path);
		size = { img_surface->w, img_surface->h };
	}

	~Sprite() {
		SDL_FreeSurface(surface);
	}

	void Draw(int x, int y) {
		SDL_Rect rect;
		rect.x = x;
		rect.y = y;
		rect.w = size.width;
		rect.h = size.height;

		int a = SDL_BlitScaled(img_surface, NULL, surface, &rect);
	}
};

static FRKey convertKey(SDL_Keycode key) {
	if (key == SDL_KeyCode::SDLK_LEFT) {
		return FRKey::LEFT;
	}
	else if (key == SDL_KeyCode::SDLK_RIGHT) {
		return FRKey::RIGHT;
	}
	else if (key == SDL_KeyCode::SDLK_UP) {
		return FRKey::UP;
	}
	else if (key == SDL_KeyCode::SDLK_DOWN) {
		return FRKey::DOWN;
	}

	return (FRKey)-1;
}

Sprite* createSprite(const char* path) {
	return new Sprite(path);
}

void destroySprite(Sprite* sprite) {
	delete sprite;
}

void drawSprite(Sprite* sprite, int x, int y) {
	sprite->Draw(x, y);
}

void setSpriteSize(Sprite* sprite, int w, int h) {
	sprite->size = { w, h };
}

void getSpriteSize(Sprite* sprite, int& w, int& h) {
	w = sprite->size.width;
	h = sprite->size.height;
}

int run(Framework* framework) {
	SDL_Init(SDL_INIT_VIDEO);
	IMG_Init(IMG_INIT_PNG);

	bool fullscreen = false;

	framework->PreInit(window_size.width, window_size.height, fullscreen);


	const char* name = nullptr;
	name = framework->GetTitle();

	Uint32 flags = 0;
	if (fullscreen) flags = SDL_WINDOW_FULLSCREEN;

	window = SDL_CreateWindow(name, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, window_size.width, window_size.height, flags);
	surface = SDL_GetWindowSurface(window);

	bool success = framework->Init();
	if (!success) _exit(0);

	bool is_running = true;

	while (is_running) {
		SDL_Event ev;

		while (SDL_PollEvent(&ev) > 0) {
			if (ev.type == SDL_QUIT) {
				is_running = false;
			}
			else if (ev.type == SDL_MOUSEMOTION) {
				framework->onMouseMove(ev.motion.x, ev.motion.y, ev.motion.xrel, ev.motion.yrel);
			}
			else if (ev.type == SDL_MOUSEBUTTONDOWN) {
				if (ev.button.button == SDL_BUTTON_LEFT) {
					framework->onMouseButtonClick(FRMouseButton::LEFT, false);
				}
				else if (ev.button.button == SDL_BUTTON_RIGHT) {
					framework->onMouseButtonClick(FRMouseButton::RIGHT, false);
				}
			}
			else if (ev.type == SDL_MOUSEBUTTONUP) {
				if (ev.button.button == SDL_BUTTON_LEFT) {
					framework->onMouseButtonClick(FRMouseButton::LEFT, true);
				}
				else if (ev.button.button == SDL_BUTTON_RIGHT) {
					framework->onMouseButtonClick(FRMouseButton::RIGHT, true);
				}
			}
			else if (ev.type == SDL_KEYDOWN) {
				if (ev.key.keysym.sym == SDL_KeyCode::SDLK_ESCAPE) {
					is_running = false;
					break;
				}

				FRKey key = convertKey(ev.key.keysym.sym);

				if (key != (FRKey)-1)
					framework->onKeyPressed(key);
			}
			else if (ev.type == SDL_KEYUP) {
				FRKey key = convertKey(ev.key.keysym.sym);

				if (key != (FRKey)-1)
					framework->onKeyReleased(key);
			}
		}

		SDL_UpdateWindowSurface(window);

		bool tick = framework->Tick();
		if (tick) is_running = false;
	}

	framework->Close();

	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}

void getScreenSize(int& w, int& h) {
	w = window_size.width;
	h = window_size.height;
}

unsigned int getTickCount() {
	return (unsigned int)std::chrono::steady_clock::now().time_since_epoch().count() * 1000;
}