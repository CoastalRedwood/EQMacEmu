#include "../client.h"
#include "../string_ids.h"

void command_hideme(Client *c, const Seperator *sep){
	bool state = atobool(sep->arg[1]);

	if (sep->arg[1][0] == 0)
		c->Message(Chat::Default, "Usage: #hideme [on/off]");
	else
	{
		c->SetHideMe(state);
		c->Message_StringID(Chat::Broadcasts, c->GetHideMe() ? NOW_INVISIBLE : NOW_VISIBLE, c->GetName());
	}
}

