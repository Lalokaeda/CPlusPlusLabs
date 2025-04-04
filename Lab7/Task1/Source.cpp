#include <SFML/Graphics.hpp>
#include <ctime>
#include <cstdlib>
#include <cmath>
#pragma warning(disable : 4275)

// Класс Point: базовый класс для точки
class Point {
public:
    int X, Y; // Координаты точки

    // Конструктор с параметрами по умолчанию
    Point(int x = 0, int y = 0) : X(x), Y(y) {}

    // Метод для получения текущих координат точки
    void Locat(int& x, int& y) const {
        x = X;
        y = Y;
    }
};

// Класс Krug: наследник класса Point, представляет круг
class Krug : public Point {
private:
    int Radius;           // Радиус круга
    sf::Color Cvet;       // Цвет круга
    sf::CircleShape shape; // SFML-объект для отрисовки круга

public:
    // Конструктор круга
    Krug(int x, int y, int radius, const sf::Color& cvet) :
        Point(x, y), Radius(radius), Cvet(cvet)
    {
        shape.setRadius(static_cast<float>(Radius));
        shape.setFillColor(Cvet);
        shape.setOrigin(sf::Vector2f(static_cast<float>(Radius), static_cast<float>(Radius)));
        shape.setPosition(sf::Vector2f(static_cast<float>(X), static_cast<float>(Y)));
    }

    // Отображение круга
    void Show(sf::RenderWindow& window) const {
        window.draw(shape);
    }

    // Скрытие круга
    void Hide(sf::RenderWindow& window) {
        auto oldColor = shape.getFillColor();
        shape.setFillColor(sf::Color::Transparent);
        window.draw(shape);
        shape.setFillColor(oldColor);
    }

    // Изменение размера круга
    void ChangeSize(int delta) {
        Radius = std::max(1, Radius + delta); // Не даём радиусу стать <= 0
        shape.setRadius(static_cast<float>(Radius));
        shape.setOrigin(sf::Vector2f(static_cast<float>(Radius), static_cast<float>(Radius)));
    }

    // Изменение цвета круга
    void ChangeColor(const sf::Color& newColor) {
        Cvet = newColor;
        shape.setFillColor(Cvet);
    }

    // Метод для "полёта" круга
    void Fly(int Cost, sf::RenderWindow& window) {
        srand(static_cast<unsigned>(time(nullptr)));

        while (window.isOpen()) {
            //while (window.pollEvent()) {
                window.handleEvents([&](const sf::Event::Closed&) {
                    window.close();
                    },
                    [&](const sf::Event::KeyPressed& keyPress)
                    {
                        if (keyPress.code == sf::Keyboard::Key::Escape) {
                            return;
                        }
                    });
            //}

            int newX, newY;
            this->Locat(newX, newY);

            // Генерация новых координат
            do {
                newX += static_cast<int>(std::round((rand() / static_cast<double>(RAND_MAX) - 0.5) * Cost));
            } while (newX <= 0 || newX >= static_cast<int>(window.getSize().x));

            do {
                newY += static_cast<int>(std::round((rand() / static_cast<double>(RAND_MAX) - 0.5) * Cost));
            } while (newY <= 0 || newY >= static_cast<int>(window.getSize().y));

            // Обновление позиции
            X = newX;
            Y = newY;
            shape.setPosition(sf::Vector2f(static_cast<float>(X), static_cast<float>(Y)));

            // Случайное изменение размера и цвета
            ChangeSize((rand() % 20) - 10);
            ChangeColor(sf::Color(
                rand() % 256,
                rand() % 256,
                rand() % 256
            ));

            // Отрисовка
            window.clear();
            window.draw(shape);
            window.display();

            sf::sleep(sf::milliseconds(300));
        }
    }
};

int main() {
    // Создание окна
    sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "Moving Circle");

    // Создание круга
    Krug krug(400, 300, 50, sf::Color::Red);

    // Основной цикл
    while (window.isOpen()) {
       // while (window.pollEvent()) {
            window.handleEvents([&](const sf::Event::Closed&) {
                window.close();
                });
       // }

        window.clear();
        krug.Show(window); // Отображение круга
        window.display();
    }

    // Запуск движения
    krug.Fly(15, window);

    return 0;
}
