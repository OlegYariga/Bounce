#pragma once
#include "engine.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
//#include <fstream>

using namespace sf;

class drawMap {
public:
		//static const int HEIGHT_MAP = 25;//������ ����� ������
		//static const int WIDTH_MAP = 40;//������ ����� ������ 
		Image image1;
		Texture map;//�������� �����
		Sprite s_map;//������ ������ ��� �����
		//String TileMap[]; //!!!!!!!!�������� ������� ����� ��� �������� ����� ����� ��������� ����
		
		


		drawMap() {//����������� ������
			
			image1.loadFromFile("map1.jpeg");// ��������� �������� �� �����

			map.loadFromImage(image1);//�������� �������� ���������

			s_map.setTexture(map);//�������� �������� ��������
			
			
		}
		~drawMap() {//���������� 
		}

		void drawing_level() {// ������� ��������� ������

			//RenderWindow window(sf::VideoMode(1200, 600), "Bounce");
			

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

};