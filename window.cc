//#include <X11/Xutil.h>
#include <iostream>
#include <cstdlib>
#include <string>
#include <unistd.h>
#include "window.h"

using namespace std;

Xwindow::Xwindow(int width, int height) {
  d = XOpenDisplay(nullptr);
  if (d == nullptr) {
    std::cerr << "Cannot open display" << std::endl;
    exit(1);
  }

  s = DefaultScreen(d);
  w = XCreateSimpleWindow(d, RootWindow(d, s), 10, 10, width, height, 1, BlackPixel(d, s), WhitePixel(d, s));
  XSelectInput(d, w, ExposureMask | KeyPressMask);
  XMapWindow(d, w);

  // Set up colours.
  Colormap cm = DefaultColormap(d, s);
  XColor xc;
  char color_strings[5][10] = {"white", "black", "red", "green", "blue"};

  for (int i = 0; i < 5; ++i) {
    XParseColor(d, cm, color_strings[i], &xc);
    XAllocColor(d, cm, &xc);
    colours[i] = xc.pixel;
  }

  gc = create_gc(d, w, 0);
  XSetForeground(d, gc, BlackPixel(d, s));
}

Xwindow::~Xwindow() {
  XFreeGC(d, gc);
  XDestroyWindow(d, w);
  XCloseDisplay(d);
}

void Xwindow::fillRectangle(int x, int y, int width, int height, int colour) {
  XSetForeground(d, gc, colours[colour]);
  XFillRectangle(d, w, gc, x, y, width, height);
  XSetForeground(d, gc, colours[Black]);
}

void Xwindow::drawString(int x, int y, std::string msg, int colour) {
  XSetForeground(d, gc, colours[colour]);
  XDrawString(d, w, gc, x, y, msg.c_str(), msg.length());
  XSetForeground(d, gc, colours[Black]);
}

void Xwindow::drawPiece(char piece, int x, int y, int width, int height) {
  std::string pieceStr(1, piece);
  drawString(x + width / 2, y + height / 2, pieceStr);
}

GC Xwindow::create_gc(Display* display, Window win, int reverse_video) {
  GC gc;
  unsigned long valuemask = 0;
  XGCValues values;
  unsigned int line_width = 2;
  int line_style = LineSolid;
  int cap_style = CapButt;
  int join_style = JoinBevel;

  gc = XCreateGC(display, win, valuemask, &values);

  // Set the GC's graphics characteristics
  if (reverse_video) {
    XSetForeground(display, gc, WhitePixel(display, DefaultScreen(display)));
    XSetBackground(display, gc, BlackPixel(display, DefaultScreen(display)));
  } 
  else {
    XSetForeground(display, gc, BlackPixel(display, DefaultScreen(display)));
    XSetBackground(display, gc, WhitePixel(display, DefaultScreen(display)));
  }

  XSetLineAttributes(display, gc, line_width, line_style, cap_style, join_style);
  XSetFillStyle(display, gc, FillSolid);

  return gc;
}