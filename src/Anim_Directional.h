/*
 * Anim_Directional.h
 *
 *  Created on: 7 août 2019
 *      Author: fabien
 */

#ifndef SRC_ANIM_DIRECTIONAL_H_
#define SRC_ANIM_DIRECTIONAL_H_

#include "Anim_Base.h"

class Anim_Directional: public Anim_Base
{

protected:

	void frameStep();
	void cropSprite();
	void readIn(std::stringstream& l_stream);

};

#endif /* SRC_ANIM_DIRECTIONAL_H_ */
