char logout_user() {
	extern int iLoginChange;
	extern char sUser[26];
	sUser[26] = "                          ";
	iLoginChange = 0;
}