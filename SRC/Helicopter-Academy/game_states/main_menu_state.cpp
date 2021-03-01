#include "main_menu_state.h"


namespace academy {
	void main_menu_state::init() {
		this->_data->assets.load_texture("main_menu_background", MAIN_MENU_BACKGROUND_FILEPATH);
		this->_data->assets.load_texture("game_title", GAME_TITLE_FILEPATH);
		this->_data->assets.load_texture("play_button", PLAY_BUTTON_FILEPATH);

		_background.setTexture(this->_data->assets.get_texture("main_menu_background"));
		_title.setTexture(this->_data->assets.get_texture("game_title"));
		_play_button.setTexture(this->_data->assets.get_texture("play_button"));

		_background_music.openFromFile(MAIN_MENU_STATE_SOUND_FILEPATH);
		_background_music.play();

		_play_button.setPosition
		((SCREEN_WIDTH / 2) - (_play_button.getGlobalBounds().width / 2),
		(SCREEN_HEIGHT / 2) - (_play_button.getGlobalBounds().height / 2));

	}

	void main_menu_state::handle_input() {
		sf::Event event;

		while (this->_data->window.pollEvent(event)) {
			if (sf::Event::Closed == event.type) {
				_background_music.stop();

				this->_data->window.close();

			}

			if (this->_data->input.is_sprite_clicked(this->_play_button, sf::Mouse::Left, this->_data->window)) {
				_background_music.stop();

				this->_data->machine.add_state(state_ref(new game_state(_data)), true);

			}

			if (this->_data->input.is_button_pressed(sf::Keyboard::Space)) {
				_background_music.stop();

				this->_data->machine.add_state(state_ref(new game_state(_data)), true);

			}

		}

	}

	void main_menu_state::draw(float dt) {
		this->_data->window.clear(sf::Color::Red);

		this->_data->window.draw(this->_background);
		this->_data->window.draw(this->_title);
		this->_data->window.draw(this->_play_button);

		this->_data->window.display();

	}

}
