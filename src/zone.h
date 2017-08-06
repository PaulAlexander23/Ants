#pragma once
#include"main.h"

class zone
{
public:
    zone();

    void set_rect(int x, int y, int w, int h);
    bool in(int x, int y);
    bool in(vector position);
    int draw(SDL_Renderer *renderer);

    ~zone();

private:
    SDL_Rect rect;
};
