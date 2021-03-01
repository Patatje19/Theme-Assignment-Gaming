#include "asset_manager.h"

namespace academy {
	void asset_manager::load_texture(std::string name, std::string file_name) {
		sf::Texture tex;

		if (tex.loadFromFile(file_name)) {
			this->_textures[name] = tex;

		}

	}

	void asset_manager::load_font(std::string name, std::string file_name) {
		sf::Font font;

		if (font.loadFromFile(file_name)) {
			this->_fonts[name] = font;

		}

	}

	sf::Texture& asset_manager::get_texture(std::string name) {
		return this->_textures.at(name);

	}

	sf::Font& asset_manager::get_font(std::string name) {
		return this->_fonts.at(name);

	}

}
