/*
 * Anim_Base.h
 *
 *  Created on: 7 août 2019
 *      Author: fabien
 */

#ifndef SRC_ANIM_BASE_H_
#define SRC_ANIM_BASE_H_

#include <sstream>

class SpriteSheet;

using Frame = unsigned int;

class Anim_Base
{

	friend class SpriteSheet;

public:

	Anim_Base();
	virtual ~Anim_Base();

	void setLooping(const bool& l_loop);
	void setSpriteSheet(SpriteSheet* l_sheet);
	void setFrame(const unsigned int& l_frame);
	void setName(const std::string& l_name);

	bool isInAction();

	void play();
	void pause();
	void stop();
	void reset();

	virtual void update(const float& l_dT);

	friend std::stringstream& operator >>(std::stringstream& l_stream, Anim_Base& a)
	{
		a.readIn(l_stream);
		return l_stream;
	}

protected:

	virtual void frameStep() = 0;
	virtual void cropSprite() = 0;
	virtual void readIn(std::stringstream& l_stream) = 0;

	Frame m_frameCurrent;
	Frame m_frameStart;
	Frame m_frameEnd;
	Frame m_frameRow;
	int m_frameActionStart;
	int m_frameActionEnd;
	float m_frameTime;
	float m_elapsedTime;
	bool m_loop;
	bool m_playing;
	std::string m_name;
	SpriteSheet* m_spriteSheet;

};

#endif /* SRC_ANIM_BASE_H_ */