#pragma once
#include "Singleton.h"

class Framework :
    public Singleton<Framework>
{
	friend Singleton<Framework>;

protected:
	Framework() = default;
	virtual ~Framework() = default;

	Framework(const Framework& other) = delete;
	Framework& operator=(const Framework& other) = delete;

	sf::RenderWindow m_MainWindow;

	sf::Clock clock;
	float m_TimeScale = 1.f;

	float m_Time = 0.f;
	float m_DeltaTime = 0.f;
	float m_RealTime = 0.f;
	float m_RealDeltaTime = 0.f;

public:
	float GetTime() const { return m_Time; }
	float GetDeltaTime() const { return m_DeltaTime; }
	float GetRealTime() const { return m_RealTime; }
	float GetRealDeltaTime() const { return m_RealDeltaTime; }

	void SetTimeScale(float newTimeScale) { m_TimeScale = newTimeScale; }
	float GetTimeScale() const { return m_TimeScale; }

	virtual void Initialize(int width, int height, const std::string& name);
	virtual void Do();
	virtual void Release();
};

#define FM (Framework::GetInstance())
#define GM (GameManager::GetInstance())
#define IM (InputManager::GetInstance())
#define SM (SceneManager::GetInstance())
