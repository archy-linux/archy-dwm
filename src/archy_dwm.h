//
// Created by anas on 10/31/22.
//

#ifndef ARCHY_DWM_H
#define ARCHY_DWM_H

/* enums */
enum {
    CurNormal, CurResize, CurMove, CurLast
}; /* cursor */
enum {
    SchemeNorm, SchemeSel, SchemeUrg
}; /* color schemes */
enum {
    NetSupported, NetWMName, NetWMState, NetWMCheck,
    NetSystemTray, NetSystemTrayOP, NetSystemTrayOrientation, NetSystemTrayOrientationHorz,
    NetWMFullscreen, NetActiveWindow, NetWMWindowType,
    NetWMWindowTypeDialog, NetClientList, NetLast
}; /* EWMH atoms */
enum {
    Manager, Xembed, XembedInfo, XLast
}; /* Xembed atoms */
enum {
    WMProtocols, WMDelete, WMState, WMTakeFocus, WMLast
}; /* default atoms */


typedef union {
    int i;
    unsigned int ui;
    float f;
    const void *v;
} Arg;

typedef struct Monitor Monitor;
typedef struct Client Client;
struct Client {
    char name[256];
    float mina, maxa;
    int x, y, w, h;
    int oldx, oldy, oldw, oldh;
    int basew, baseh, incw, inch, maxw, maxh, minw, minh, hintsvalid;
    int bw, oldbw;
    unsigned int tags;
    int isfixed, isfloating, isurgent, neverfocus, oldstate, isfullscreen, issticky;
    Client *next;
    Client *snext;
    Monitor *mon;
    Window win;
};


typedef struct {
    const char *symbol;

    void (*arrange)(Monitor *);
} Layout;

typedef struct Pertag Pertag;
struct Monitor {
    char ltsymbol[16];
    float mfact;
    int nmaster;
    int num;
    int by;               /* bar geometry */
    int mx, my, mw, mh;   /* screen size */
    int wx, wy, ww, wh;   /* window area  */
    unsigned int seltags;
    unsigned int sellt;
    unsigned int tagset[2];
    int showbar;
    int topbar;
    Client *clients;
    Client *sel;
    Client *stack;
    Monitor *next;
    Window barwin;
    const Layout *lt[2];
    Pertag *pertag;
};

typedef struct {
    const char *class;
    const char *instance;
    const char *title;
    unsigned int tags;
    int isfloating;
    int monitor;
} Rule;

typedef struct Systray Systray;
struct Systray {
    Window win;
    Client *icons;
};

/* function declarations */
static void applyrules(Client *c);

static int applysizehints(Client *c, int *x, int *y, int *w, int *h, int interact);

static void arrange(Monitor *m);

static void arrangemon(Monitor *m);

static void attach(Client *c);

static void attachstack(Client *c);

static void buttonpress(XEvent *e);

static void checkotherwm(void);

static void cleanup(void);

static void cleanupmon(Monitor *mon);

static void clientmessage(XEvent *e);

static void configure(Client *c);

static void configurenotify(XEvent *e);

static void configurerequest(XEvent *e);

static Monitor *createmon(void);

static void destroynotify(XEvent *e);

static void detach(Client *c);

static void detachstack(Client *c);

static Monitor *dirtomon(int dir);

static void drawbar(Monitor *m);

static void drawbars(void);

static void enternotify(XEvent *e);

static void expose(XEvent *e);

static void focus(Client *c);

static void focusin(XEvent *e);

static Atom getatomprop(Client *c, Atom prop);

static int getrootptr(int *x, int *y);

static long getstate(Window w);

static unsigned int getsystraywidth();

static int gettextprop(Window w, Atom atom, char *text, unsigned int size);

static void grabbuttons(Client *c, int focused);

static void grabkeys(void);

static void keypress(XEvent *e);

static void manage(Window w, XWindowAttributes *wa);

static void mappingnotify(XEvent *e);

static void maprequest(XEvent *e);

static void monocle(Monitor *m);

static void motionnotify(XEvent *e);

static Client *nexttiled(Client *c);

static void pop(Client *);

static void propertynotify(XEvent *e);

static Monitor *recttomon(int x, int y, int w, int h);

static void removesystrayicon(Client *i);

static void resize(Client *c, int x, int y, int w, int h, int interact);

static void resizebarwin(Monitor *m);

static void resizeclient(Client *c, int x, int y, int w, int h);

static void resizemouse(const Arg *arg);

static void resizerequest(XEvent *e);

static void restack(Monitor *m);

static void run(void);

static void scan(void);

static int sendevent(Window w, Atom proto, int m, long d0, long d1, long d2, long d3, long d4);

static void sendmon(Client *c, Monitor *m);

static void setclientstate(Client *c, long state);

static void setfocus(Client *c);

static void setfullscreen(Client *c, int fullscreen);

static void setup(void);

static void seturgent(Client *c, int urg);

static void showhide(Client *c);

static void sigchld(int unused);

static Monitor *systraytomon(Monitor *m);

static void tile(Monitor *);

static void toggletag(const Arg *arg);

static void toggleview(const Arg *arg);

static void unfocus(Client *c, int setfocus);

static void unmanage(Client *c, int destroyed);

static void unmapnotify(XEvent *e);

static void updatebarpos(Monitor *m);

static void updatebars(void);

static void updateclientlist(void);

static int updategeom(void);

static void updatenumlockmask(void);

static void updatesizehints(Client *c);

static void updatestatus(void);

static void updatesystray(void);

static void updatesystrayicongeom(Client *i, int w, int h);

static void updatesystrayiconstate(Client *i, XPropertyEvent *ev);

static void updatetitle(Client *c);

static void updatewindowtype(Client *c);

static void updatewmhints(Client *c);

static Client *wintoclient(Window w);

static Monitor *wintomon(Window w);

static Client *wintosystrayicon(Window w);

static int xerror(Display *dpy, XErrorEvent *ee);

static int xerrordummy(Display *dpy, XErrorEvent *ee);

static int xerrorstart(Display *dpy, XErrorEvent *ee);

static void autostart_exec(void);

#endif //ARCHY_DWM_H
