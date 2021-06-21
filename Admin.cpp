#include "Admin.h"
void Admin::AdminGenerateData(Admin* admin_ptr)
{
	for (auto i = 0; i < 10; i++)
	{
		admin_ptr[i].name = "Admin" + to_string(i + 1);
		admin_ptr[i].username = "AdminUsername" + to_string(i + 1);
		admin_ptr[i].password = "AdminPassword" + to_string(i + 1);
	}
}
bool Admin::AdminVerification(Admin* admin_ptr, string Username, string Password)
{
	bool found(0);
	for (auto i = 0; i < 10; i++)
	{
		if (admin_ptr[i].username == Username)
		{
			if (admin_ptr[i].password == Password)
			{
				found = 1;
				break;
			}
		}
	}
	return found;
}