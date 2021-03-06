/*
Copyright (C) 2014 CU Galaxies
*/

#ifndef STABILIZERSCOMMAND_H_
#define STABILIZERSCOMMAND_H_

#include "server/zone/objects/scene/SceneObject.h"

class StabilizersCommand : public QueueCommand {
public:

	StabilizersCommand(const String& name, ZoneProcessServer* server)
		: QueueCommand(name, server) {

	}

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {

		if (!checkStateMask(creature))
			return INVALIDSTATE;

		if (!checkInvalidLocomotions(creature))
			return INVALIDLOCOMOTION;

		return SUCCESS;
	}

};

#endif //STABILIZERSCOMMAND_H_
