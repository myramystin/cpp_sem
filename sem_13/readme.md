# Copy-and-Swap

устойчивые к исключениям операторы присваивания + меньше дублирующего кода

# SOLID

## Single Responsibility Principle

Класс должен делать что-то одно и делать это хорошо.

```cpp
class Employee {
    std::string name;
    double salary;
    
public:
    // Бизнес-логика
    double calculatePay() { /* ... */ }
    
    // Работа с БД
    void saveToDatabase() { /* ... */ }
    
    // Отчётность
    void generatePayReport() { /* ... */ }
    
    // Работа с сетью
    void sendPaySlipByEmail() { /* ... */ }
};
```
Выше плохой код, класс перегружен


## O — Open/Closed Principle

```cpp
enum class ShapeType { Circle, Rectangle, Triangle };

class Shape {
public:
    ShapeType type;
};

class AreaCalculator {
public:
    double calculateArea(Shape& shape) {
        if (shape.type == ShapeType::Circle) {
            return 3.14 * radius * radius;
        } 
        else if (shape.type == ShapeType::Rectangle) {
            return width * height;
        }
        else if (shape.type == ShapeType::Triangle) {
            return 0.5 * base * height;
        }
        // Добавление новой фигуры требует изменения этой функции!
    }
};
```

Выше плохой код

## L — Liskov Substitution Principle (Принцип подстановки Барбары Лисков)

Определение: Объекты подклассов должны корректно заменять объекты базового класса без изменения поведения программы.

Другими словами: Если класс B наследуется от A, то везде, где используется A, можно подставить B, и программа продолжит работать корректно.

```cpp
class Rectangle {
protected:
    int width, height;
    
public:
    virtual void setWidth(int w) { width = w; }
    virtual void setHeight(int h) { height = h; }
    
    int getWidth() const { return width; }
    int getHeight() const { return height; }
    
    int area() const { return width * height; }
};

class Square : public Rectangle {
public:
    void setWidth(int w) override {
        width = w;
        height = w;  // Квадрат
    }
    
    void setHeight(int h) override {
        width = h;
        height = h;
    }
};

// Тест, который работает для Rectangle, но ломается для Square:
void testRectangle(Rectangle& rect) {
    rect.setWidth(5);
    rect.setHeight(4);
    
    assert(rect.area() == 20);  //  Для Rectangle: 5 * 4 = 20
                                // Для Square: 4 * 4 = 16 (провал!)
}
```


ХОРОШИЙ КОД
```cpp
// Базовый класс для всех фигур
class Shape {
public:
    virtual int area() const = 0;
    virtual ~Shape() = default;
};

// Rectangle — самостоятельная сущность
class Rectangle : public Shape {
    int width, height;
    
public:
    Rectangle(int w, int h) : width(w), height(h) {}
    
    void setWidth(int w) { width = w; }
    void setHeight(int h) { height = h; }
    
    int area() const override { return width * height; }
};

// Square — самостоятельная сущность (НЕ наследуется от Rectangle)
class Square : public Shape {
    int side;
    
public:
    Square(int s) : side(s) {}
    
    void setSide(int s) { side = s; }
    
    int area() const override { return side * side; }
};

// Теперь мы не пытаемся подставить Square вместо Rectangle
void processShape(const Shape& shape) {
    std::cout << "Area: " << shape.area() << std::endl;
    // Работает для ЛЮБОЙ фигуры!
}

```

## Interface Segregation Principle

Лучше иметь много маленьких специализированных интерфейсов, чем один большой универсальный.

```cpp
// "Толстый" интерфейс
class IWorker {
public:
    virtual void work() = 0;
    virtual void eat() = 0;
    virtual void sleep() = 0;
    virtual ~IWorker() = default;
};

class Human : public IWorker {
public:
    void work() override { std::cout << "Working...\n"; }
    void eat() override { std::cout << "Eating...\n"; }
    void sleep() override { std::cout << "Sleeping...\n"; }
};

class Robot : public IWorker {
public:
    void work() override { std::cout << "Working...\n"; }
    
    void eat() override {
        throw std::logic_error("Robots don't eat");
    }
    
    void sleep() override {
        throw std::logic_error("Robots don't sleep");
    }
};

```

ХОРОШИЙ КОД 

```cpp
// Разделённые интерфейсы
class IWorkable {
public:
    virtual void work() = 0;
    virtual ~IWorkable() = default;
};

class IEatable {
public:
    virtual void eat() = 0;
    virtual ~IEatable() = default;
};

class ISleepable {
public:
    virtual void sleep() = 0;
    virtual ~ISleepable() = default;
};

// Человек реализует все интерфейсы
class Human : public IWorkable, public IEatable, public ISleepable {
public:
    void work() override { std::cout << "Human working\n"; }
    void eat() override { std::cout << "Human eating\n"; }
    void sleep() override { std::cout << "Human sleeping\n"; }
};

// Робот реализует только то, что нужно
class Robot : public IWorkable {
public:
    void work() override { std::cout << "Robot working\n"; }
    // Нет методов eat() и sleep() — их просто нет!
};

```

##  Dependency Inversion Principle

- Модули высокого уровня не должны зависеть от модулей низкого уровня. Оба должны зависеть от абстракций.
- Абстракции не должны зависеть от деталей. Детали должны зависеть от абстракций.

Зависимости должны указывать на интерфейсы (абстракции), а не на конкретные реализации.

