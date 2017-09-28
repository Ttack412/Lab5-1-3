#include <iostream>
#include <string>

class AdHocSquare {
    
public:
    
    AdHocSquare(double side){this->side = side;}
    void set_side(double side){this->side = side;}
    double get_area();
    
private:
    
    double side;
};

class LazySquare {
    
public:
    
    LazySquare(double side){this->side = side;}
    void set_side(double side){this->side = side;}
    double get_area();

private: 
    double side;
    double area;
    bool side_changed;

};

//multiplies the sides of the square
double AdHocSquare::get_area()
{
    return side * side;
}


double LazySquare::get_area()
{
    //checks the area
    if(area == 0)
    {
        //sets the area if it's not already set
        area = side * side;
    }
    else
    { 
        //if the area isn't equal to the sides, reset it
        if(area != side * side)
        {
            side_changed = true;
        }
        else
        {
            side_changed = false;
        } 
        
        if(side_changed == true)
        {
            area = side * side;
        } 
    }
    return area;
}

int main(void) {
    //creates an AdHocSquare and sets its side
    AdHocSquare AdHocSquare(5.5);
    std::cout << "The AdHocSquare area is " << AdHocSquare.get_area() << std::endl;
    
    //resets the side
    AdHocSquare.set_side(6.5);
    std::cout << "The new AdHocSquare area is " << AdHocSquare.get_area() << std::endl;
    
    //creates an LazySquare and sets its side
    LazySquare LazySquare(4.5);
    std::cout << "The LazySquare area is " << LazySquare.get_area() << std::endl;
    
    //resets the side
    LazySquare.set_side(3.5);
    std::cout << "The new LazySquare area is " << LazySquare.get_area() << std::endl;
}

