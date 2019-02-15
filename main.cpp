#include "Shape.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <list>
#include <deque>
#include <map>

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

void AddOneToWidth(ShapeVector& myShapes)
{
    std::for_each(myShapes.begin(), myShapes.end(), [](std::shared_ptr<IShape>& curShape)
    {
        curShape->SetWidth(curShape->GetWidth() + 1);
    });
}

void TryFind(ShapeVector& myShapes)
{
    std::shared_ptr<IShape> findShape = std::make_shared<Shape>();
    findShape->SetWidth(8);
    findShape->SetHeight(14);

    auto found = std::find(myShapes.begin(), myShapes.end(), findShape);
    if (found != myShapes.end())
    {
        std::cout << "Found: " << std::string(**found) << std::endl;
    }
    else
    {
        std::cout << "Not Found" << std::endl;
    }

    findShape = myShapes[5];

    found = std::find(myShapes.begin(), myShapes.end(), findShape);
    if (found != myShapes.end())
    {
        std::cout << "Found: " << std::string(**found) << std::endl;
    }
    else
    {
        std::cout << "Not Found" << std::endl;
    }
}

std::random_device rd;
std::mt19937 myrandom(rd());

void TryShuffle(ShapeVector& myShapes)
{
    std::shuffle(myShapes.begin(), myShapes.end(), myrandom);

    std::cout << "Shuffle" << std::endl;
    PrintShapes(myShapes);
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

    AddOneToWidth(myShapes);

    PrintShapes(myShapes);

    TryFind(myShapes);

    TryShuffle(myShapes);


    std::cout << "Sort List" << std::endl;
    //std::deque<long> sortList;
    std::vector<long> sortList;

    sortList.push_back(5);
    sortList.push_back(1);
    sortList.push_back(7);
    sortList.push_back(3);
    sortList.push_back(4);
    sortList.push_back(2);

    std::sort(sortList.begin(), sortList.end());

    for(auto cur : sortList)
    {
        std::cout << std::to_string(cur) << ", ";
    }

    std::map<std::string, long> mapSort;

    std::cout << std::endl << "Map Sort" << std::endl;
    mapSort["Test5"] = 5;
    mapSort["Test2"] = 2;
    mapSort["Test7"] = 7;
    mapSort["Test1"] = 1;
    mapSort["Test3"] = 3;

    for (auto cur : mapSort)
    {
        std::cout << cur.first << " " << cur.second << ", ";
    }
    std::cout << std::endl;

    std::cout << "Exit 0" << std::endl;
    return 0;
}