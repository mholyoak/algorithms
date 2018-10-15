#include "Shape.h"

#include <iostream>
#include <vector>

using ShapeVector = std::vector<std::shared_ptr<IShape>>;

void PrintShapes(const ShapeVector& myShapes)
{
    std::cout << "Shapes" << std::endl;
    std::for_each(myShapes.begin(), myShapes.end(), [](const std::shared_ptr<IShape>& curShape) {
        std::cout << "\tWidth: " << std::to_string(curShape->GetWidth())
                  << " Height: " << std::to_string(curShape->GetHeight())
                  << " Area: " << std::to_string(curShape->GetArea())
                  << std::endl;
    });
}

int main() {
    std::cout << "Hello, World!" << std::endl;

    std::shared_ptr<IShape> myShape = std::make_shared<Shape>();

    std::cout << "Shape Area " << std::to_string(myShape->GetArea()) << std::endl;

    ShapeVector myShapes;

    for (int i = 1; i <= 10; i++)
    {
        std::shared_ptr<IShape> myShape = std::make_shared<Shape>();
        myShape->SetWidth(i);
        myShape->SetHeight(i * 2);
        myShapes.push_back(myShape);
    }

    PrintShapes(myShapes);

    bool allAreasLarge = std::all_of(myShapes.begin(), myShapes.end(), [](const std::shared_ptr<IShape>& curShape) {
        return curShape->GetArea() > 5;
    });
    std::cout << "all_of area > 5: " << std::to_string(allAreasLarge) << std::endl;

    bool allAreasAtLeastSmall = std::all_of(myShapes.begin(), myShapes.end(), [](const std::shared_ptr<IShape>& curShape) {
        return curShape->GetArea() > 1;
    });
    std::cout << "all_of at least small: " << std::to_string(allAreasAtLeastSmall) << std::endl;

    bool anyAreaEight = std::any_of(myShapes.begin(), myShapes.end(), [](const std::shared_ptr<IShape>& curShape){
        return curShape->GetArea() == 8;
    });
    std::cout << "any area eight: " << std::to_string(anyAreaEight) << std::endl;

    bool noneAreaFive = std::none_of(myShapes.begin(), myShapes.end(), [](const std::shared_ptr<IShape>& curShape){
        return curShape->GetArea() == 5;
    });
    std::cout << "none_of area 5: " << std::to_string(noneAreaFive) << std::endl;

    std::cout << "Exit 0" << std::endl;
    return 0;
}