//
//  main.cpp
//  Final Project
//
//  Created by Sarika Tyagi on 11/30/16.
//  Copyright © 2016 Sarika Tyagi. All rights reserved.
//

#include <gamma.h>
#include <RGBmatrixPanel.h>
#include <Adafruit_GFX.h>

// define the wiring of the LED screen
const uint8_t CLK  = 8;
const uint8_t LAT = A3;
const uint8_t OE = 9;
const uint8_t A = A0;
const uint8_t B = A1;
const uint8_t C = A2;

// define the wiring of the inputs
const int POTENTIOMETER_PIN_NUMBER = 5;
const int BUTTON_PIN_NUMBER = 10;

// global constant for the number of Invaders in the game
const int NUM_ENEMIES = 16;

// a global variable that represents the LED screen
RGBmatrixPanel matrix(A, B, C, CLK, LAT, OE, false);

// the following functions are for printing messages
void print_level(int level);
void print_lives(int lives);
void game_over();

//CHANGES START HERE
//constants for matrix; check later for matrix array
const int PLAYER_ROWS = 2;
const int PLAYER_COLUMNS = 3;

const int MATRIX_ROWS = 16;
const int MATRIX_COLS = 32;


//create the player array
const int playerArray[PLAYER_ROWS][PLAYER_COLUMNS];




class Color {
public:
    int red;
    int green;
    int blue;
    Color() {
        red = 0;
        green = 0;
        blue = 0;
    }
    Color(int r, int g, int b) {
        red = r;
        green = g;
        blue = b;
    }
    uint16_t to_333() const {
        return matrix.Color333(red, green, blue);
    }
};

const Color BLACK(0, 0, 0);
const Color RED(7, 0, 0);
const Color ORANGE(7, 4, 0);
const Color YELLOW(7, 7, 0);
const Color GREEN(0, 7, 0);
const Color BLUE(0, 0, 7);
const Color PURPLE(7, 0, 7);
const Color WHITE(7, 7, 7);
const Color LIME(4, 7, 0);
const Color AQUA(0, 7, 7);

class Invader {
public:
    // Constructors
    Invader() {
        x = 0;
        y = 0;
        strength = 0;
    }
    // sets values for private date members x and y
    Invader(int x_arg, int y_arg) {
        x = x_arg;
        y = y_arg;
    }
    // sets values for private data members
    Invader(int x_arg, int y_arg, int strength_arg) {
        x = x_arg;
        y = y_arg;
        strength = strength_arg;
    }
    // sets values for private data members
    void initialize(int x_arg, int y_arg, int strength_arg) {
        x = x_arg;
        y = y_arg;
        strength = strength_arg;
    }
    
    // getters
    int get_x() const {
        return x;
    }
    int get_y() const {
        return y;
    }
    int get_strength() const {
        return strength;
    }
    
    // Moves the Invader down the screen by one row
    // Modifies: y
    void move() {
        y = y + 1;
        return;
    }
    
    // draws the Invader if its strength is greater than 0
    // calls: draw_with_rgb
    void draw() {
        switch (strength) {
            case 1:
                draw_with_rgb(RED, Color eye_color)
                
           }
    
    // draws black where the Invader used to be
    // calls: draw_with_rgb
    void erase() {
    }
    
    // Invader is hit by a Cannonball.
    // Modifies: strength
    // calls: draw, erase
    void hit() {
    }
    
private:
    int x;
    int y;
    int strength;
    
    // draws the Invader
    void draw_with_rgb(Color body_color, Color eye_color) {
        
    }
};

class Cannonball {
public:
    Cannonball() {
        x = 0;
        y = 0;
        fired = false;
    }
    
    // resets private data members to initial values
    void reset() {
    }
    
    // getters
    int get_x() const {
    }
    int get_y() const {
    }
    bool has_been_fired() const {
    }
    
    // sets private data members
    void fire(int x_arg, int y_arg) {
    }
    
    // moves the Cannonball and detects if it goes off the screen
    // Modifies: y, fired
    void move() {
    }
    
    // resets private data members to initial values
    void hit() {
    }
    
    // draws the Cannonball, if it is fired
    void draw() {
    }
    
    // draws black where the Cannonball used to be
    void erase() {
    }
    
private:
    int x;
    int y;
    bool fired;
};

class Player {
public:
    Player() {
        x = 0;
        y = 0;
        lives = 3;
    }
    
    // getters
    int get_x() const {
    }
    int get_y() const {
    }
    int get_lives() const {
    }
    
    // setter
    void set_x(int x_arg) {
    }
    
    // Modifies: lives
    void die() {
    }
    
    // draws the Player
    // calls: draw_with_rgb
    void draw() {
        
        
        
    }
    
    // draws black where the Player used to be
    // calls: draw_with_rgb
    void erase() {
    }
    
private:
    int x;
    int y;
    int lives;
    
    // sets private data members x and y to initial values
    void initialize(int x_arg, int y_arg) {
    }
    
    // draws the player
    void draw_with_rgb(Color color) {
        
    }
};

class Game {
public:
    Game() {
        level = 0;
        time = 0;
    }
    
    // returns enemy at specified index, if in bounds
    Invader get_enemy(int index) {
    }
    
    // sets up a new game of Space Invaders
    // Modifies: global variable matrix
    // see http://arduino.cc/en/Reference/Setup
    void setup() {
    }
    
    // displays and runs Space Invaders!
    // see spec for details of game
    // Modifies: global variable matrix
    void loop(int potentiometer_value, bool button_pressed) {
    }
    
private:
    int level;
    int time;
    Player player;
    Cannonball ball;
    Invader enemies[NUM_ENEMIES];
    
    // check if Player defeated all Invaders in current level
    bool level_cleared() {
    }
    
    // set up a level
    void reset_level() {
    }
};

// a global variable that represents the game Space Invaders
Game game;

// see http://arduino.cc/en/Reference/Setup
void setup() {
    Serial.begin(9600);
    pinMode(BUTTON_PIN_NUMBER, INPUT);
    matrix.begin();
}

// see http://arduino.cc/en/Reference/Loop
void loop() {
    int potentiometer_value = analogRead(POTENTIOMETER_PIN_NUMBER);
    bool button_pressed = (digitalRead(BUTTON_PIN_NUMBER) == HIGH);
    
    game.loop(potentiometer_value, button_pressed);
}

// displays Level
void print_level(int level) {
}

// displays number of lives
void print_lives(int lives) {
}

// displays "game over"
void game_over() {
}



