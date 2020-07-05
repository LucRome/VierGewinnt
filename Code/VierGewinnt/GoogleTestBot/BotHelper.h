#pragma once

class Spielfeld;

class BotHelper
{
public:
	BotHelper();
	~BotHelper();
	Spielfeld setSpielfeld();
	int spalteHorizontal();
};