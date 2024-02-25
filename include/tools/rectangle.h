#pragma once

#include "integer_vector.h"


class Rect {

public:
    Rect();
    Rect(unsigned int w, unsigned int h);
    Rect(int x, int y, unsigned int w, unsigned int h);
    Rect(Rect &rect);

    bool collide(Vector point);
    bool collide(Rect rect);

    void width(unsigned int);
    void height(unsigned int);

    inline int width(void) const { return w; }
    inline int height(void) const { return h; }

    void left(int);
    void right(int);
    void top(int);
    void bottom(int);
    void centerx(int);
    void centery(int);

    void topleft(Vector);
    void topright(Vector);
    void bottomleft(Vector);
    void bottomright(Vector);
    void center(Vector);
    
    inline int left(void) const { return x; }
    inline int right(void) const { return x + w; }
    inline int top(void) const { return y; }
    inline int bottom(void) const { return y + h; }
    inline int centerx(void) const { return x + w / 2; }
    inline int centery(void) const { return y + h / 2; }

    inline Vector topleft(void) const { return Vector(top(), left()); }
    inline Vector topright(void) const { return Vector(top(), right()); }
    inline Vector bottomleft(void) const { return Vector(bottom(), left()); }
    inline Vector bottomright(void) const { return Vector(bottom(), left()); }
    inline Vector center(void) const { return Vector(centerx(), centery()); }

private:
    int x;
    int y;
    unsigned int w;
    unsigned int h;
};