#include "../client.h"

void command_fov(Client *c, const Seperator *sep){
	if (c->GetTarget())
		if (c->BehindMob(c->GetTarget(), c->GetX(), c->GetY()))
			c->Message(Chat::Default, "You are behind mob %s, it is looking to %d", c->GetTarget()->GetName(), c->GetTarget()->GetHeading());
		else
			c->Message(Chat::Default, "You are NOT behind mob %s, it is looking to %d", c->GetTarget()->GetName(), c->GetTarget()->GetHeading());
	else
		c->Message(Chat::Default, "I Need a target!");
}

