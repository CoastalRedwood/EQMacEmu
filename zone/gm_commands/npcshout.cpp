#include "../client.h"

void command_npcshout(Client *c, const Seperator *sep){
	if (c->GetTarget() && c->GetTarget()->IsNPC() && sep->arg[1][0])
	{
		c->GetTarget()->Shout(sep->argplus[1]);
	}
	else
	{
		c->Message(Chat::Default, "Usage: #npcshout message (requires NPC target");
	}
}

