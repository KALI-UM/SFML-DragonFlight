#pragma once
#include "GameObject.h"

namespace sf
{
	class Sound;
}

class DSprite;
class Background_Lobby :
    public GameObject
{
public:
	Background_Lobby();
	~Background_Lobby();

	bool Initialize() override ;
	void Reset()override;
	void Update(float dt)override;

	void FadeOutBackGround(float speed);

private:
	DSprite* m_Logo;
	DSprite* m_Background[2];
	DSprite* m_LobbyCharacter;

	float m_FadeOutSpeed=-1;
	float m_CurrvColorValue;
	float m_BgmVolume;
	float m_ClickVolume;

	sf::Sound* m_BackgroundMusic;
	sf::Sound* m_ClickEffect;
};

