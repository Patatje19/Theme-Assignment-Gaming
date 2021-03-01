#ifndef ASSET_MANAGER_H
#define ASSET_MANAGER_H

#include <SFML/Graphics.hpp>
#include <map>

/// @file

namespace academy {
	/// \brief
	/// Game engine asset manager
	/// \details
	/// Class to load in and get back assets 
	class asset_manager {
	private:
		std::map<std::string, sf::Texture> _textures;
		std::map<std::string, sf::Font> _fonts;

	public:
		/// \brief
		/// Default contstructor of the asset_manager class
		asset_manager() {};

		/// \brief
		/// Load textures 
		/// \details
		/// Load textures and give them a name 
		void load_texture(std::string name, std::string file_name);

		/// \brief
		/// Load fonts
		/// \details
		/// Load fonts and give them a name 
		void load_font(std::string name, std::string file_name);

		/// \brief
		/// Get textures 
		/// \details
		/// Get textures by there given name
		sf::Texture& get_texture(std::string name);

		/// \brief
		/// Get textures 
		/// \details
		/// Get fonts by there given name
		sf::Font& get_font(std::string name);

	};

}

#endif //asset_manager.h
