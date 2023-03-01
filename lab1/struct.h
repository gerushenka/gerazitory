#pragma once

typedef struct {
	char* title;
	int year;
	enum Type type;
} anim;

enum Type {
	SERIAL = 0,
	FILM = 1,
	OVA = 2,
	ONA = 3,
	SPECIAL = 4
};

