/**
 * GetUdid - Utility to get the UDID of the connected iDevice.
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

#include <string.h>
#include <CoreFoundation/CoreFoundation.h>

// Start - A part of MobileDevice.h
#define ADNCI_MSG_CONNECTED     1
struct am_device_notification_callback_info {
    struct am_device *dev;
}
__attribute__ ((packed)) am_device_notification_callback_info;
__attribute__ ((packed)) am_device;
    CFStringRef AMDeviceCopyDeviceIdentifier(struct am_device *device);
// End

struct am_device_notification *notify;
struct am_device *device;
void sendata(*device)
{
    CFStringEncoding encoding = CFStringGetSystemEncoding();
	const char *udid = CFStringGetCStringPtr(AMDeviceCopyDeviceIdentifier(device), encoding);
    printf("UDID: %s\n", udid);
    exit(EXIT_SUCCESS);
}

void getdata(struct am_device_notification_callback_info *info)
{
    sendata(info->dev);
}	 

void main()
{
	AMDeviceNotificationSubscribe(&getdata, NULL, NULL, NULL, &notify);
	CFRunLoopRun();
}
