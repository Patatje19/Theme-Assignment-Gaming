#ifndef DEFINITIONS_H
#define DEFINITIONS_H

enum game_states { e_ready, e_playing, e_game_over };

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

#define SPLASH_STATE_SHOW_TIME 1.0

#define SPLASH_SCENE_BACKGROUND_FILEPATH "resources/res/background/splash_state.png"

#define MAIN_MENU_BACKGROUND_FILEPATH "resources/res/background/menu_state.png"
#define GAME_BACKGROUND_FILEPATH_0    "resources/res/background/game_state_0.png"
#define GAME_BACKGROUND_FILEPATH_1    "resources/res/background/game_state_1.png"
#define GAME_OVER_BACKGROUND_FILEPATH "resources/res/background/game_over_state.png"

#define GAME_TITLE_FILEPATH  "resources/res/menu_state/title.png"
#define PLAY_BUTTON_FILEPATH "resources/res/menu_state/play_button.png"

#define WALL_FILEPATH           "resources/res/game_state/wall.png"
#define WALL_INVISIBLE_FILEPATH "resources/res/game_state/wall_invisible.png"

#define LAND_0_FILEPATH      "resources/res/game_state/land_0.png"
#define LAND_1_LOW_FILEPATH  "resources/res/game_state/land_1_low.png"
#define LAND_1_HIGH_FILEPATH "resources/res/game_state/land_1_high.png"

#define FUEL_FILEPATH "resources/res/game_state/fuel.png"

#define BULLET_FILEPATH "resources/res/game_state/bullet.png"

#define ENEMY_FILEPATH "resources/res/game_state/enemy.png"

#define GREEN_BAR_FILEPATH "resources/res/game_state/green_bar.png"
#define GRAY_BAR_FILEPATH  "resources/res/game_state/gray_bar.png"

#define HELICOPTER_FRAME_1_FILEPATH "resources/res/game_state/helicopter_1.png"
#define HELICOPTER_FRAME_2_FILEPATH "resources/res/game_state/helicopter_2.png"
#define HELICOPTER_FRAME_3_FILEPATH "resources/res/game_state/helicopter_3.png"
#define HELICOPTER_FRAME_4_FILEPATH "resources/res/game_state/helicopter_4.png"

#define HELICOPTER_FONT_FILEPATH "resources/fonts/helicopter_font.ttf"

#define GAME_OVER_TITLE_FILEPATH "resources/res/game_over_state/game_over_title.png"
#define RETRY_BUTTON_FILEPATH    "resources/res/game_over_state/retry_button.png"
#define GAME_OVER_BODY_FILEPATH  "resources/res/game_over_state/game_over_body.png"

#define EXPLOSION "resources/res/game_state/explosions/type_B.png"
#define ENEMY_DIE "resources/res/game_state/enemy_dies.png"

#define GAME_OVER_STATE_SOUND_FILEPATH "resources/audio/game_states/game_over_state.ogg"
#define GAME_STATE_SOUND_FILEPATH      "resources/audio/game_states/game_state.ogg"
#define MAIN_MENU_STATE_SOUND_FILEPATH "resources/audio/game_states/main_menu_state.ogg"

#define HIT_SOUND_FILEPATH   "resources/audio/hit.wav"
#define POINT_SOUND_FILEPATH "resources/audio/point.wav"
#define WING_SOUND_FILEPATH  "resources/audio/wing.wav"

#define WALL_MOVEMENT_SPEED   300.0f
#define WALL_SPAWN_FREQUENCY  1.0f
#define WALL_SPAWN_FREQUENCY1 1.5f

#define LAND_MOVEMENT_SPEED  300.0f
#define LAND_SPAWN_FREQUENCY 0.10f  

#define HELICOPTER_ANIMATION_DURATION 0.4f

#define HELICOPTER_STATE_STILL   1
#define HELICOPTER_STATE_FALLING 2
#define HELICOPTER_STATE_FLYING  3
#define HELICOPTER_STATE_RIGHT   4
#define HELICOPTER_STATE_LEFT    5

#define GRAVITY      0.0f
#define FLYING_SPEED 300.0f

#define FLYING_DURATION 0.25f

#define ROTATION_SPEED 100.0f

#define FLASH_SPEED 1500.0f

#define TIME_BEFORE_GAME_OVER_APPEARS 1.5f

#define FUELS_MOVEMENT_SPEED  200.0f
#define FUELS_SPAWN_FREQUENCY 1.0f


#define BULLET_MOVEMENT_SPEED  -500.0f
#define BULLET_SHOOT_FREQUENCY 0.5f

#define ENEMY_MOVEMENT_SPEED  500.0f
#define ENEMY_SPAWN_FREQUENCY 1.9f

#endif
