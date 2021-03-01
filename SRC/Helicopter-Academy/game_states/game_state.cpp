#include "game_state.h"


namespace academy {
	void game_state::init() {
		this->_data->assets.load_texture("game_background_0", GAME_BACKGROUND_FILEPATH_0);
		this->_data->assets.load_texture("game_background_1", GAME_BACKGROUND_FILEPATH_1);

		this->_data->assets.load_texture("walls", WALL_FILEPATH);
		this->_data->assets.load_texture("wall_invisible", WALL_INVISIBLE_FILEPATH);

		this->_data->assets.load_texture("land_0", LAND_0_FILEPATH);
		this->_data->assets.load_texture("land_1_low", LAND_1_LOW_FILEPATH);
		this->_data->assets.load_texture("land_1_high", LAND_1_HIGH_FILEPATH);

		this->_data->assets.load_texture("fuels", FUEL_FILEPATH);

		this->_data->assets.load_texture("bullet", BULLET_FILEPATH);

		this->_data->assets.load_texture("enemys", ENEMY_FILEPATH);

		this->_data->assets.load_texture("helicopter_frame_1", HELICOPTER_FRAME_1_FILEPATH);
		this->_data->assets.load_texture("helicopter_frame_2", HELICOPTER_FRAME_2_FILEPATH);
		this->_data->assets.load_texture("helicopter_frame_3", HELICOPTER_FRAME_3_FILEPATH);
		this->_data->assets.load_texture("helicopter_frame_4", HELICOPTER_FRAME_4_FILEPATH);

		this->_data->assets.load_font("helicopter_font", HELICOPTER_FONT_FILEPATH);

		_background_music.openFromFile(GAME_STATE_SOUND_FILEPATH);
		_background_music.play();

		_hit_sound_buffer.loadFromFile(HIT_SOUND_FILEPATH);
		_point_sound_buffer.loadFromFile(POINT_SOUND_FILEPATH);
		_wing_sound_buffer.loadFromFile(WING_SOUND_FILEPATH);

		_hit_sound.setBuffer(_hit_sound_buffer);
		_point_sound.setBuffer(_point_sound_buffer);
		_wing_sound.setBuffer(_wing_sound_buffer);
		
		_wall = new wall(_data);
		_land = new land(_data);
		_helicopter = new helicopter(_data);
		_flash = new flash(_data);
		_fuel = new fuel(_data);
		_fuel_bar = new fuel_bar(_data);
		_bullet = new bullet(_data);
		_enemy = new enemy(_data);
		_explosion = new animation(_data, EXPLOSION, 0, 0, 192, 192, 64, (float)0.05);
		_enemy_die = new animation(_data, ENEMY_DIE, 0, 0, 40, 43, 10, (float)0.05);

		_score_display = new score_display(_data);

		_background_0.setTexture(this->_data->assets.get_texture("game_background_0"));
		_background_1.setTexture(this->_data->assets.get_texture("game_background_1"));

		_score = 0;
		_score_display->update_score(_score);

		_fuelnum = 100;
		_score_display->update_fuel(_fuelnum);

		_game_state = game_states::e_ready;

	}

	void game_state::handle_input() {
		sf::Event event;

		while (this->_data->window.pollEvent(event)) {
			if (sf::Event::Closed == event.type) {
				_background_music.stop();

				this->_data->window.close();

			}

			if (this->_data->input.is_button_pressed(sf::Keyboard::W) || this->_data->input.is_button_pressed(sf::Keyboard::Up)) {
				if (game_states::e_game_over != _game_state) {
					_game_state = game_states::e_playing;
					_helicopter->press_button_up();

					_wing_sound.play();

				}

			}

			if (this->_data->input.is_button_pressed(sf::Keyboard::S) || this->_data->input.is_button_pressed(sf::Keyboard::Down)) {
				if (game_states::e_game_over != _game_state) {
					_game_state = game_states::e_playing;
					_helicopter->press_button_down();

					_wing_sound.play();

				}

			}

			if (this->_data->input.is_button_pressed(sf::Keyboard::D) || this->_data->input.is_button_pressed(sf::Keyboard::Right)) {
				if (game_states::e_game_over != _game_state) {
					_game_state = game_states::e_playing;
					_helicopter->press_button_right();

					_wing_sound.play();

				}

			}

			if (this->_data->input.is_button_pressed(sf::Keyboard::A) || this->_data->input.is_button_pressed(sf::Keyboard::Left)) {
				if (game_states::e_game_over != _game_state) {
					_game_state = game_states::e_playing;
					_helicopter->press_button_left();

					_wing_sound.play();

				}

			}

		}

	}

	void game_state::update(float dt) {
		if (game_states::e_game_over != _game_state) {
			_helicopter->animate(dt);

		}

		if (game_states::e_playing == _game_state) {
			_score_display->update_fuel(_fuelnum);

			if (clock2.getElapsedTime().asSeconds() > 1) {
				if (_fuelnum == 0) {
					_game_state = game_states::e_game_over;

				}

				else if (_fuelnum > 100) {
					_fuelnum = 100;

				}

				_score++;

				_turn_background++;
				_turn_land++;

				_score_display->update_score(_score);
				
				_fuelnum = _fuelnum - 5;

				clock2.restart();

			}

			_wall->move_walls(dt, _score);

			if (clock.getElapsedTime().asSeconds() > WALL_SPAWN_FREQUENCY) {
				_wall->randomise_walls_offset();

				_wall->spawn_walls();

				clock.restart();

			}

			if (_score > 20) {
				if (clock6.getElapsedTime().asSeconds() > WALL_SPAWN_FREQUENCY1) {
					_wall->randomise_walls_offset();

					_wall->spawn_walls();

					clock6.restart();

				}

			}

			_land->move_land(dt , _score);
			_fuel->move_fuels(dt , _score);

			if (clock1.getElapsedTime().asSeconds() > FUELS_SPAWN_FREQUENCY) {
				_fuel->randomise_fuels_offset();

				_fuel->spawn_fuels();

				clock1.restart();

			}

			if (_change_land) {
				if (clock4.getElapsedTime().asSeconds() > LAND_SPAWN_FREQUENCY) {
					_land->randomise_land_offset();

					_land->spawn_land_low("land_0");
					_land->spawn_land_high("land_0");

					clock4.restart();

				}

				if (_turn_land == 10) {
					_change_land = false;

				}

			}

			else {
				if (clock4.getElapsedTime().asSeconds() > LAND_SPAWN_FREQUENCY) {
					_land->randomise_land_offset();

					_land->spawn_land_low("land_1_low");
					_land->spawn_land_high("land_1_high");

					clock4.restart();

				}

				if (_turn_land == 20) {
					_change_land = true;
					_turn_land = 0;

				}

			}

			_enemy->move_enemys(dt , _score);

			if (clock5.getElapsedTime().asSeconds() > ENEMY_SPAWN_FREQUENCY) {
				_enemy->randomise_enemys_offset();

				_enemy->spawn_enemys();

				clock5.restart();

			}

			_helicopter->update(dt);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left) || sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
				if (clock3.getElapsedTime().asSeconds() > BULLET_SHOOT_FREQUENCY) {
					_bullet->spawn_bullets(_collision.get_position(_helicopter->get_sprite()));
					
					clock3.restart();

				}

			}

			_bullet->move_bullets(dt);


			std::vector<sf::Sprite> _land_sprites = _land->get_sprites();
			std::vector<sf::Sprite>& _wall_sprites   = _wall->get_sprites();
			std::vector<sf::Sprite>& _fuel_sprites   = _fuel->get_sprites();
			std::vector<sf::Sprite>& _enemy_sprites  = _enemy->get_sprites();
			std::vector<sf::Sprite>& _bullet_sprites = _bullet->get_sprites();
			
			int number_of_enemys = _enemy_sprites.size();
			
			for (unsigned int i = 0; i < _land_sprites.size(); i++) {
				for (unsigned int j = 0; j < _enemy_sprites.size(); j++) {
					if (_collision.check_sprite_collision(_land_sprites.at(i), _enemy_sprites.at(j))) {
						if (_enemy->get_upspeed() <= 0) {
							_enemy->set_upspeed(2);

						}

						else {
							_enemy->set_upspeed(-2);

						}

					}

				}

			}

			for (unsigned int i = 0; i < _wall_sprites.size(); i++) {
				for (unsigned int j = 0; j < _fuel_sprites.size(); j++) {
					if (_collision.check_sprite_collision(_wall_sprites.at(i), _fuel_sprites.at(j))) {
						_fuel_sprites.erase(_fuel_sprites.begin() + j);

					}

				}

			}

			for (unsigned int i = 0; i < _land_sprites.size(); i++) {
				for (unsigned int j = 0; j < _fuel_sprites.size(); j++) {
					if (_collision.check_sprite_collision(_land_sprites.at(i), _fuel_sprites.at(j))) {
						_fuel_sprites.erase(_fuel_sprites.begin() + j);

					}

				}

			}

			for (unsigned int i = 0; i < _wall_sprites.size(); i++) {
				for (unsigned int j = 0; j < _enemy_sprites.size(); j++) {
					if (_collision.check_sprite_collision(_wall_sprites.at(i), _enemy_sprites.at(j))) {
						_enemy_sprites.erase(_enemy_sprites.begin() + j);

					}

					if (_enemy_sprites.size() != number_of_enemys) {
						break;

					}

				}

			}

			for (unsigned int i = 0; i < _land_sprites.size(); i++) {
				for (unsigned int j = 0; j < _wall_sprites.size(); j++) {
					if (_collision.check_sprite_collision(_land_sprites.at(i), _wall_sprites.at(j))) {
						_land_sprites.erase(_land_sprites.begin() + i);

					}

				}

			}

			for (unsigned int i = 0; i < _fuel_sprites.size(); i++) {
				for (unsigned int j = 0; j < _enemy_sprites.size(); j++) {
					if (_collision.check_sprite_collision(_fuel_sprites.at(i), _enemy_sprites.at(j))) {
						_enemy_sprites.erase(_enemy_sprites.begin() + j);

					}

					if (_enemy_sprites.size() != number_of_enemys) {
						break;

					}

				}

			}

			for (unsigned int i = 0; i < _fuel_sprites.size(); i++) {
				if (_collision.check_sprite_collision(_helicopter->get_sprite(), 0.625f, _fuel_sprites.at(i), 1.0f)) {
					_point_sound.play();
					
					if(_fuelnum > 75) {
						_fuelnum = 100;

					}

					else {
						_fuelnum = _fuelnum + 25;

					}

					_fuel_sprites.erase(_fuel_sprites.begin() + i);

				}

			}

			for (unsigned int i = 0; i < _bullet_sprites.size(); i++) {
				for (unsigned int j = 0; j < _enemy_sprites.size(); j++) {
					if (_collision.check_sprite_collision(_bullet_sprites.at(i), _enemy_sprites.at(j))) {
						_enemy_die->position = sf::Vector2f
						(_collision.get_position(_enemy_sprites.at(j)).x + 20, _collision.get_position(_enemy_sprites.at(j)).y + 22);
						
						_enemy_sprites.erase(_enemy_sprites.begin() + j);
						_bullet_sprites.erase(_bullet_sprites.begin() + i);

						_enemy_die->show = true;
						_enemy_die->frame = 0.0;

					}

					if (_enemy_sprites.size() != number_of_enemys) {
						break;

					}

				}

			}

			for (unsigned int i = 0; i < _wall_sprites.size(); i++) {
				for (unsigned int j = 0; j < _bullet_sprites.size(); j++) {
					if (_collision.check_sprite_collision(_wall_sprites.at(i), _bullet_sprites.at(j))) {
						_bullet_sprites.erase(_bullet_sprites.begin() + j);

					}

				}

			}

			for (unsigned int i = 0; i < _land_sprites.size(); i++) {
				if (_collision.check_sprite_collision(_helicopter->get_sprite(), 0.725f, _land_sprites.at(i), 1.0f)) {
					_game_state = game_states::e_game_over;
					_explosion->show = true;
					_explosion->frame = 0.0;

					clock.restart();

					_hit_sound.play();

				}

			}

			for (unsigned int i = 0; i < _enemy_sprites.size(); i++) {
				if (_collision.check_sprite_collision(_helicopter->get_sprite(), 0.725f, _enemy_sprites.at(i), 1.0f)) {
					_game_state = game_states::e_game_over;
					_explosion->show = true;
					_explosion->frame = 0.0;

					clock.restart();

					_hit_sound.play();

				}

			}

			for (unsigned int i = 0; i < _wall_sprites.size(); i++) {
				if (_collision.check_sprite_collision(_helicopter->get_sprite(), 0.640f, _wall_sprites.at(i), 1.0f)) {
					_game_state = game_states::e_game_over;
					_explosion->show = true;
					_explosion->frame = 0.0;

					clock.restart();

					_hit_sound.play();
					
				}

			}

		}

		if (game_states::e_game_over == _game_state) {
			_flash->show(dt);

			_background_music.stop();

			if (clock.getElapsedTime().asSeconds() > TIME_BEFORE_GAME_OVER_APPEARS) {
				this->_data->machine.add_state(state_ref(new game_over(_data, _score)), true);

			}

		}

	}

	void game_state::draw(float dt) {
		this->_data->window.clear(sf::Color::Red);

		this->_data->window.draw(this->_background_0);

		if (_change_background) {
			this->_data->window.draw(this->_background_0);

			if (_turn_background == 5) {
				_change_background = false;
			
			}

		}

		else {
			this->_data->window.draw(this->_background_1);

			if (_turn_background == 10) {
				_change_background = true;
				_turn_background = 0;

			}

		}

		_wall->draw_walls();

		_land->draw_land();

		_fuel->draw_fuels();

		_enemy->draw_enemys();

		_helicopter->draw();

		_fuel_bar->set_fuel_percentage(_fuelnum);

		_fuel_bar->draw();

		_flash->draw();

		_bullet->draw_bullets();

		_score_display->draw();

		if(_explosion->show) {
			if(_explosion->isEnd()) {
				_explosion->show = false;

			}

			_explosion->draw(_collision.get_position(_helicopter->get_sprite()));
			_explosion->update();

		}

		if (_enemy_die->show && !_explosion->show) {
			if (_enemy_die->isEnd()) {
				_enemy_die->show = false;

			}

			_enemy_die->position = sf::Vector2f(_enemy_die->position.x - (float)0.5, _enemy_die->position.y);
			_enemy_die->draw(_enemy_die->position);
			_enemy_die->update();

		}
		
		this->_data->window.display();

	}

}
