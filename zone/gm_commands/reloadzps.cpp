#include "../client.h"

void command_reloadzps(Client *c, const Seperator *sep){
	database.LoadStaticZonePoints(&zone->zone_point_list, zone->GetShortName());
	c->Message(Chat::Default, "Reloading server zone_points.");
}

