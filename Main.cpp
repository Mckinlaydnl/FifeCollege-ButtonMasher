// Included Libraries
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>


//entry point for the program

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


	sf::Text promptText;
	promptText.setFont(gameFont);
	promptText.setString("Click the button to start game");
	promptText.setCharacterSize(16);
	promptText.setFillColor(sf::Color::Yellow);
	promptText.setStyle(sf::Text::Italic);
	promptText.setPosition(gameWindow.getSize().x / 2 - promptText.getLocalBounds().width / 2, 200);
	//Score
	int score = 0;

	//score text
	sf::Text scoreText;
	scoreText.setFont(gameFont);
	scoreText.setString("Score: " + std::to_string(score));
	scoreText.setCharacterSize(16);
	scoreText.setFillColor(sf::Color::Black);
	scoreText.setPosition(30,30);

	sf::Text timerText;
	timerText.setFont(gameFont);
	timerText.setString("Time Remaining: 0");
	timerText.setCharacterSize(16);
	timerText.setFillColor(sf::Color::Black);
	timerText.setPosition(gameWindow.getSize().x - timerText.getLocalBounds().width - 30, 30);



	//timer functionality
	sf::Time timeLimit = sf::seconds(10.0f); //20.0
	sf::Time timeRemaining = timeLimit;
	sf::Clock gameClock;

	//click sound effect
	sf::SoundBuffer clickBuffer;
	clickBuffer.loadFromFile("audio/buttonclick.ogg");
	sf::Sound clickSound;
	clickSound.setBuffer(clickBuffer);

	//click sound effect
	sf::SoundBuffer gameoverBuffer;
	gameoverBuffer.loadFromFile("audio/gameover.ogg");
	sf::Sound gameoverSound;
	gameoverSound.setBuffer(gameoverBuffer);


	//Game state
	bool playing = false;


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
			if (gameEvent.type == sf::Event::MouseButtonPressed)
			{
				// Close the game window
				if (buttonSprite.getGlobalBounds().contains(gameEvent.mouseButton.x,gameEvent.mouseButton.y)) 
				{
					//We clicked the button
					
					if (playing == true)
					{
						score = score + 1;
					}
					else
					{//no - start playing now
						playing = true;

						//reset the game data
						score = 0;
						timeRemaining = timeLimit;

						promptText.setString("Click the button as fast as you can!");
					}

					//play click sound
					clickSound.play();
				}
			}

			// Check if the event is the closed event
			if (gameEvent.type == sf::Event::Closed)
			{
				// Close the game window
				gameWindow.close();
			}
		}

		//update game state
		sf::Time frameTime = gameClock.restart();


		if (playing == true)
		{
			timeRemaining = timeRemaining - frameTime;
			if (timeRemaining.asSeconds() <= 0.0f)
			{
				timeRemaining = sf::seconds(0.0f);
				playing = false;
				promptText.setString("Your final score was: " + std::to_string(score) + "! Click the button to start a new game");
				//play click sound
				gameoverSound.play();
			}
		}

		//update out text displays based on data
		timerText.setString("Time Remaining: " + std::to_string((int)timeRemaining.asSeconds()));


		// TODO: Update game state
		//score = score + 1;
		scoreText.setString("Score: " + std::to_string(score));
		// TODO: Draw graphics
		gameWindow.clear(sf::Color::Red);

		//draw everything
		gameWindow.draw(buttonSprite);
		gameWindow.draw(titleText);
		gameWindow.draw(authorText);
		gameWindow.draw(scoreText);
		gameWindow.draw(timerText);
		gameWindow.draw(promptText);
		
		//draw gameWindow
		gameWindow.display();

	}

	// exit point for the program
	return 0;
}