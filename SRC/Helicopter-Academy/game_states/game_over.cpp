#include "game_over.h"

/*********************************************************************************************************************/

namespace academy {
	void game_over::read_high_score() {
		std::ifstream read_file;

		read_file.open("resources/high_score.txt");

		if (read_file.is_open()) {
			while (!read_file.eof()) {
				read_file >> _high_score;

			}

		}

		read_file.close();

		std::ofstream write_file("resources/high_score.txt");

		if (write_file.is_open()) {
			if (_score > _high_score) {
				_high_score = _score;

			}

			write_file << _high_score;

		}

		write_file.close();

	}

}

/*********************************************************************************************************************/

namespace academy {
	void game_over::init() {
		read_high_score();

		this->_data->assets.load_texture("game_background", GAME_OVER_BACKGROUND_FILEPATH);
		this->_data->assets.load_texture("game_over_body", GAME_OVER_BODY_FILEPATH);
		this->_data->assets.load_texture("game_over_title", GAME_OVER_TITLE_FILEPATH);
		
		this->_data->assets.load_texture("retry_button", RETRY_BUTTON_FILEPATH);

		_background.setTexture(this->_data->assets.get_texture("game_background"));
		_game_over_container.setTexture(this->_data->assets.get_texture("game_over_body"));
		_game_over_title.setTexture(this->_data->assets.get_texture("game_over_title"));
		
		_retry_button.setTexture(this->_data->assets.get_texture("retry_button"));

		_background_music.openFromFile(GAME_OVER_STATE_SOUND_FILEPATH);
		_background_music.play();

		_game_over_container.setPosition(sf::Vector2f
		((_data->window.getSize().x / 2) - (_game_over_container.getGlobalBounds().width / 2),
		(_data->window.getSize().y / 2) - (_game_over_container.getGlobalBounds().height / 2)));

		_game_over_title.setPosition(sf::Vector2f
		((_data->window.getSize().x / 2) - (_game_over_title.getGlobalBounds().width / 2),
		_game_over_container.getPosition().y - _game_over_title.getGlobalBounds().height * (float)1.2));

		_retry_button.setPosition(sf::Vector2f
		((_data->window.getSize().x / 2) - (_retry_button.getGlobalBounds().width / 2),
		_game_over_container.getPosition().y + _game_over_container.getGlobalBounds().height +
		(_retry_button.getGlobalBounds().height * (float)0.2)));

		_score_text.setFont(this->_data->assets.get_font("helicopter_font"));
		_score_text.setString(std::to_string(_score));
		_score_text.setCharacterSize(56);
		_score_text.setFillColor(sf::Color::Red);

		_score_text.setOrigin
		(sf::Vector2f(_score_text.getGlobalBounds().width / 2, _score_text.getGlobalBounds().height / 2));
		_score_text.setPosition
		(sf::Vector2f(_data->window.getSize().x / 10 * (float)6.25, _data->window.getSize().y / (float)2.25));

		_high_score_text.setFont(this->_data->assets.get_font("helicopter_font"));
		_high_score_text.setString(std::to_string(_high_score));
		_high_score_text.setCharacterSize(56);
		_high_score_text.setFillColor(sf::Color::Red);

		_high_score_text.setOrigin
		(sf::Vector2f(_high_score_text.getGlobalBounds().width / 2, _high_score_text.getGlobalBounds().height / 2));
		_high_score_text.setPosition
		(sf::Vector2f(_data -> window.getSize().x / 10 * (float)6.25, _data -> window.getSize().y / (float)1.70));

	}

	void game_over::handle_input() {
		sf::Event event;

		while (_data -> window.pollEvent(event)) {
			if (sf::Event::Closed == event.type) {
				_background_music.stop();

				_data -> window.close();

			}

			if (this->_data->input.is_sprite_clicked(this->_retry_button, sf::Mouse::Left, this->_data->window)) {
				_background_music.stop();

				this->_data->machine.add_state(state_ref(new game_state(_data)), true);

			}

			if (this->_data->input.is_button_pressed(sf::Keyboard::Space)) {
				_background_music.stop();

				this->_data->machine.add_state(state_ref(new game_state(_data)), true);

			}

		}

	}

	void game_over::draw(float dt) {
		this->_data->window.clear();

		this->_data->window.draw(this->_background);

		_data->window.draw(_game_over_title);
		_data->window.draw(_game_over_container);

		_data->window.draw(_retry_button);

		_data->window.draw(_score_text);
		_data->window.draw(_high_score_text);

		this->_data->window.display();

	}

}
