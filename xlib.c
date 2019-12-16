// look at that, i finally wrote C again! 

#include <stdio.h>
#include <stdlib.h>
#include <X11/Xlib.h>
#include <X11/Xos.h>
#include <X11/Xutil.h>


main( int argc, char * argv[])
  {
          Display* dpy;
          int screen;
          Window win;
          XEvent event;
          char *window_name;

          dpy = XOpenDisplay(NULL);

          if(dpy == NULL)
          {
                  fprintf(stderr, "Cannot open display\n");
                  exit(1);
          }
          screen = DefaultScreen(dpy);

          win = XCreateSimpleWindow(dpy, RootWindow(dpy, screen),
                          200, 200, 500, 300,
                          1, BlackPixel(dpy, screen), WhitePixel(dpy, screen));

          XSelectInput(dpy, win, ExposureMask | KeyPressMask);
          XStoreName(dpy, win, "XCoffee");

          XMapWindow(dpy, win);
          while(1)
          {
                  XNextEvent(dpy, &event);
          }

          return 0;

  }
