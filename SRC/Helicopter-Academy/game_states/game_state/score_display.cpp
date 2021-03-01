#include "score_display.h"

namespace academy {
	score_display::score_display(game_data_ref data) : _data(data) {
		_score_text.setFont(this->_data->assets.get_font("helicopter_font"));
		_score_text.setString("0");
		_score_text.setCharacterSize(128);
		_score_text.setFillColor(sf::Color::White);

		_score_text.setOrigin        
		(sf::Vector2f(_score_text.getGlobalBounds().width / 2, _score_text.getGlobalBounds().height / 2));
		_score_text.setPosition
		(sf::Vector2f((float)_data->window.getSize().x / 2, (float)_data->window.getSize().y / 5));


		_fuel_text.setFont(this->_data->assets.get_font("helicopter_font"));
		_fuel_text.setString("0");
		_fuel_text.setCharacterSize(60);
		_fuel_text.setFillColor(sf::Color::Red);

		_fuel_text.setOrigin
		(sf::Vector2f(_fuel_text.getGlobalBounds().width + 110 , _fuel_text.getGlobalBounds().height -10));
		_fuel_text.setPosition
		(sf::Vector2f((float)_data->window.getSize().x / 8, (float)_data->window.getSize().y / 8));

	}

	void score_display::draw() {
		_data->window.draw(_score_text);
		_data->window.draw(_fuel_text);

	}

	void score_display::update_score(int score) {
		_score_text.setString(std::to_string(score));

	}

	void score_display::update_fuel(int fuel) {
		_fuel_text.setString(std::to_string(fuel));

	}

}
