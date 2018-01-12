#pragma once
#include "stdafx.h"
#undef DrawText

class Renderer
{
public:
	void Initialize();

	void BeginScene();
	void DrawScene();
	void EndScene();

	static Renderer* GetInstance();

private:
	Renderer();
	~Renderer();

	float DrawText(ImFont* pFont, const std::string& text, const ImVec2& position, float size, uint32_t color, bool center);
	void DrawLine(const ImVec2& from, const ImVec2& to, uint32_t color, float thickness = 1.0f);
	void DrawCircle(const ImVec2& position, float radius, uint32_t color, float thickness = 1.0f);
	void DrawCircleFilled(const ImVec2& position, float radius, uint32_t color);
	void DrawBox(const ImVec2& position, const ImVec2& headPosition, uint32_t color);

	ImFont* m_pFont;

	static Renderer* m_pInstance;
};