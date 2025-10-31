#include <ftxui/screen/screen.hpp>
#include <ftxui/screen/color.hpp>
#include <thread>
#include <chrono>
#include <iostream>

int main() {
    using namespace ftxui;

    const int width = 20;
    const int height = 10;
    auto screen = Screen::Create(Dimension::Fixed(width), Dimension::Fixed(height));

    for (int frame = 0; frame < width; ++frame) {
        // Limpia la pantalla
        for (int y = 0; y < height; ++y)
            for (int x = 0; x < width; ++x)
                screen.PixelAt(x, y).character = U' ';

        // Dibuja un píxel animado
        auto& pixel = screen.PixelAt(frame, height / 2);
        pixel.character = U'*';
        pixel.bold = true;
        pixel.foreground_color = Color::Red;

        // Imprime la pantalla y resetea el cursor
        std::cout << screen.ToString();
        std::cout << screen.ResetPosition();
        std::cout << std::flush;

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    return 0;
}
