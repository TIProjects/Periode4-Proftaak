#include "LifeBar.h"

LifeBar::LifeBar(Vec3f pos, float width, float height, std::vector<std::string> paths, int size, int sections) : GUIElement(pos)
{
	_Width = width;
	_Height = height;
	_Sections = sections;
	_Life = sections;
	int i = 0;
	for(std::string var : paths)
	{
		if(i != 2) _Images.push_back(Image(pos, width, height, var));
		else {
			float x = pos.x;
			for (int i2 = 1; i2 < sections; i2++) {
				pos.x = (width / sections*i2);
				_Images.push_back(Image(pos, (width/100), height, var));
			}
			pos.x = x;
		}
		i++;
	}
	Decrement();
	Increment();
}

void LifeBar::Increment()
{
	if (_Life < _Sections) {
		_Life++;
		_Images[1].SetWidth(_Width / _Sections*_Life-_Width/110);
	}
}

void LifeBar::Decrement()
{
	if (_Life > 0) {
		_Life--;
		if(_Life == 0) _Images[1].SetWidth(_position.x- _Width / 110);
		else _Images[1].SetWidth(_Width / _Sections*_Life - _Width / 110);
	}
}

void LifeBar::Draw()
{
	for each(Image var in _Images)
	{
		var.Draw();
	}
}
