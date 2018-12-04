#include "engine.h"
#include "drawMaps.h"
#include <fstream>
#include <string>

using namespace std;
//int num_level = 1;


RenderWindow window(sf::VideoMode(1200, 600), "Bounce", sf::Style::None);//���������������� ������ ���� ����


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
			switch (TileMap[i][j])
			{
			case ' ': {
				s_map.setTextureRect(IntRect(0, 0, 32, 32));
				break;
			}
			case '0': {
				s_map.setTextureRect(IntRect(96, 0, 32, 32));
				break;
			}
			case 'F': {
				s_map.setTextureRect(IntRect(96, 0, 32, 32));
				break;
			}
			default:
				s_map.setTextureRect(IntRect(0, 0, 32, 32));
				break;
			}

			s_map.setPosition(j * 32, i * 32);//�� ���� ����������� ����������, ��������� � �����. �� ���� ������ ������� �� ��� �������. ���� ������, �� ��� ����� ���������� � ����� �������� 32*32 � �� ������ ���� 
			
			window.draw(s_map);//������ ���������� �� �����
		}
}

void drawMap::loadLevelFromFile(int num_level) {
	string line;
	ifstream myfile("level"+ to_string(num_level)+".level");
	int i = 0;
	if (myfile.is_open())
	{
		while (!myfile.eof())
		{
			getline(myfile, line);
			TileMap[i] = line;
			i++;
		}
		myfile.close();
	}
}


String TileMap[HEIGHT_MAP] = {// ����������� ����� (� ������� ������� �������� �� �����)
	"bbbbbbbbbbbbbbbbbbb0bbbbbbbbbbbbbbbbbbb0",
	"0000000000000000000++++++++            0",
	"0      000000000000                    0",
	"0      000000000000                    0",
	"0      000000000000                    0",
	"0                                      0",
	"0                                      0",
	"0                 0                    0",
	"0                 0                    0",
	"0               000          0         0",
	"0                 0 A        0         0",
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