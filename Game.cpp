#include "Game.h"


int Game::GetScore() {
	return _Score/10;
}

void Game::New() {
	_End = false;
	_Score = 0;
	_Person = Person(Coord(200, 100), _Texture);

	random_device rd;
	mt19937 gen(rd());
	
	_Platform[0] = new PlatformBasic(Coord(200, 20), _Texture);
	for (int i = 1; i<N; i++) {
		
		uniform_int_distribution<> dis(_Platform[i - 1]->GetPosition().y + 30 , _Platform[i - 1]->GetPosition().y + 65);
		int __y = dis(gen);
		_Platform[i] = _PA.New(Coord(_PA.GetX(), __y), _Texture);
		
	}

}

void Game::End() {
	
	//delete _Person;
}

void Game::MoveRight() {
	_Person.MovePositionX(7);
	_Person.LookRight();
	if (_Person.GetPosition().x > 400) {
		_Person.SetPositionX(0);
	};
}

void Game::MoveLeft() {
	_Person.MovePositionX(-7);
	_Person.LookLeft();
	if (_Person.GetPosition().x < 0) {
		_Person.SetPositionX(400);
	};
}

float dy = 0;
int i;

bool Game::Calculate() {
	
	if (!_End) {

		dy += 0.2;
		_Person.SetPositionY(_Person.GetPosition().y - dy);

		if (_Person.GetPosition().y > 250) {
			int randX;
			for (i = 0; i < N; i++) {

				_Person.SetPositionY(250);
				_Platform[i]->MovePositionY(dy);
				_Score += -dy;
				if (_Platform[i]->GetPosition().y < 0) {
					bool a = true;

					do {
						randX = _PA.GetX();
						a = false;
						for (int j = 0; j < N; j++) {
							if (randX < _Platform[j]->GetPosition().x + 50 && randX > _Platform[j]->GetPosition().x - 50
								&& 600 < _Platform[j]->GetPosition().y + 20 && 600 > _Platform[j]->GetPosition().y - 20) {
								//cout << "ren" << endl;
								a = true;

							}
						}

					} while (a);
					_Platform[i] = _PA.New(Coord(randX, 600), _Texture);

				}

			}
		}


		for (i = 0; i < N; i++) {
			if (_Platform[i]->InPlatform(_Person) && (dy > 0)) { // подкидывание если на платформе
				dy = -_Platform[i]->GetBumpDistance((int)dy);
			}
			if (_Person.GetPosition().y < 0) { // or proebal
				_End = true;
				return false;
			}
		}
		return true;

	}
	else {
		return false;
	}

}

void Game::Render() {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	if (!_End) {
		for (size_t i = 0; i < N; i++) {
			_Platform[i]->Draw();
		}
		_Person.Draw();

		glColor3f(0.89f, 0.85f, 0.78f);
		glBegin(GL_QUADS);
		glVertex2d(0, 600);
		glVertex2d(400, 600);
		glVertex2d(400, 570);
		glVertex2d(0, 570);
		glEnd();

		char score[20];
		glColor3f(0.0f, 0.0f, 0.0f);
		glRasterPos2f(9, 580);
		sprintf(score, "score: %d", _Score / 10);
		for (int j = 0; j < strlen(score); j++) {
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, score[j]);
		}
	}
	
}

Game::Game(GLuint texture){
	_Texture = texture;
}

Game::Game(){
}

Game::~Game()
{
}
