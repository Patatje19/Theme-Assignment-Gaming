#include "helicopter.h"

namespace academy {
	helicopter::helicopter(game_data_ref data) : _data(data) {
		_animation_iterator = 0;

		_animation_frames.push_back(this->_data->assets.get_texture("helicopter_frame_1"));
		_animation_frames.push_back(this->_data->assets.get_texture("helicopter_frame_2"));
		_animation_frames.push_back(this->_data->assets.get_texture("helicopter_frame_3"));
		_animation_frames.push_back(this->_data->assets.get_texture("helicopter_frame_4"));

		_helicopter_sprite.setTexture(_animation_frames.at(_animation_iterator));

		_helicopter_sprite.setPosition
		((_data->window.getSize().x / 4) - (_helicopter_sprite.getGlobalBounds().width / 2),
			(_data->window.getSize().y / 2) - (_helicopter_sprite.getGlobalBounds().height / 2));

		_helicopter_state = HELICOPTER_STATE_STILL;

		sf::Vector2f origin = sf::Vector2f
		(_helicopter_sprite.getGlobalBounds().width / 2, _helicopter_sprite.getGlobalBounds().height / 2);

		_helicopter_sprite.setOrigin(origin);

		_rotation = 0;

	}

	void helicopter::draw() {
		_data->window.draw(_helicopter_sprite);

	}

	void helicopter::animate(float dt) {
		if (_clock.getElapsedTime().asSeconds() > HELICOPTER_ANIMATION_DURATION / _animation_frames.size()) {
			if (_animation_iterator < _animation_frames.size() - 1) {
				_animation_iterator++;

			}

			else {
				_animation_iterator = 0;

			}

			_helicopter_sprite.setTexture(_animation_frames.at(_animation_iterator));

			_clock.restart();

		}

	}

	void helicopter::set_range() {
		if(_helicopter_sprite.getPosition().x < 0){
			_helicopter_sprite.setPosition(0 , _helicopter_sprite.getPosition().y);

		}

		if(_helicopter_sprite.getPosition().y < 0) {
			_helicopter_sprite.setPosition(_helicopter_sprite.getPosition().x , 0);

		}

		if(_helicopter_sprite.getPosition().x > SCREEN_WIDTH) {
			_helicopter_sprite.setPosition(SCREEN_WIDTH, _helicopter_sprite.getPosition().y);

		}

		if(_helicopter_sprite.getPosition().y > SCREEN_HEIGHT) {
			_helicopter_sprite.setPosition(_helicopter_sprite.getPosition().x, SCREEN_HEIGHT);

		}

	}

	void helicopter::update(float dt) {
		helicopter::set_range();

		if (HELICOPTER_STATE_FALLING == _helicopter_state) {
			_helicopter_sprite.move(0, FLYING_SPEED * dt);

		}

		else if (HELICOPTER_STATE_FLYING == _helicopter_state) {
			_helicopter_sprite.move(0, -FLYING_SPEED * dt);

		}

		else if (HELICOPTER_STATE_RIGHT == _helicopter_state) {
			_helicopter_sprite.move(FLYING_SPEED * dt, 0);

		}

		else if (HELICOPTER_STATE_LEFT == _helicopter_state) {
			_helicopter_sprite.move(-FLYING_SPEED * dt, 0);

		}

		if (_movement_clock.getElapsedTime().asSeconds() > FLYING_DURATION) {
			_movement_clock.restart();
			_helicopter_state = HELICOPTER_STATE_STILL;

		}

	}

	void helicopter::click_mouse() {
		_movement_clock.restart();
		_helicopter_state = HELICOPTER_STATE_FLYING;

	}

	void helicopter::press_button_up() {
		_movement_clock.restart();
		_helicopter_state = HELICOPTER_STATE_FLYING;

	}

	void helicopter::press_button_down() {
		_movement_clock.restart();
		_helicopter_state = HELICOPTER_STATE_FALLING;

	}

	void helicopter::press_button_right() {
		_movement_clock.restart();
		_helicopter_state = HELICOPTER_STATE_RIGHT;

	}

	void helicopter::press_button_left() {
		_movement_clock.restart();
		_helicopter_state = HELICOPTER_STATE_LEFT;

	}

	const sf::Sprite& helicopter::get_sprite() const {
		return _helicopter_sprite;

	}

}
