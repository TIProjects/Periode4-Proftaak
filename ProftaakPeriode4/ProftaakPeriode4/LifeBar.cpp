#include "LifeBar.h"

LifeBar::LifeBar(Vec3f pos, float width, float height, int sections, std::string background, std::string frame, std::string bar, std::string segment)
{
	_width = width;
	_height = height;
	_sections = sections;
	_life = sections;
	_pos = pos;

	_background = new Image(pos, width, height, background);
	_frame = new Image(pos, width, height, frame);
	_segment = new Image(pos, width / 100, height, segment);
	_bar = new Image(pos, width, height, bar);


}

int LifeBar::Increment()
{
	if (_life < _sections) {
		_life++;
		_bar->SetWidth(_width / _sections*_life+_width/100);
	}
	return _life;
}

int LifeBar::Decrement()
{
	if (_life > 0) {
		_life--;
		if(_life == 0) _bar->SetWidth(_position.x+ _width / 100);
		else _bar->SetWidth(_width / _sections*_life + _width / 100);
	}
	return _life;
}

void LifeBar::Draw()
{
	_background->Draw();
	_bar->Draw();
	float placed = 0;
	for (int i = 0; i < _sections; i++) {
		Vec3f pos = Vec3f(_pos.x + placed, _pos.y, _pos.z);
		_segment->SetPosition(pos);
		_segment->Draw();
		placed += _width / _sections;
	}
	_frame->Draw();
	
}
