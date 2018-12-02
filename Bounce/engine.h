#if!defined( _ENGINE_H_INCLUDED_)
#define _ENGINE_H_INCLUDED_


#include <SFML/Graphics.hpp>
using namespace sf;

// Определение игрового окна (для работы с ним подключить файл engine.h и использовать объект window)
//
extern RenderWindow window;//инициализация в другом месте (в файле drawMaps.h)
//

static const int HEIGHT_MAP = 26;//размер карты высота
static const int WIDTH_MAP = 64;//размер карты ширина 
//
// Массив карты (после загрузки карты к нему можно обращаться, чтобы проверять границы)
//
extern String TileMap[HEIGHT_MAP];//инициализация в другом месте (в файле drawMaps.cpp)


#endif // !_ENGINE_H_INCLUDED_