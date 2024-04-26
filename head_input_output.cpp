
#include <iostream>
struct Point
{
    int x;
    int y;
};
template<typename Type>
void Print(Type const &data1)
{
    std:: cout << data1 << "\t";
}
void Print(Point const &data)
{
    std:: cout << data.x << "  " << data.y << "\t";
}
template<typename Type>
void Scanf(Type * data)
{
    std:: cin >> *data;
}
void Scanf(Point * po)
{
    std:: cin >> po->x >> po->y;
}
