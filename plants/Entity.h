#ifndef ENTITY_H
#define ENTITY_H

class Entity {
  double x, y;
  int width, height;

  public:
    Entity(double x, double y);
    Entity(double x, double y, int width, int height);

    double getDist(Entity entity);
    virtual void update(double delta);

    // Accessor methods
    double getX();
    double getY();
    double getCentreX();
    double getCentreY();

    int getWidth();
    int getHeight();

    // Mutator methods
    void setX(double _x);
    void setY(double _y);
    void incX(double i);
    void incY(double i);
    void setPos(double x, double y);
    void setBounds(double x, double y, int width, int height);

    void setWidth(int width);
    void setHeight(int height);
    void incPos(double x, double y);
};

#endif
