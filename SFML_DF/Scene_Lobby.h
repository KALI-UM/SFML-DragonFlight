#pragma once
#include "SceneBase.h"
class Background_Lobby;
<<<<<<< HEAD
class SoundObject;
class DieEffect;
=======
class GameStart;
>>>>>>> origin/master
class Scene_Lobby :
    public SceneBase
{
public:
	Scene_Lobby();
	~Scene_Lobby();

protected:
	bool Initialize() override;
	void Reset() override;
	void Update(float dt) override;
	void Release() override;


private:
	Background_Lobby* m_LobbyImage;
<<<<<<< HEAD
	SoundObject* m_SoundObject;
	std::vector< DieEffect*> m_Effects;

=======
	GameStart* m_GameStart;
	bool m_Start = false;
>>>>>>> origin/master
	float m_FadeSpeed;
};

