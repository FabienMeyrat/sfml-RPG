/*
 * SharedContext.h
 *
 *  Created on: 29 juil. 2019
 *      Author: fabien
 */

#ifndef SRC_SHAREDCONTEXT_H_
#define SRC_SHAREDCONTEXT_H_

#include "Window.h"
#include "EventManager.h"

struct SharedContext
{
	SharedContext() : m_wind(nullptr), m_eventManager(nullptr) {}
	Window* m_wind;
	EventManager* m_eventManager;
};

#endif /* SRC_SHAREDCONTEXT_H_ */
