// and another one! this one also does stuff with X11.

#include <X11/Xlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

main(void) {
          Display *d;
          Window w;
          XEvent e;
          const char *msg = "Verdammt noch mal";
          int s;

          d = XOpenDisplay(NULL);
          if (d == NULL) {
                  fprintf(stderr, "Cannot open display\n");
                  exit(1);
          }

          s = DefaultScreen(d);
          w = XCreateSimpleWindow(d, RootWindow(d,s), 10, 10, 100, 100, 1,
                          BlackPixel(d,s), WhitePixel(d,s));
          XSelectInput(d,w, ExposureMask | KeyPressMask);
          XMapWindow(d, w);
          XStoreName(d, w, "XCoffee");

          while (1)
          {
                  XNextEvent(d, &e);
                  if (e.type == Expose)
                  {
                          XFillRectangle(d, w, DefaultGC(d,s), 20, 20, 10, 10);
                          XDrawString(d, w, DefaultGC(d, s), 10, 50, msg, strlen(msg));
                  }
                  if (e.type == KeyPress)
                          break;
          }
          XCloseDisplay(d);
          return 0;
  }
