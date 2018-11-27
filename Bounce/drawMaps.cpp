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
			if (TileMap[i][j] == ' ')  s_map.setTextureRect(IntRect(0, 0, 32, 32)); //���� ��������� ������ ������, �� ������ 1� ���������
			if (TileMap[i][j] == 's')  s_map.setTextureRect(IntRect(32, 0, 32, 32));//���� ��������� ������ s, �� ������ 2� ���������
			if (TileMap[i][j] == '0') s_map.setTextureRect(IntRect(96, 0, 32, 32));//���� ��������� ������ 0, �� ������ 3� ���������
			if (TileMap[i][j] == 'F') s_map.setTextureRect(IntRect(96, 0, 32, 32));//���� ��������� ������ 0, �� ������ 3� ���������
			if (TileMap[i][j] == '+')  s_map.setTextureRect(IntRect(128, 0, 32, 32));//���� ��������� ������ s, �� ������ 4� ���������
			if (TileMap[i][j] == '-') s_map.setTextureRect(IntRect(160, 0, 32, 32));//���� ��������� ������ 0, �� ������ 5� ���������
			if (TileMap[i][j] == 'R') s_map.setTextureRect(IntRect(192, 0, 32, 32));//���� ��������� ������ 0, �� ������ 5� ���������

			if (TileMap[i][j] == 'b') s_map.setTextureRect(IntRect(64, 0, 32, 32));//!!!�������� �� ���� ��� ����
			if (TileMap[i][j] == 'A') s_map.setTextureRect(IntRect(64, 0, 32, 32));//!!!�������� �� ���� ��� ����
			s_map.setPosition(j * 32, i * 32);//�� ���� ����������� ����������, ��������� � �����. �� ���� ������ ������� �� ��� �������. ���� ������, �� ��� ����� ���������� � ����� �������� 32*32 � �� ������ ���� 
			
			window.draw(s_map);//������ ���������� �� �����
		}
}

void drawMap::loadLevelFromFile(int num_level) {
	string line;
	ifstream myfile("level"+ to_string(num_level)+".level");
	//ifstream myfile("level1.level");
	int i = 0;
	if (myfile.is_open())
	{
		while (!myfile.eof())
		{
			getline(myfile, line);
			TileMap[i] = line;
			//cout << TileMap[i] << endl;
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