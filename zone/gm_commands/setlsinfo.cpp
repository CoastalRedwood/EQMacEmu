#include "../client.h"
#include "../worldserver.h"
extern WorldServer worldserver;

void command_setlsinfo(Client* c, const Seperator* sep) {
	int arguments = sep->argnum;
	if (arguments < 2) {
		c->Message(Chat::Default, "Usage: #setlsinfo [Email] [Password]");
		return;
	}

	auto pack = new ServerPacket(ServerOP_LSAccountUpdate, sizeof(ServerLSAccountUpdate_Struct));
	auto s = (ServerLSAccountUpdate_Struct*)pack->pBuffer;
	s->useraccountid = c->LSAccountID();
	strn0cpy(s->useraccount, c->AccountName(), 16);
	strn0cpy(s->useremail, sep->arg[1], 100);
	strn0cpy(s->userpassword, sep->arg[2], 16);
	worldserver.SendPacket(pack);
	safe_delete(pack);
	c->Message(Chat::Default, "Your email and local loginserver password have been set.");
}

