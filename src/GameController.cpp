#include <GameController.h>
const int BUTTON_SIZE = 70;

GameController::GameController() :m_objects()
{

	m_objects[0] = new King(BUTTON_SIZE * 0, 0, m_imagesPath[0]);
	m_objects[1] = new Mage(BUTTON_SIZE * 1, 0, m_imagesPath[1]);
	m_objects[2] = new Warrior(BUTTON_SIZE * 2, 0, m_imagesPath[2]);
	m_objects[3] = new Thief(BUTTON_SIZE * 3, 0, m_imagesPath[3]);
	m_objects[4] = new Obstacle(BUTTON_SIZE * 4, 0, m_imagesPath[4]);
	m_objects[5] = new Obstacle(BUTTON_SIZE * 5, 0, m_imagesPath[5]);
	m_objects[6] = new Obstacle(BUTTON_SIZE * 6, 0, m_imagesPath[6]);
	m_objects[7] = new Obstacle(BUTTON_SIZE * 7, 0, m_imagesPath[7]);
	m_objects[8] = new Obstacle(BUTTON_SIZE * 8, 0, m_imagesPath[8]);
	m_objects[9] = new Obstacle(BUTTON_SIZE * 9, 0, m_imagesPath[9]);
	m_objects[10] = new Obstacle(BUTTON_SIZE * 10, 0, m_imagesPath[10]);

}

DisplayObject*& GameController::getObject(int index) {

	return m_objects[index];
}