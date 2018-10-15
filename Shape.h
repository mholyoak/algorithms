//
// Created by Mitch Holyoak on 10/15/18.
//

#ifndef ALGORITHMS_SHAPE_H
#define ALGORITHMS_SHAPE_H

class IShape {
public:
    virtual ~IShape() {};

    virtual int GetHeight() const = 0;
    virtual void SetHeight(int height) = 0;

    virtual int GetWidth() const = 0;
    virtual void SetWidth(int width) = 0;

    virtual int GetArea() const = 0;
};

class Shape : public IShape {
public:
    Shape();
    ~Shape();

    int GetHeight() const override;
    void SetHeight(int height) override;
    int GetWidth() const override;
    void SetWidth(int width) override;
    int GetArea() const override;

private:
    int _width = 1;
    int _height = 2;
};


#endif //ALGORITHMS_SHAPE_H
