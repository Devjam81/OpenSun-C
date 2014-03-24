/**
 * OpeniSend_rec - Utility for send command to Recovery Mode.
 * Copyright (C) 2014  Louis Kremer
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 **/

//
// The information are from http://theiphonewiki.com/wiki/Recovery_Mode_(Protocols)#Recovery_Mode_4.x_.28DevID.3D0x1283.29
// Include code from http://github.com/cal0x/openiapp .
//

#include <stdlib.h>
#include <stdio.h>
#include <libusb-1.0/libusb.h>
#include <usb.h> // I don't need it because I had problems with usb_device_handle(); and usb_control_msg();

int cmd();
struct libusb_device_handle *handle;

void help(void){
    printf("[*] ./OpeniSend_rec -h or --help or -help (Help)\n");
    printf("[*] ./OpeniSend_rec -a (fix recovery loop)\n");
    printf("[*] ./OpeniSend_rec <command>\n");
}

int main(int argc, char *argv[]) {
    libusb_init(NULL);
    handle = libusb_open_device_with_vid_pid(NULL, 0x05AC, 0x1281);
    if(argc == 2 && strcmp(argv[1], "--help")==0)
    {
        help();
        return -1;
    }
    else if(argc == 2 && strcmp(argv[1], "-help")==0){
        help();
        return -1;
    }
    else if(argc == 2 && strcmp(argv[1], "-h")==0){
        help();
        return -1;
    }
    else if(argc == 2 && strcmp(argv[1], "-a")==0){
        char *setenv = "setenv auto-boot true";
        char *saveenv = "saveenv";
        char *reboot = "reboot";
        cmd(&setenv);
        cmd(&saveenv);
        cmd(&reboot);
        exit(0);
    }
    else if(argc == 1){
        help();
        return -1;
    }
    else {
        char *command = argv[1];
        cmd(&command);
        exit(0);
    }
}

int cmd(char* command[]) {
	if (libusb_control_transfer(handle, 0x40, 0, 0, 0, command[0], (strlen(command[0]) + 1), 1000)) {
		printf("[*] Successfully sent command.\r\n");
		return -1;
	} else {
		printf("[*] Error with sending the Command");
    }
	return 1;
}
