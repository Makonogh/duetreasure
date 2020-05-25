#pragma once


enum class INPUT_ID
{
	LEFT1,
	RIGHT1,
	UP1,
	DOWN1,
	LEFT2,
	RIGHT2,
	UP2,
	DOWN2,
	BTN_1,
	BTN_2,
	BTN_3,
	BTN_4,
	START,
	SELECT,
	MAX
};


INPUT_ID begin(INPUT_ID);
INPUT_ID end(INPUT_ID);
INPUT_ID operator*(INPUT_ID key);
INPUT_ID operator++(INPUT_ID& key);
