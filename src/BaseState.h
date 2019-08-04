/*
 * BaseState.h
 *
 *  Created on: 29 juil. 2019
 *      Author: fabien
 */

#ifndef SRC_BASESTATE_H_
#define SRC_BASESTATE_H_

#include <SFML/System.hpp>

class StateManager;

class BaseState
{

	friend class StateManager;

public:

	BaseState(StateManager* l_stateManager)
		: m_stateMgr(l_stateManager), m_transparent(false), m_transcendent(false)
	{}

	virtual ~BaseState() {}

	virtual void onCreate() = 0;
	virtual void onDestroy() = 0;

	virtual void activate() = 0;
	virtual void deactivate() = 0;

	virtual void update(const sf::Time& l_time) = 0;
	virtual void draw() = 0;

	void setTransparent(const bool& l_transparent) { m_transparent = l_transparent;}
	void setTranscendent(const bool& l_transcendent) { m_transcendent = l_transcendent; }

	bool isTransparent() const { return m_transparent; }
	bool isTranscendent() const { return m_transcendent; }
	StateManager* getStateManager() { return m_stateMgr; }

protected:

	StateManager* m_stateMgr;
	bool m_transparent;
	bool m_transcendent;

};

#endif /* SRC_BASESTATE_H_ */
