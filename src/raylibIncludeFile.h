//
// Created by eal on 03/02/25.
//

#ifndef RAYLIBINCLUDEFILE_H
#define RAYLIBINCLUDEFILE_H

#undef KEY_RESERVED		0
#undef KEY_ESC			1
#undef KEY_1			2
#undef KEY_2			3
#undef KEY_3			4
#undef KEY_4			5
#undef KEY_5			6
#undef KEY_6			7
#undef KEY_7			8
#undef KEY_8			9
#undef KEY_9			10
#undef KEY_0			11
#undef KEY_MINUS		12
#undef KEY_EQUAL		13
#undef KEY_BACKSPACE		14
#undef KEY_TAB			15
#undef KEY_Q			16
#undef KEY_W			17
#undef KEY_E			18
#undef KEY_R			19
#undef KEY_T			20
#undef KEY_Y			21
#undef KEY_U			22
#undef KEY_I			23
#undef KEY_O			24
#undef KEY_P			25
#undef KEY_LEFTBRACE		26
#undef KEY_RIGHTBRACE		27
#undef KEY_ENTER		28
#undef KEY_LEFTCTRL		29
#undef KEY_A			30
#undef KEY_S			31
#undef KEY_D			32
#undef KEY_F			33
#undef KEY_G			34
#undef KEY_H			35
#undef KEY_J			36
#undef KEY_K			37
#undef KEY_L			38
#undef KEY_SEMICOLON		39
#undef KEY_APOSTROPHE		40
#undef KEY_GRAVE		41
#undef KEY_LEFTSHIFT		42
#undef KEY_BACKSLASH		43
#undef KEY_Z			44
#undef KEY_X			45
#undef KEY_C			46
#undef KEY_V			47
#undef KEY_B			48
#undef KEY_N			49
#undef KEY_M			50
#undef KEY_COMMA		51
#undef KEY_DOT			52
#undef KEY_SLASH		53
#undef KEY_RIGHTSHIFT		54
#undef KEY_KPASTERISK		55
#undef KEY_LEFTALT		56
#undef KEY_SPACE		57
#undef KEY_CAPSLOCK		58
#undef KEY_F1			59
#undef KEY_F2			60
#undef KEY_F3			61
#undef KEY_F4			62
#undef KEY_F5			63
#undef KEY_F6			64
#undef KEY_F7			65
#undef KEY_F8			66
#undef KEY_F9			67
#undef KEY_F10			68
#undef KEY_NUMLOCK		69
#undef KEY_SCROLLLOCK		70
#undef KEY_KP7			71
#undef KEY_KP8			72
#undef KEY_KP9			73
#undef KEY_KPMINUS		74
#undef KEY_KP4			75
#undef KEY_KP5			76
#undef KEY_KP6			77
#undef KEY_KPPLUS		78
#undef KEY_KP1			79
#undef KEY_KP2			80
#undef KEY_KP3			81
#undef KEY_KP0			82
#undef KEY_KPDOT		83

#undef KEY_ZENKAKUHANKAKU	85
#undef KEY_102ND		86
#undef KEY_F11			87
#undef KEY_F12			88
#undef KEY_RO			89
#undef KEY_KATAKANA		90
#undef KEY_HIRAGANA		91
#undef KEY_HENKAN		92
#undef KEY_KATAKANAHIRAGANA	93
#undef KEY_MUHENKAN		94
#undef KEY_KPJPCOMMA		95
#undef KEY_KPENTER		96
#undef KEY_RIGHTCTRL		97
#undef KEY_KPSLASH		98
#undef KEY_SYSRQ		99
#undef KEY_RIGHTALT		100
#undef KEY_LINEFEED		101
#undef KEY_HOME		102
#undef KEY_UP			103
#undef KEY_PAGEUP		104
#undef KEY_LEFT		105
#undef KEY_RIGHT		106
#undef KEY_END			107
#undef KEY_DOWN		108
#undef KEY_PAGEDOWN		109
#undef KEY_INSERT		110
#undef KEY_DELETE		111
#undef KEY_MACRO		112
#undef KEY_MUTE		113
#undef KEY_VOLUMEDOWN		114
#undef KEY_VOLUMEUP		115
#undef KEY_POWER		116	/* SC System Power Down */
#undef KEY_KPEQUAL		117
#undef KEY_KPPLUSMINUS		118
#undef KEY_PAUSE		119
#undef KEY_SCALE		120	/* AL Compiz Scale (Expose) */

#undef KEY_KPCOMMA		121
#undef KEY_HANGEUL		122
#undef KEY_HANGUEL		KEY_HANGEUL
#undef KEY_HANJA		123
#undef KEY_YEN			124
#undef KEY_LEFTMETA		125
#undef KEY_RIGHTMETA		126
#undef KEY_COMPOSE		127

#undef KEY_STOP		128	/* AC Stop */
#undef KEY_AGAIN		129
#undef KEY_PROPS		130	/* AC Properties */
#undef KEY_UNDO		131	/* AC Undo */
#undef KEY_FRONT		132
#undef KEY_COPY		133	/* AC Copy */
#undef KEY_OPEN		134	/* AC Open */
#undef KEY_PASTE		135	/* AC Paste */
#undef KEY_FIND		136	/* AC Search */
#undef KEY_CUT			137	/* AC Cut */
#undef KEY_HELP		138	/* AL Integrated Help Center */
#undef KEY_MENU		139	/* Menu (show menu) */
#undef KEY_CALC		140	/* AL Calculator */
#undef KEY_SETUP		141
#undef KEY_SLEEP		142	/* SC System Sleep */
#undef KEY_WAKEUP		143	/* System Wake Up */
#undef KEY_FILE		144	/* AL Local Machine Browser */
#undef KEY_SENDFILE		145
#undef KEY_DELETEFILE		146
#undef KEY_XFER		147
#undef KEY_PROG1		148
#undef KEY_PROG2		149
#undef KEY_WWW			150	/* AL Internet Browser */
#undef KEY_MSDOS		151
#undef KEY_COFFEE		152	/* AL Terminal Lock/Screensaver */
#undef KEY_SCREENLOCK		KEY_COFFEE
#undef KEY_ROTATE_DISPLAY	153	/* Display orientation for e.g. tablets */
#undef KEY_DIRECTION		KEY_ROTATE_DISPLAY
#undef KEY_CYCLEWINDOWS	154
#undef KEY_MAIL		155
#undef KEY_BOOKMARKS		156	/* AC Bookmarks */
#undef KEY_COMPUTER		157
#undef KEY_BACK		158	/* AC Back */
#undef KEY_FORWARD		159	/* AC Forward */
#undef KEY_CLOSECD		160
#undef KEY_EJECTCD		161
#undef KEY_EJECTCLOSECD	162
#undef KEY_NEXTSONG		163
#undef KEY_PLAYPAUSE		164
#undef KEY_PREVIOUSSONG	165
#undef KEY_STOPCD		166
#undef KEY_RECORD		167
#undef KEY_REWIND		168
#undef KEY_PHONE		169	/* Media Select Telephone */
#undef KEY_ISO			170
#undef KEY_CONFIG		171	/* AL Consumer Control Configuration */
#undef KEY_HOMEPAGE		172	/* AC Home */
#undef KEY_REFRESH		173	/* AC Refresh */
#undef KEY_EXIT		174	/* AC Exit */
#undef KEY_MOVE		175
#undef KEY_EDIT		176
#undef KEY_SCROLLUP		177
#undef KEY_SCROLLDOWN		178
#undef KEY_KPLEFTPAREN		179
#undef KEY_KPRIGHTPAREN	180
#undef KEY_NEW			181	/* AC New */
#undef KEY_REDO		182	/* AC Redo/Repeat */

#undef KEY_F13			183
#undef KEY_F14			184
#undef KEY_F15			185
#undef KEY_F16			186
#undef KEY_F17			187
#undef KEY_F18			188
#undef KEY_F19			189
#undef KEY_F20			190
#undef KEY_F21			191
#undef KEY_F22			192
#undef KEY_F23			193
#undef KEY_F24			194

#undef KEY_PLAYCD		200
#undef KEY_PAUSECD		201
#undef KEY_PROG3		202
#undef KEY_PROG4		203
#undef KEY_ALL_APPLICATIONS	204	/* AC Desktop Show All Applications */
#undef KEY_DASHBOARD		KEY_ALL_APPLICATIONS
#undef KEY_SUSPEND		205
#undef KEY_CLOSE		206	/* AC Close */
#undef KEY_PLAY		207
#undef KEY_FASTFORWARD		208
#undef KEY_BASSBOOST		209
#undef KEY_PRINT		210	/* AC Print */
#undef KEY_HP			211
#undef KEY_CAMERA		212
#undef KEY_SOUND		213
#undef KEY_QUESTION		214
#undef KEY_EMAIL		215
#undef KEY_CHAT		216
#undef KEY_SEARCH		217
#undef KEY_CONNECT		218
#undef KEY_FINANCE		219	/* AL Checkbook/Finance */
#undef KEY_SPORT		220
#undef KEY_SHOP		221
#undef KEY_ALTERASE		222
#undef KEY_CANCEL		223	/* AC Cancel */
#undef KEY_BRIGHTNESSDOWN	224
#undef KEY_BRIGHTNESSUP	225
#undef KEY_MEDIA		226

#undef KEY_SWITCHVIDEOMODE	227	/* Cycle between available video
					   outputs (Monitor/LCD/TV-out/etc) */
#undef KEY_KBDILLUMTOGGLE	228
#undef KEY_KBDILLUMDOWN	229
#undef KEY_KBDILLUMUP		230

#undef KEY_SEND		231	/* AC Send */
#undef KEY_REPLY		232	/* AC Reply */
#undef KEY_FORWARDMAIL		233	/* AC Forward Msg */
#undef KEY_SAVE		234	/* AC Save */
#undef KEY_DOCUMENTS		235

#undef KEY_BATTERY		236

#undef KEY_BLUETOOTH		237
#undef KEY_WLAN		238
#undef KEY_UWB			239

#undef KEY_UNKNOWN		240

#undef KEY_VIDEO_NEXT		241	/* drive next video source */
#undef KEY_VIDEO_PREV		242	/* drive previous video source */
#undef KEY_BRIGHTNESS_CYCLE	243	/* brightness up, after max is min */
#undef KEY_BRIGHTNESS_AUTO	244	/* Set Auto Brightness: manual
					  brightness control is off,
					  rely on ambient */
#undef KEY_BRIGHTNESS_ZERO	KEY_BRIGHTNESS_AUTO
#undef KEY_DISPLAY_OFF		245	/* display device to off state */

#undef KEY_WWAN		246	/* Wireless WAN (LTE, UMTS, GSM, etc.) */
#undef KEY_WIMAX		KEY_WWAN
#undef KEY_RFKILL		247	/* Key that controls all radios */

#undef KEY_MICMUTE		248	/* Mute / unmute the microphone */

#include "raylib.h"

#endif //RAYLIBINCLUDEFILE_H
