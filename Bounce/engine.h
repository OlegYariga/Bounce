#if!defined( _ENGINE_H_INCLUDED_)
#define _ENGINE_H_INCLUDED_


#include <SFML/Graphics.hpp>
using namespace sf;

// ����������� �������� ���� (��� ������ � ��� ���������� ���� engine.h � ������������ ������ window)
//
extern RenderWindow window;//������������� � ������ ����� (� ����� drawMaps.h)
//

static const int HEIGHT_MAP = 25;//������ ����� ������
static const int WIDTH_MAP = 40;//������ ����� ������ 
//
// ������ ����� (����� �������� ����� � ���� ����� ����������, ����� ��������� �������)
//
extern String TileMap[HEIGHT_MAP];//������������� � ������ ����� (� ����� drawMaps.cpp)


#endif // !_ENGINE_H_INCLUDED_