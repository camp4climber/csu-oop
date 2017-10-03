#include <iostream>
using namespace std;

struct Triangle
{
  char color;
  char shade;
  short base;
  short height;
};

struct Circle
{
  char color;
  char shade;
  short radius;
};

union circle_funcs
{
  void (*draw)(struct Circle *);
  float (*area)(struct Circle *);
};

union triangle_funcs
{
  void (*draw)(struct Triangle *);
  float (*area)(struct Triangle *);
};

void set_circle(struct Circle *c, char color, char shade, short radius)
{
  c->color = color;
  c->shade = shade;
  c->radius = radius;
}

void set_triangle(struct Triangle *t, char color, char shade, short base, short height)
{
  t->color = color;
  t->shade = shade;
  t->base = base;
  t->height = height;
}

void draw_circle(struct Circle *c)
{
  switch(c->shade)
    {
    case 'l':
      cout << "Light ";
      break;
    case 'd':
      cout << "Dark ";
      break;
    default:
      cout << "UNSHADED ";
    }
  switch (c->color)
    {
    case 'r':
      cout << "red ";
      break;
    case 'g':
      cout << "green ";
      break;
    case 'b':
      cout << "blue ";
      break;
    default:
      cout << "COLORLESS ";
    }
  cout << "circle. ";
  cout << "Radius: " << c->radius << endl;
}

void draw_triangle(struct Triangle *t)
{
  switch(t->shade)
    {
    case 'l':
      cout << "Light ";
      break;
    case 'd':
      cout << "Dark ";
      break;
    default:
      cout << "UNSHADED ";
    }
  switch (t->color)
    {
    case 'r':
      cout << "red ";
      break;
    case 'g':
      cout << "green ";
      break;
    case 'b':
      cout << "blue ";
      break;
    default:
      cout << "COLORLESS ";
    }
  cout << "triangle. ";
  cout << "Base: " << t->base;
  cout << " Height: " << t->height << endl;
}

float area_circle(struct Circle *c)
{
  return 3.14 * c->radius * c->radius;
}

float area_triangle(struct Triangle *t)
{
  return 0.5 * t->base * t->height;
}

int main()
{
  Circle c;
  Triangle t;

  union circle_funcs vtc[2];
  vtc[0].draw = draw_circle;
  vtc[1].area = area_circle;

  union triangle_funcs vtt[2];
  vtt[0].draw = draw_triangle;
  vtt[1].area = area_triangle;

  set_circle(&c, 'r', 'd', 5);
  set_triangle(&t, 'b', 'l', 3, 4);

  vtc[0].draw(&c);
  vtt[0].draw(&t);


  cout << "Circle Area: " << vtc[1].area(&c) << endl;
  cout << "Triangle Area: " << vtt[1].area(&t) << endl;

  return 0;
}
