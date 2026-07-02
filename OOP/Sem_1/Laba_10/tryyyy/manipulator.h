#ifndef MANIPULATOR_H
#define MANIPULATOR_H

#include <iostream>
#include <iomanip>

class ProductManipulator {
    private:
        int width;
        char fillChar;
        bool alignLeft;
    public:
        ProductManipulator(int w, char f, bool a);
        friend std::ostream& operator<<(std::ostream& os, const ProductManipulator& pm);
};

// Функция-создатель
ProductManipulator productFormat(int width, char fillChar = ' ', bool alignLeft = true);

#endif