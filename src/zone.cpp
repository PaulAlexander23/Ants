#include "zone.h"

zone::zone()
{
    rect.x = 0;
    rect.y = 0;
    rect.w = 0;
    rect.h = 0;
}

void zone::set_rect(int x, int y, int w, int h){
    rect.x = x;
    rect.y = y;
    rect.w = w;
    rect.h = h;
}

bool zone::in(int x, int y){
    if(rect.x <= x && x <= rect.x + rect.w && rect.y <= y && y <= rect.y + rect.h){
        return 1;
    }
    else{
        return 0;
    }
}

bool zone::in(vector position){
    return in(position.x, position.y);
}

int zone::draw(SDL_Renderer *renderer){
    int out = SDL_RenderFillRect(renderer, &rect);
    return(out);
}

zone::~zone()
{
}
