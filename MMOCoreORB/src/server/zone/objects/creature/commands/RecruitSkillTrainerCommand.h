/*
Copyright (C) 2007 <SWGEmu>

This File is part of Core3.

This program is free software; you can redistribute
it and/or modify it under the terms of the GNU Lesser
General Public License as published by the Free Software
Foundation; either version 2 of the License,
or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
See the GNU Lesser General Public License for
more details.

You should have received a copy of the GNU Lesser General
Public License along with this program; if not, write to
the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA

Linking Engine3 statically or dynamically with other modules
is making a combined work based on Engine3.
Thus, the terms and conditions of the GNU Lesser General Public License
cover the whole combination.

In addition, as a special exception, the copyright holders of Engine3
give you permission to combine Engine3 program with free software
programs or libraries that are released under the GNU LGPL and with
code included in the standard release of Core3 under the GNU LGPL
license (or modified versions of such code, with unchanged license).
You may copy and distribute such a system following the terms of the
GNU LGPL for Engine3 and the licenses of the other code concerned,
provided that you include the source code of that other code when
and as the GNU LGPL requires distribution of source code.

Note that people who make modified versions of Engine3 are not obligated
to grant this special exception for their modified versions;
it is their choice whether to do so. The GNU Lesser General Public License
gives permission to release a modified version without this exception;
this exception also makes it possible to release a modified version
which carries forward this exception.
*/

#ifndef RECRUITSKILLTRAINERCOMMAND_H_
#define RECRUITSKILLTRAINERCOMMAND_H_

#include "server/zone/objects/scene/SceneObject.h"
#include "server/zone/objects/player/sui/listbox/SuiListBox.h"
#include "server/zone/objects/creature/commands/sui/RecruitSkillTrainerSuiCallback.h"

class RecruitSkillTrainerCommand : public QueueCommand {
public:

	RecruitSkillTrainerCommand(const String& name, ZoneProcessServer* server)
		: QueueCommand(name, server) {

	}

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {

		if (!checkStateMask(creature))
			return INVALIDSTATE;

		if (!checkInvalidLocomotions(creature))
			return INVALIDLOCOMOTION;

		if (!creature->hasSkill("social_politician_civic_02"))
			return GENERALERROR;

		ManagedReference<CityRegion*> city = creature->getCityRegion();

		if (city == NULL)
			return GENERALERROR;

		if (!city->isMayor(creature->getObjectID()))
			return GENERALERROR;

		ManagedReference<SuiListBox*> suiTrainerType = new SuiListBox(creature, SuiWindowType::RECRUIT_SKILL_TRAINER, 0);
		suiTrainerType->setCallback(new RecruitSkillTrainerSuiCallback(server->getZoneServer()));

		suiTrainerType->setPromptTitle("@city/city:trainer_n");
		suiTrainerType->setPromptText("@city/city:trainer_d");

		suiTrainerType->addMenuItem("@city/city:st_architect", 0);
		suiTrainerType->addMenuItem("@city/city:st_armorsmith", 1);
		suiTrainerType->addMenuItem("@city/city:st_artisan", 2);
		suiTrainerType->addMenuItem("@city/city:st_bioengineer", 3);
		suiTrainerType->addMenuItem("@city/city:st_bountyhunter", 4);
		suiTrainerType->addMenuItem("@city/city:st_brawler", 5);
		suiTrainerType->addMenuItem("@city/city:st_carbine", 6);
		suiTrainerType->addMenuItem("@city/city:st_chef", 7);
		suiTrainerType->addMenuItem("@city/city:st_combatmedic", 8);
		suiTrainerType->addMenuItem("@city/city:st_commando", 9);
		suiTrainerType->addMenuItem("@city/city:st_creaturehandler", 10);
		suiTrainerType->addMenuItem("@city/city:st_dancer", 11);
		suiTrainerType->addMenuItem("@city/city:st_doctor", 12);
		suiTrainerType->addMenuItem("@city/city:st_droidengineer", 13);
		suiTrainerType->addMenuItem("@city/city:st_entertainer", 14);
		suiTrainerType->addMenuItem("@city/city:st_1hsword", 15);
		suiTrainerType->addMenuItem("@city/city:st_imagedesigner", 16);
		suiTrainerType->addMenuItem("@city/city:st_marksman", 17);
		suiTrainerType->addMenuItem("@city/city:st_medic", 18);
		suiTrainerType->addMenuItem("@city/city:st_merchant", 19);
		suiTrainerType->addMenuItem("@city/city:st_musician", 20);
		suiTrainerType->addMenuItem("@city/city:st_pistol", 21);
		suiTrainerType->addMenuItem("@city/city:st_polearm", 22);
		suiTrainerType->addMenuItem("@city/city:st_politician", 23);
		suiTrainerType->addMenuItem("@city/city:st_ranger", 24);
		suiTrainerType->addMenuItem("@city/city:st_rifleman", 25);
		suiTrainerType->addMenuItem("@city/city:st_scout", 26);
		suiTrainerType->addMenuItem("@city/city:st_smuggler", 27);
		suiTrainerType->addMenuItem("@city/city:st_squadleader", 28);
		suiTrainerType->addMenuItem("@city/city:st_2hsword", 29);
		suiTrainerType->addMenuItem("@city/city:st_tailor", 30);
		suiTrainerType->addMenuItem("@city/city:st_unarmed", 31);
		suiTrainerType->addMenuItem("@city/city:st_weaponsmith", 32);



		creature->getPlayerObject()->addSuiBox(suiTrainerType);
		creature->sendMessage(suiTrainerType->generateMessage());

		return SUCCESS;
	}

};

#endif //RECRUITSKILLTRAINERCOMMAND_H_
