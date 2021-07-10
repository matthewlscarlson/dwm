// dwm

static unsigned int borderpx = 1;
static unsigned int snap     = 32;

// swallow
static int swallowfloating = 0;

// gaps
static unsigned int gappih = 20;
static unsigned int gappiv = 10;
static unsigned int gappoh = 10;
static unsigned int gappov = 30;
static int smartgaps       = 0;

// bar
static int showbar = 1;
static int topbar  = 1;

// barpadding
static int vertpad = 10;
static int sidepad = 10;

// fonts
static char font[]         = "monospace:size=10";
static const char *fonts[] = { font };

// colors
static char normbgcolor[]     = "#222222";
static char normbordercolor[] = "#444444";
static char normfgcolor[]     = "#bbbbbb";
static char selfgcolor[]      = "#eeeeee";
static char selbordercolor[]  = "#005577";
static char selbgcolor[]      = "#005577";

// alpha
static const unsigned int baralpha    = 0xd0;
static const unsigned int borderalpha = OPAQUE;

// color array
static char *colors[][3] = {
       //               fg           bg           border
       [SchemeNorm] = { normfgcolor, normbgcolor, normbordercolor },
       [SchemeSel]  = { selfgcolor,  selbgcolor,  selbordercolor  },
};

// alpha array
static const unsigned int alphas[][3] = {
    //               fg      bg        border
	[SchemeNorm] = { OPAQUE, baralpha, borderalpha },
	[SchemeSel]  = { OPAQUE, baralpha, borderalpha },
};

// tags
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

// underline
static unsigned int ulinepad	 = 5;
static unsigned int ulinestroke	 = 2;
static unsigned int ulinevoffset = 0;
static int ulineall 		     = 0;

// rules
static const Rule rules[] = {
   // class instance title           tags mask isfloating isterminal noswallow monitor
    { NULL, NULL,    "Event Tester", 0,        0,         0,         1,        -1 },
};

// sizes
static float mfact     = 0.55;
static int nmaster     = 1;
static int resizehints = 1;

// vanitygaps layouts
#define FORCE_VSPLIT 1
#include "vanitygaps.c"
static const Layout layouts[] = {
   // symbol  arrange function
	{ "[]=",  tile                   },
	{ "[M]",  monocle                },
	{ "[@]",  spiral                 },
	{ "[\\]", dwindle                },
	{ "H[]",  deck                   },
	{ "TTT",  bstack                 },
	{ "===",  bstackhoriz            },
	{ "HHH",  grid                   },
	{ "###",  nrowgrid               },
	{ "---",  horizgrid              },
	{ ":::",  gaplessgrid            },
	{ "|M|",  centeredmaster         },
	{ ">M>",  centeredfloatingmaster },
	{ "><>",  NULL                   },
	{ NULL,   NULL                   },
};

// modifier key
#define MODKEY Mod1Mask

// tag keys
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY, view,       {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY, toggleview, {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY, tag,        {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY, toggletag,  {.ui = 1 << TAG} },

// shcmd
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

// status bar
#define STATUSBAR "dwmblocks"

// termcmd
#define TERM "st"
static const char *termcmd[]  = { TERM, NULL };

// xresources
ResourcePref resources[] = {
		{ "font",            STRING,  &font },
		{ "normbgcolor",     STRING,  &normbgcolor },
		{ "normbordercolor", STRING,  &normbordercolor },
		{ "normfgcolor",     STRING,  &normfgcolor },
		{ "selbgcolor",      STRING,  &selbgcolor },
		{ "selbordercolor",  STRING,  &selbordercolor },
		{ "selfgcolor",      STRING,  &selfgcolor },
		{ "borderpx",        INTEGER, &borderpx },
		{ "snap",          	 INTEGER, &snap },
		{ "showbar",         INTEGER, &showbar },
		{ "topbar",          INTEGER, &topbar },
		{ "nmaster",         INTEGER, &nmaster },
		{ "resizehints",     INTEGER, &resizehints },
		{ "mfact",      	 FLOAT,   &mfact },
        { "swallowfloating", INTEGER, &swallowfloating },
        { "gappih",          INTEGER, &gappih },
        { "gappiv",          INTEGER, &gappiv },
        { "gappoh",          INTEGER, &gappoh },
        { "gappov",          INTEGER, &gappov },
        { "smartgaps",       INTEGER, &smartgaps },
        { "vertpad",         INTEGER, &vertpad },
        { "sidepad",         INTEGER, &sidepad },
        { "ulinepad",        INTEGER, &ulinepad },
        { "ulinestroke",     INTEGER, &ulinestroke },
        { "ulinevoffset",    INTEGER, &ulinevoffset },
        { "ulineall",        INTEGER, &ulineall },
};

// keys
static Key keys[] = {
	/* modifier                  key        function        argument */
	{ MODKEY,                    XK_p,      spawn,          SHCMD("dmenu_run") },
	{ MODKEY|ShiftMask,          XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY|Mod4Mask,           XK_u,      incrgaps,       {.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask, XK_u,      incrgaps,       {.i = -1 } },
	{ MODKEY|Mod4Mask,           XK_i,      incrigaps,      {.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask, XK_i,      incrigaps,      {.i = -1 } },
	{ MODKEY|Mod4Mask,           XK_o,      incrogaps,      {.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask, XK_o,      incrogaps,      {.i = -1 } },
	{ MODKEY|Mod4Mask,           XK_6,      incrihgaps,     {.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask, XK_6,      incrihgaps,     {.i = -1 } },
	{ MODKEY|Mod4Mask,           XK_7,      incrivgaps,     {.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask, XK_7,      incrivgaps,     {.i = -1 } },
	{ MODKEY|Mod4Mask,           XK_8,      incrohgaps,     {.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask, XK_8,      incrohgaps,     {.i = -1 } },
	{ MODKEY|Mod4Mask,           XK_9,      incrovgaps,     {.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask, XK_9,      incrovgaps,     {.i = -1 } },
	{ MODKEY|Mod4Mask,           XK_0,      togglegaps,     {0} },
	{ MODKEY|Mod4Mask|ShiftMask, XK_0,      defaultgaps,    {0} },
	{ MODKEY,                    XK_b,      togglebar,      {0} },
	{ MODKEY,                    XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                    XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                    XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                    XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                    XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                    XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                    XK_Return, zoom,           {0} },
	{ MODKEY,                    XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,          XK_c,      killclient,     {0} },
	{ MODKEY,                    XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                    XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                    XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                    XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,          XK_space,  togglefloating, {0} },
	{ MODKEY|ShiftMask,          XK_f,      togglefullscr,  {0} },
	{ MODKEY,                    XK_s,      togglesticky,   {0} },
	{ MODKEY,                    XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,          XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                    XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                    XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,          XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,          XK_period, tagmon,         {.i = +1 } },
	  TAGKEYS(                   XK_1,                      0)
	  TAGKEYS(                   XK_2,                      1)
	  TAGKEYS(                   XK_3,                      2)
	  TAGKEYS(                   XK_4,                      3)
	  TAGKEYS(                   XK_5,                      4)
	  TAGKEYS(                   XK_6,                      5)
	  TAGKEYS(                   XK_7,                      6)
	  TAGKEYS(                   XK_8,                      7)
	  TAGKEYS(                   XK_9,                      8)
	{ MODKEY|ShiftMask,          XK_q,      quit,           {0} },
};

// buttons
static Button buttons[] = {
	/* click         event mask button   function        argument */
	{ ClkLtSymbol,   0,         Button1, setlayout,      {0} },
	{ ClkLtSymbol,   0,         Button3, setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,   0,         Button2, zoom,           {0} },
	{ ClkStatusText, 0,         Button1, sigstatusbar,   {.i = 1} },
	{ ClkStatusText, 0,         Button2, sigstatusbar,   {.i = 2} },
	{ ClkStatusText, 0,         Button3, sigstatusbar,   {.i = 3} },
	{ ClkClientWin,  MODKEY,    Button1, movemouse,      {0} },
	{ ClkClientWin,  MODKEY,    Button2, togglefloating, {0} },
	{ ClkClientWin,  MODKEY,    Button3, resizemouse,    {0} },
	{ ClkTagBar,     0,         Button1, view,           {0} },
	{ ClkTagBar,     0,         Button3, toggleview,     {0} },
	{ ClkTagBar,     MODKEY,    Button1, tag,            {0} },
	{ ClkTagBar,     MODKEY,    Button3, toggletag,      {0} },
};
