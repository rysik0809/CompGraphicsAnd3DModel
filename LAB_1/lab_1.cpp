#include <SFML/Graphics.hpp>
#include <vector>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML");

    sf::VertexArray lines(sf::Lines);

    // Исходные координаты линий
    std::vector<std::pair<sf::Vector2f, sf::Vector2f>> originalCoords = {
        {{405.f, 100.f}, {425.f, 140.f}},
        {{425.f, 140.f}, {425.f, 250.f}},
        {{425.f, 250.f}, {445.f, 220.f}},
        {{445.f, 220.f}, {445.f, 290.f}},
        {{445.f, 290.f}, {425.f, 250.f}},
        {{425.f, 250.f}, {425.f, 270.f}},
        {{425.f, 270.f}, {385.f, 270.f}},
        {{385.f, 270.f}, {385.f, 250.f}},
        {{385.f, 250.f}, {365.f, 220.f}},
        {{365.f, 220.f}, {365.f, 290.f}},
        {{365.f, 290.f}, {385.f, 250.f}},
        {{385.f, 250.f}, {385.f, 140.f}},
        {{385.f, 140.f}, {405.f, 100.f}},
    };

    // Применяем преобразования к каждой точке
    for (const auto& line : originalCoords) {
        sf::Vector2f p1 = line.first;
        sf::Vector2f p2 = line.second;

        // 1. Перенос: x-1, y+2
        p1.x -= 1.f;   p1.y += 2.f;
        p2.x -= 1.f;   p2.y += 2.f;

        // 2. Уменьшение в 4 раза
        p1.x /= 4.f;   p1.y /= 4.f;
        p2.x /= 4.f;   p2.y /= 4.f;

        // 3. Отображение относительно x = y (swap)
        std::swap(p1.x, p1.y);
        std::swap(p2.x, p2.y);

        lines.append(sf::Vertex(p1, sf::Color::Red));
        lines.append(sf::Vertex(p2, sf::Color::Red));
    }

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(lines);
        window.display();
    }

    return 0;
}