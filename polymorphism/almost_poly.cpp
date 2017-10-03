#include <iostream>
using namespace std;

/*************************************
Super cool. So even though we only implemented triangle in our do_poly,
we still get the correct results for our circle objects. Since we are using function pointers,
we have the location in memory for the correct functions to call for specific objects. I think since our
function definitions for circle_funcs and triangle_funcs are the same, we can call circles functions even though do_poly
is only calling stuff from t_ptr. I'm still confused on why exactly this works, but those are my thoughts.
 ************************************/

void draw_circle(struct Circle *c);
float area_circle(struct Circle *c);
void draw_triangle(struct Triangle *t);
float area_triangle(struct Triangle *t);
struct Triangle;
struct Circle;

union shape_ptr {
  struct Circle *c_ptr;
  struct Triangle *t_ptr;
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

struct Triangle
{
  char color;
  union triangle_funcs vtt[2];
  char shade;
  short base;
  short height;
};

struct Circle
{
  char color;
  union circle_funcs vtc[2];
  char shade;
  short radius;
};

void set_circle(struct Circle *c, char color, char shade, short radius)
{
  c->color = color;
  c->vtc[0].draw = draw_circle;
  c->vtc[1].area = area_circle;
  c->shade = shade;
  c->radius = radius;
}

void set_triangle(struct Triangle *t, char color, char shade, short base, short height)
{
  t->color = color;
  t->vtt[0].draw = draw_triangle;
  t->vtt[1].area = area_triangle;
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

void do_poly(union shape_ptr shape)
{
  shape.t_ptr->vtt[0].draw(shape.t_ptr);
  cout << "Area: " << shape.t_ptr->vtt[1].area(shape.t_ptr) << endl;
}

int main()
{
  union shape_ptr shapes[4];

  Circle c1;
  set_circle(&c1, 'r', 'd', 5);
  Circle c2;
  set_circle(&c2, 'r', 'l', 5);
  Triangle t1;
  set_triangle(&t1, 'b', 'l', 3, 4);
  Triangle t2;
  set_triangle(&t2, 'b', 'd', 3, 4);

  shapes[0].c_ptr = &c1;
  shapes[1].c_ptr = &c2;
  shapes[2].t_ptr = &t1;
  shapes[3].t_ptr = &t2;

  for (int i = 0; i < 4; i++)
    {
      do_poly(shapes[i]);
    }

  return 0;
}
