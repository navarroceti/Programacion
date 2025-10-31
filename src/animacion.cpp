
#include <ftxui/screen/screen.hpp>
#include <ftxui/screen/color.hpp>
#include <thread>
#include <chrono>
#include <iostream>
#include <Dibujo.hpp>
#include <GestorDibujos.hpp>
using namespace ftxui;

int main()
{
    // Crear la ventana
    auto screen = Screen::Create(
        Dimension::Full(), 
        Dimension::Fixed(24)
    );

    // Agregar código de los elementos de la granja
    const std::vector<std::u32string> granja1 = {
        U"  _||_ ",
        U" |    |",
        U" |____|",
        U" |    |",
        U"/-|__|-\\"};
    const std::vector<std::u32string> vaca1 = {
        U" (oo)",
        U" /V\\"};
    const std::vector<std::u32string> cerdo1 = {
        U" ( 'o')",
        U" /|_|\\"};
    const std::vector<std::u32string> gallina1 = {
        U"  _",
        U" (v)",
        U" /_\\"};
    const std::vector<std::u32string> tractor1 = {
        U"  ____",
        U" /|_||\\`.__",
        U"(   _    _ _\\",
        U"=`-(_)--(_)-'"};
    const std::vector<std::u32string> arbol1 = {
        U"  &&&",
        U" &&&&&",
        U"   |"};

    GestorDibujos gestor;
    gestor.Agregar(Dibujo(2, 1, granja1, ftxui::Color::White));     // granja blanca
    gestor.Agregar(Dibujo(15, 2, arbol1, ftxui::Color::Green));     // árbol verde
    gestor.Agregar(Dibujo(8, 10, vaca1, ftxui::Color::GrayLight));  // vaca gris
    gestor.Agregar(Dibujo(20, 11, vaca1, ftxui::Color::GrayLight)); // vaca gris
    gestor.Agregar(Dibujo(5, 12, cerdo1, ftxui::Color::Magenta));   // cerdo rosa
    gestor.Agregar(Dibujo(25, 13, gallina1, ftxui::Color::Yellow)); // gallina amarilla
    gestor.Agregar(Dibujo(30, 8, tractor1, ftxui::Color::Red));     // tractor rojo

    int frames = 120;
    for (int frame = 0; frame < frames; ++frame)
    {
        // Limpia la pantalla
        screen.Clear();

        // Animación: mover vacas y tractor
        gestor.dibujos[2].x = 8 + (frame % 10);  // vaca1
        gestor.dibujos[3].x = 20 - (frame % 10); // vaca2
        gestor.dibujos[6].x = 30 + (frame % 15); // tractor hacia la derecha

        gestor.DibujarTodos(screen);

        // Imprime la pantalla y resetea el cursor
        std::cout << screen.ToString();
        std::cout << screen.ResetPosition();
        std::cout << std::flush;

        std::this_thread::sleep_for(std::chrono::milliseconds(120));
    }
    return 0;
}
