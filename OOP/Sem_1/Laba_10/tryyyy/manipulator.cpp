#include "manipulator.h"

ProductManipulator::ProductManipulator(int w, char f, bool a) : 
    width(w), fillChar(f), alignLeft(a) {}

std::ostream& operator<<(std::ostream& os, const ProductManipulator& pm) {
    os << std::setw(pm.width) << std::setfill(pm.fillChar);
    if (pm.alignLeft) os << std::left;
    else os << std::right;
    return os;
}

ProductManipulator productFormat(int width, char fillChar, bool alignLeft) {
    return ProductManipulator(width, fillChar, alignLeft);
}