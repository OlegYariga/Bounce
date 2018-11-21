#include "engine.h"
#include "drawMaps.h"

RenderWindow window(sf::VideoMode(1200, 600), "Bounce");//���������������� ������ ���� ����


drawMap::drawMap() {//����������� ������

	image1.loadFromFile("map1.jpeg");// ��������� �������� �� �����

	map.loadFromImage(image1);//�������� �������� ���������

	s_map.setTexture(map);//�������� �������� ��������

}
drawMap::~drawMap() {

}

void drawMap::drawing_level() {// ������� ��������� ������

	for (int i = 0; i < HEIGHT_MAP; i++)
		for (int j = 0; j < WIDTH_MAP; j++)
		{
			if (TileMap[i][j] == ' ')  s_map.setTextureRect(IntRect(0, 0, 32, 32)); //���� ��������� ������ ������, �� ������ 1� ���������
			if (TileMap[i][j] == 's')  s_map.setTextureRect(IntRect(32, 0, 32, 32));//���� ��������� ������ s, �� ������ 2� ���������
			if (TileMap[i][j] == '0') s_map.setTextureRect(IntRect(96, 0, 32, 32));//���� ��������� ������ 0, �� ������ 3� ���������
			if (TileMap[i][j] == '+')  s_map.setTextureRect(IntRect(128, 0, 32, 32));//���� ��������� ������ s, �� ������ 4� ���������
			if (TileMap[i][j] == '-') s_map.setTextureRect(IntRect(160, 0, 32, 32));//���� ��������� ������ 0, �� ������ 5� ���������
			if (TileMap[i][j] == 'R') s_map.setTextureRect(IntRect(192, 0, 32, 32));//���� ��������� ������ 0, �� ������ 5� ���������

			if (TileMap[i][j] == 'b') s_map.setTextureRect(IntRect(64, 0, 32, 32));//!!!�������� �� ���� ��� ����
			if (TileMap[i][j] == 'A') s_map.setTextureRect(IntRect(64, 0, 32, 32));//!!!�������� �� ���� ��� ����
			s_map.setPosition(j * 32, i * 32);//�� ���� ����������� ����������, ��������� � �����. �� ���� ������ ������� �� ��� �������. ���� ������, �� ��� ����� ���������� � ����� �������� 32*32 � �� ������ ���� 
			
			window.draw(s_map);//������ ���������� �� �����
		}
}

String TileMap[HEIGHT_MAP] = {// ����������� ����� (� ������� ������� �������� �� �����)
	"0000000000000000000000000000000000000000",
	"0000000000000000000++++++++            0",
	"0      000000000000                    0",
	"0      000000000000                    0",
	"0      000000000000                    0",
	"0                                      0",
	"0                                      0",
	"0                 0  bb                0",
	"0                 0                    0",
	"0               000                    0",
	"0                 0Abbbbbbb  0         0",
	"0             00000----------0         0",
	"0000000RRRRR0000000000000000000000000000",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0000000000000000000000000000000000000000",
};