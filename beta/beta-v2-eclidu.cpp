// Beginning of code

/*
 *   Welcome to ECLIDU! -- Easy Command Line Interface Disk Utility
 *   This program is used for listing mounted drives, formatting drives, writing files to drives to make a live USB,
 *   and mounting drives. ECLIDU takes all of these commands and puts them into one program. What makes ECLIDU
 *   different from other disk management programs is it is easier to use and it can write .iso and .img files to a flashdrive.
 *   This is an all-in-one disk utility for Linux amatuers and experts alike, and for those that like using the
 *   command line but don't want to have a hard time doing so.
 *
 *   Copyright (C) 2016  Austin Tyler Wade Malone
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 *   Email: malone.austin.t@gmail.com
 *
 */

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

void aboutcout() {
	cout << "\nWelcome to ECLIDU! -- Easy Command Line Interface Disk Utility\n\n"
		"This program is used for listing mounted drives, formatting drives,\nwriting files to drives to make a live USB,\n"
		"and mounting drives. ECLIDU takes all of these commands and puts them\ninto one program. What makes ECLIDU"
		"different from other disk\nmanagement programs is it is easier to use and it can write .iso and\n.img files to a flashdrive."
		"This is an all-in-one disk utility\nfor Linux amatuers and experts alike, and for those that like using the\n"
		"command line but don't want to have a hard time doing so.\n\n"
		"ECLIDU -- Easy Command Line Interface Disk Utility:\nCopyright (C) 2016  Austin Tyler Wade Malone\n"
		"This program is free software: you can redistribute\nit and/or modify it under the terms of the\n"
		"GNU General Public License as published by the\nFree Software Foundation, either version 3 of \n"
		"the License, or (at your option) any later version.\nThis program is distributed in the hope that it will be useful, \n"
		"but WITHOUT ANY WARRANTY; without even the\nimplied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  \n"
		"See the GNU General Public License for more details.\nYou should have received a copy of the GNU General Public License \n"
		"along with this program.  If not, see <http://www.gnu.org/licenses/>.\nDev Email: <malone.austin.t@gmail.com>" << endl;
}

// add more filesystems maybe?
void fsmenu() {
	cout << "\n1 (vfat - Popular for flashdrives)\n2 (ext4 - Popular for Linux partitions)\n"
		"3 (ext3)\n4 (ext2)\n~> ";
}

void fsswitch() {
	int fsAns;
	string fsAnsDrive;

	cin >> fsAns;

	cout << "Please select the device you wish to format. (e.g. /dev/sdb): ";

	cin >> fsAnsDrive;

	switch (fsAns) {
		case 1:
			system (("sudo mkfs.vfat -I " + fsAnsDrive).c_str());
			break;
		case 2:
			system (("sudo mkfs.ext4 -I " + fsAnsDrive).c_str());
			break;
		case 3:
			system (("sudo mkfs.ext3 -I " + fsAnsDrive).c_str());
			break;
		case 4:
			system (("sudo mkfs.ext2 -I " + fsAnsDrive).c_str());
			break;
		default:
			cout << "\nYou entered an invalid command. Please try again." << endl;
	}
}

void menu() {
	cout << "\n\e[1mECLIDU Menu:\e[0m";
	cout << "\nl (List mounted storage devices and partitions with fdisk)\n"
		"u (Unmount storage device and/or partition)\nm (Mount storage device and/or partition)\n"
		"f (Format storage device and/or partition)\n"
		"w (Write a file to a storage device)\nx (Exit program)\na (About ECLIDU)\n"
		"b (Report bugs)\n"
		"(Note: You can hit CTRL+C at any time to end an operation)\n~> ";
}

void list() {
	system ("sudo fdisk -l");
}

void unmount() {
	string ansUmount;
	system ("sudo fdisk -l");
	cout << "Please select the device you want to unmount. (e.g. /dev/sdb):" << endl;
	cin >> ansUmount;
	system (("sudo umount -f " + ansUmount).c_str());
  cout << ansUmount << endl;
}

void mount() {
	string ansMount;
	cout << "Please select the drive you want to mount. (e.g. /dev/sdb): ";
	cin >> ansMount;
	system (("sudo mount " + ansMount).c_str());
}

void filesystem() {
	cout << "Please select the type of filesystem: ";
	fsmenu();
	fsswitch();
}

void write() {
	string ansWrite, ansDrive;
	cout << "Please enter the path to the file. (e.g. /home/user/Downloads/file.iso): ";
	cin >> ansWrite;
	cout << "Please enter the drive to write to. (e.g. /dev/sdb): ";
	cin >> ansDrive;
	system (("sudo chmod 777 " + ansDrive).c_str());
	system (("sudo dd if=" + ansWrite + " of=" + ansDrive).c_str());
}

void clear() {
	system("clear");
	cout << "\n\e[1mECLIDU: Working...\e[0m\n";
}

int main();

void menuselect() {
	string ans;
	getline (cin,ans);

	switch (ans[0]) {
		case 'b':
			clear();
			cout << "\nPlease submit any bugs here:" << endl;
			// NEED bug section!!!!
			break;
		case 'l':
		case 'L':
			clear();
			cout << endl;
			list();
			break;
		case 'u':
		case 'U':
			clear();
			cout << endl;
			unmount();
			break;
		case 'm':
		case 'M':
			clear();
			mount();
			break;
		case 'f':
		case 'F':
			clear();
			filesystem();
			break;
		case 'w':
		case 'W':
			clear();
			write();
			break;
		case 'a':
		case 'A':
			clear();
			aboutcout();
			break;
		case 'x':
		case 'X':
			system ("clear");
			cout << "\nGoodbye! - ECLIDU\n" << endl;
			exit (EXIT_SUCCESS);
		default:
      cout << endl;
			system ("clear");
			//cout << "\nYou entered an invalid command. Please try again." << endl;
	}
  main();
}

int main() {
	menu();
	menuselect();

  return 0;
}

// End of code
