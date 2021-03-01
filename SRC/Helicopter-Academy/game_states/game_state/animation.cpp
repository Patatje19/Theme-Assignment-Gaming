#include "animation.h"

namespace academy {
	animation::animation
	(game_data_ref data, std::string s, float x, float y, float w, float h, int count, float Speed) : _data(data) {
		frame = 0;
		speed = Speed;

		t.loadFromFile(s);

		for(int i = 0; i < count; i++) {
			frames.push_back(sf::IntRect((int)x + i * (int)w, (int)y, (int)w, (int)h));

		}

		sprite.setPosition(x, y);
		sprite.setTexture(t);
		sprite.setOrigin(w / 2, h / 2);
		sprite.setTextureRect(frames[0]);

		show = false;

	}

	void animation::draw(sf::Vector2f pos) {
		sprite.setPosition(pos);
		_data->window.draw(sprite);

	}

	void animation::update() {
		frame += speed;
		n = frames.size();
		
		if (frame >= n) {
			frame -= n;

		}

		if (n > 0) {
			sprite.setTextureRect(frames[int(frame)]);

		}

	}

	bool animation::isEnd() {
		return frame + speed >= frames.size();
		
	}
	
}
