#include <concepts>
#include <iostream>

// Define the interface using a concept
template <typename T>
concept Drawable = requires(T t) {
    { t.draw() } -> std::same_as<void>; // Requires a draw() method that returns void
};

// Base class to enforce the interface
template <typename Derived>
class DrawableBase
{
public:
    void draw()
    {
        static_cast<Derived*>(this)->draw(); // Use CRTP to call the derived class's draw() method
    }
};

// A class implementing the Drawable interface
class Circle : public DrawableBase<Circle>
{
public:
    void draw()
    {
        std::cout << "Drawing a Circle\n";
    }
};

// Another class implementing the Drawable interface
class Rectangle : public DrawableBase<Rectangle>
{
public:
    void draw()
    {
        std::cout << "Drawing a Rectangle\n";
    }
};

// Function that accepts only Drawable objects
void render(Drawable auto& shape)
{
    shape.draw();
}

int main()
{
    Circle circle;
    Rectangle rectangle;

    render(circle);    // Output: Drawing a Circle
    render(rectangle); // Output: Drawing a Rectangle

    return 0;
}
