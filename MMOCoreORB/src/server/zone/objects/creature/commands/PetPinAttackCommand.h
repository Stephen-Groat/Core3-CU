/*
Copyright (C) 2014 CU Galaxies
*/

#ifndef PETPINATTACKCOMMAND_H_
#define PETPINATTACKCOMMAND_H_

#include "server/zone/objects/scene/SceneObject.h"

class PetPinAttackCommand : public QueueCommand {
public:

	PetPinAttackCommand(const String& name, ZoneProcessServer* server)
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

#endif //PETPINATTACKCOMMAND_H_
