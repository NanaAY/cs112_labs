/* manageUserAccounts.cpp contains the "driver" for class AccountManager.
 * Joel Adams, for CS 112 at Calvin College.
* Name: Nana Osei Asiedu Yirenkyi
 */
#include "AccountManager.h"

int main() {
	AccountManager manager("accountInfo.txt");
	manager.run();
}
