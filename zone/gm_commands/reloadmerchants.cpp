#include "../client.h"

void command_reloadmerchants(Client *c, const Seperator *sep)
{
	zone->ClearMerchantLists();
	zone->GetMerchantDataForZoneLoad();
	zone->LoadTempMerchantData();
	c->Message(Chat::Default, "Merchant list reloaded for %s.", zone->GetShortName());
}

