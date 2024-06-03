#include <linux/uinput.h> // Virtual mouse/keyboard input. For windows we will use VJoy/
#include <libevdev-1.0/libevdev/libevdev.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main (int * argc, char** argv) 
{
    struct libevdev * dev= NULL; // Making a virtual controller object.
    int* err =  NULL;
    err = new int();
    int rc = 1;
    // Declare a file descriptor, or a file containing all of the information of the new device.
    int fd = open("../../../../dev/input/by-id/usb-VMware_VMware_Virtual_USB_Mouse-mouse" , O_RDONLY | O_NONBLOCK); 
    if (fd < 0 ) 
    {
        perror("libevdev_set_fd");
        return -1;
    }
    rc = libevdev_new_from_fd(fd, &dev);
    if (rc < 0) 
    {
        perror("libevdev_new_from_fd");
        return -1; 
    }
    printf("Input device name: %s\n", libevdev_get_name(dev));
    printf("Input device ID: bus %#x vendor %#x product %#x\n",
           libevdev_get_id_bustype(dev),
           libevdev_get_id_vendor(dev),
           libevdev_get_id_product(dev));
    delete err; 
}