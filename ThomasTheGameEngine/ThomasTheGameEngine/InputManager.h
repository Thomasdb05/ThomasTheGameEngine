#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

#include<vector>
#include<iostream>
#include "GLFW/glfw3.h"


namespace Input {

	enum KeyState {
		unheld,
		held,
		release,
		pressed
	};

	void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

	extern KeyState A;
	extern KeyState B;
	extern KeyState C;
	extern KeyState D;
	extern KeyState E;
	extern KeyState F;
	extern KeyState G;
	extern KeyState H;
	extern KeyState I;
	extern KeyState J;
	extern KeyState K;
	extern KeyState L;
	extern KeyState M;
	extern KeyState N;
	extern KeyState O;
	extern KeyState P;
	extern KeyState Q;
	extern KeyState R;
	extern KeyState S;
	extern KeyState T;
	extern KeyState U;
	extern KeyState V;
	extern KeyState W;
	extern KeyState X;
	extern KeyState Y;
	extern KeyState Z;

	extern std::vector<KeyState*> keys;

	void updateKeys();

	void initKeys(GLFWwindow* wind);

}

#endif