// Included Libraries
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>





//--------------------------------------------
//Game setup
//--------------------------------------------


// entry point for the program
int main()
{
	// Make a variable called gameWindow of type RenderWindow
	sf::RenderWindow gameWindow;
	gameWindow.create(sf::VideoMode::getDesktopMode(), "Button Masher", 
		sf::Style::Titlebar | sf::Style::Close);

	// Create Button Sprite
	sf::Texture buttonTexture;
	buttonTexture.loadFromFile("graphics/button.png");

	sf::Sprite buttonSprite;
	buttonSprite.setTexture(buttonTexture);


	buttonSprite.setTexture(buttonTexture);
	//center the sprite on the screen.
	buttonSprite.setPosition(
		gameWindow.getSize().x / 2 - buttonTexture.getSize().x / 2,
		gameWindow.getSize().y / 2 - buttonTexture.getSize().y / 2
	);

	//create music
	sf::Music gameMusic;
	gameMusic.openFromFile("audio/music.ogg");
	//gameMusic.play();

	//create font
	sf::Font gameFont;
	gameFont.loadFromFile("fonts/mainFont.ttf");


	//create Title
	sf::Text titleText;
	titleText.setFont(gameFont);
	titleText.setString("Button Masher!");
	
	titleText.setCharacterSize(100);
	titleText.setFillColor(sf::Color::Black);
	titleText.setStyle(sf::Text::Bold | sf::Text::Italic);

	titleText.setPosition(gameWindow.getSize().x / 2
		- titleText.getLocalBounds().width / 2, 30);

	sf::Text authorText;
	authorText.setFont(gameFont);
	authorText.setString("By Daniel Mckinlay");
	authorText.setCharacterSize(16);
	authorText.setFillColor(sf::Color::Yellow);
	authorText.setStyle(sf::Text::Italic);
	authorText.setPosition(gameWindow.getSize().x / 2 - authorText.getLocalBounds().width / 2, 150);


	// Game Loop
	// Runs every frame until the game window is closed
	while (gameWindow.isOpen())
	{
		// Check for input
		sf::Event gameEvent;
		while (gameWindow.pollEvent(gameEvent))
		{
			// Process events

			// Check if the event is the closed event
			if (gameEvent.type == sf::Event::Closed)
			{
				// Close the game window
				gameWindow.close();
			}
		}

		// TODO: Update game state

		// TODO: Draw graphics
		gameWindow.clear(sf::Color::Red);

		//draw everything
		gameWindow.draw(buttonSprite);
		gameWindow.draw(titleText);
		gameWindow.draw(authorText);
		
		//draw gameWindow
		gameWindow.display();

	}

	// exit point for the program
	return 0;
}