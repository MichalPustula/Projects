#pragma once


struct Field
{
    Field(int x_, int y_) : x(x_), y(y_) {}

    int x;
    int y;

    bool operator ==(const Field& rhs)
    {
        if (this->x == rhs.x && this->y == rhs.y) {return true;}
        else { return false;}
    }

};

