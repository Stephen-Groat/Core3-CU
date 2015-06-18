/*
Copyright (C) 2014 CU Galaxies
*/

#ifndef BANDAGECOMMAND_H_
#define BANDAGECOMMAND_H_

#include "server/zone/objects/scene/SceneObject.h"

class BandageCommand : public QueueCommand {
public:

	BandageCommand(const String& name, ZoneProcessServer* server)
		: QueueCommand(name, server) {

	}

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) {

		if (!checkStateMask(creature))
			return INVALIDSTATE;

		if (!checkInvalidLocomotions(creature))
			return INVALIDLOCOMOTION;

		return SUCCESS;
	}

};

#endif //BANDAGECOMMAND_H_