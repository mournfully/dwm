/* See LICENSE file for copyright and license details. */

#define SESSION_FILE "/tmp/dwm-session"

/* appearance */
static const unsigned int borderpx  = 3;        /* border pixel of windows */
static const unsigned int gappx     = 4;        /* gaps between windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const int textvertpad 		= 4;        /* vertical padding between bar text and bar box */
static const int vertpad            = 4;        /* vertical padding between bar and window*/
static const int sidepad            = 4;        /* horizontal padding between bar and window */
static const char *fonts[]          = { "JetBrainsMono Nerd Font:style=regular:size=11", "Material Design Icons Desktop:style=regular:size=14" };

#include "colour-scheme.h"
static const char *colors[][3] = {	
/*  name            	fg         		bg         		border   	*/
	[SchemeNorm] 	= { col_white, 		col_crust,		col_crust	}, /* for windows that you haven't selected */
	[SchemeSel]  	= { col_crust, 		col_white,		col_white  	}, /* when you select a window or tag */
	[SchemeUrg]		= { col_crust,		col_white, 		col_red		}, /* for when a window wants your attention */
};

/* tagging */
static const char *tags[] = { "󰈹", "󰆍", "󰨞", "󱔗", "󰝰", "󰊌" }; 
static const char *tagnorm[][2] = {
    /* fg			 bg		   */
	{  col_red, 	 col_crust },
	{  col_peach, 	 col_crust },
	{  col_yellow, 	 col_crust },
	{  col_green, 	 col_crust },
	{  col_teal, 	 col_crust },
	{  col_lavender, col_crust },
};

static const char *tagsel[][2] = {
	/* fg			 bg		      */
	{  col_red, 	 col_surface0 },
	{  col_peach, 	 col_surface0 },
	{  col_yellow, 	 col_surface0 },
	{  col_green, 	 col_surface0 },
	{  col_teal, 	 col_surface0 },
	{  col_lavender, col_surface0 },
};

/* rules */
static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      	instance    title       tags mask     isfloating   monitor */
	{ "Code",	    NULL,       NULL,       1 << 2,       0,           -1 },
	{ "obsidian",  	NULL,       NULL,       1 << 3,       0,           -1 },
};

/* layout(s) */
static const float mfact     = 0.5;  /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle }, /* fullscreen focused window */
};

/* key definitions - define super key as modifier key */
#define MODKEY Mod4Mask		
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },
/* commands - regular program bindings now handled in sxhkdrc */

/* key definitions array */
static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	/* kill focused window */
	{ MODKEY|ShiftMask,		        XK_q,      killclient,     {0} },
	/* quit dwm cleanly */
	{ MODKEY|ShiftMask,             XK_c,      quit,           {0} },
	
	/* focus on next/previous window in current tag */
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
    /* rotate window position in current tag */
    { MODKEY|ShiftMask,             XK_j,      rotatestack,    {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_k,      rotatestack,    {.i = -1 } },
    /* toggle window between master and stack area */
	{ MODKEY,                       XK_c,      zoom,           {0} },
	/* increase/decrease # of windows in master area */
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	/* increase/decrease master area size */
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	/* increase/decrease/reset cfact */
	{ MODKEY|ShiftMask,             XK_h,      setcfact,       {.f = +0.25} },
	{ MODKEY|ShiftMask,             XK_l,      setcfact,       {.f = -0.25} },
	{ MODKEY|ShiftMask,             XK_o,      setcfact,       {.f =  0.00} },
	/* increase/decrease/reset gap size */
	{ MODKEY,                    	XK_equal,  setgaps,        {.i = -1 } },
	{ MODKEY,                    	XK_minus,  setgaps,        {.i = +1 } },
	{ MODKEY|ShiftMask,          	XK_equal,  setgaps,        {.i = 0  } },

	/* view all windows with any tag */
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	/* apply all tags to focused window */
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	/* view all windows with nth tag */
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                     	XK_7,                      6)
	/* switch between workspaces */
	{ MODKEY,                    	XK_Tab,    view,           {0} }, 
	
	/* set layouts (tiling/floating/monocle) */
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	/* toggle floating/tiling mode for window */
	{ MODKEY|ShiftMask,             XK_f,      togglefloating, {0} },
	/* switch focus between monitors */
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	/* move windows between monitors */
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
};

/* mouse button definitions */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	/* left click on tag to switch between workspaces */
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	/* mod + (hold) LMB to set floating and move window */
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	/* mod + (hold) RMB to set floating and resize window */
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	/* mod + MMB to reset floating windows back to tiled */
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
};
