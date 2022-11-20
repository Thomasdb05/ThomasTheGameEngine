#include "InputManager.h"

namespace Input {

	KeyState A;
	KeyState B;
	KeyState C;
	KeyState D;
	KeyState E;
	KeyState F;
	KeyState G;
	KeyState H;
	KeyState I;
	KeyState J;
	KeyState K;
	KeyState L;
	KeyState M;
	KeyState N;
	KeyState O;
	KeyState P;
	KeyState Q;
	KeyState R;
	KeyState S;
	KeyState T;
	KeyState U;
	KeyState V;
	KeyState W;
	KeyState X;
	KeyState Y;
	KeyState Z;

	std::vector<KeyState*> keys;

	void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
		int keyIndex = key - 65; //GLFW_KEY letters start at 65
		if (action == GLFW_PRESS) {
			*keys[keyIndex] = KeyState::pressed;
			return;
		}
		else if (action == GLFW_RELEASE) {
			*keys[keyIndex] = KeyState::release;
		}
	}

	//call this function BEFORE getting input (before polling for events)
	void updateKeys() {
		for (int i = 0; i < keys.size(); i++) {
			if (*keys[i] == KeyState::release) {
				*keys[i] = KeyState::unheld;
			}
			else if (*keys[i] == KeyState::pressed) {
				*keys[i] = KeyState::held;
			}
		}
	}

	void initKeys(GLFWwindow* wind) {

		keys.reserve(26);
		keys.push_back(&A);
		keys.push_back(&B);
		keys.push_back(&C);
		keys.push_back(&D);
		keys.push_back(&E);
		keys.push_back(&F);
		keys.push_back(&G);
		keys.push_back(&H);
		keys.push_back(&I);
		keys.push_back(&J);
		keys.push_back(&K);
		keys.push_back(&L);
		keys.push_back(&M);
		keys.push_back(&N);
		keys.push_back(&O);
		keys.push_back(&P);
		keys.push_back(&Q);
		keys.push_back(&R);
		keys.push_back(&S);
		keys.push_back(&T);
		keys.push_back(&U);
		keys.push_back(&V);
		keys.push_back(&W);
		keys.push_back(&X);
		keys.push_back(&Y);
		keys.push_back(&Z);

		glfwSetKeyCallback(wind, keyCallback);
	}
}